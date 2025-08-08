// Fill out your copyright notice in the Description page of Project Settings.


#include "GameSystems/Inv_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"

#include "Kismet/GameplayStatics.h"

#include "InventorySystems/Components/Inv_InventoryComponent.h"

#include "InventorySystems/Interfaces/Inv_InteractableItemInterface.h"

#include "UI/HUD/Inv_HUDWidget.h"



AInv_PlayerController::AInv_PlayerController()
{
	PrimaryActorTick.bCanEverTick = true;

	TraceLength = 500.0; // Default distance for item trace (in cm)

	ItemTraceChannel = ECollisionChannel::ECC_GameTraceChannel1;

}


void AInv_PlayerController::BeginPlay()
{
	Super::BeginPlay();

	// Get the Enhanced Input subsystem for the local player
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	if (IsValid(Subsystem)) // Add the default input mapping context
	{
		Subsystem->AddMappingContext(Default_InventoryIMC, 0);

	}

	InventoryComponent = FindComponentByClass<UInv_InventoryComponent>();
	CreateHUDWidget(); // Create and display the HUD widget
	

}


void AInv_PlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// Perform a trace every frame to check for interactable items
	TraceForItem();


}


void AInv_PlayerController::SetupInputComponent()// The input component is configured here
{
	Super::SetupInputComponent();

	// Convert the input component to Enhanced InputComponent type
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Bind input action to the corresponding function
		EnhancedInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Started, this, &AInv_PlayerController::PrimaryInteract);
		EnhancedInputComponent->BindAction(ToggleInventoryAction, ETriggerEvent::Started, this, &AInv_PlayerController::ToggleInventory);

	}
}

// Called when "E" key (or assigned action) is pressed
void AInv_PlayerController::PrimaryInteract()
{
	
	if (InteractActor.IsValid())
	{
	
		//Todo add inventory
		if (InteractActor->Implements<UInv_InteractableItemInterface>())
		{
			IInv_InteractableItemInterface::Execute_PrimaryInteract(InteractActor.Get(),this);
			
		}
	}

	
}

void AInv_PlayerController::ToggleInventory()
{
	if (!InventoryComponent.IsValid()) return;

	InventoryComponent->ToggleInterfaceMenu();

}



// Creates and adds the HUD widget to the viewport
void AInv_PlayerController::CreateHUDWidget()
{
	if (!IsLocalController()) return;

	HUDWidget = CreateWidget< UInv_HUDWidget>(this, HUDWidgetClass);
	if (IsValid(HUDWidget))
	{
		HUDWidget->AddToViewport();
	}


}



// Performs a line trace from the center of the screen to detect interactable items
void AInv_PlayerController::TraceForItem()
{

	if (!IsValid(GEngine) || !IsValid(GEngine->GameViewport)) return;// Validate engine and viewport

	// Get screen center
	FVector2D ViewportSize;
	GEngine->GameViewport->GetViewportSize(ViewportSize);
	const FVector2D ViewportCenter = ViewportSize / 2.f;

	// Convert screen position to world space
	FVector TraceStart;
	FVector Forward;
	if (!UGameplayStatics::DeprojectScreenToWorld(this, ViewportCenter, TraceStart, Forward)) return;

	// Define end point of the trace
	const FVector TraceEnd = TraceStart + (Forward * TraceLength);

	FHitResult HitResult;

	// Perform the trace
	GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ItemTraceChannel);

	// Update references to currently and previously traced actors
	AActor* HitActor = HitResult.GetActor();
	if (HitActor == ThisActor) return; // Aktör degismediyse islem yapma

	LastActor = ThisActor;
	ThisActor = HitActor;


	if (ThisActor == LastActor) return;	// If the traced actor hasn't changed, do nothing

	if (ThisActor.IsValid())
	{
		AActor* Highlightable = ThisActor.Get();
		if (Highlightable->Implements<UInv_InteractableItemInterface>())
		{
			IInv_InteractableItemInterface::Execute_InteractItem(Highlightable);
			InteractActor = Highlightable;
		}
	}

	if (LastActor.IsValid())
	{

		AActor* Highlightable = LastActor.Get();
		if (Highlightable->Implements<UInv_InteractableItemInterface>())
		{
			IInv_InteractableItemInterface::Execute_UnInteractItem(Highlightable);

			InteractActor = nullptr;
		}
	}



}

