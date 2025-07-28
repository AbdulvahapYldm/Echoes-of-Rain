// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Inv_PlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "Widgets/HUD/Inv_HUDWidget.h"


void AInv_PlayerController::BeginPlay()
{
	Super::BeginPlay();
	
	// Get the Enhanced Input subsystem for the local player
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	
	if (IsValid(Subsystem)) // Add the default input mapping context
	{
		Subsystem->AddMappingContext(Default_Inventory_IMC, 0);
	
	}


	CreateHUDWidget(); // Create and display the HUD widget

}

void AInv_PlayerController::SetupInputComponent()// The input component is configured here
{
	Super::SetupInputComponent();

	// Convert the input component to Enhanced InputComponent type
	if (UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent))
	{
		// Bind input action to the corresponding function
		EnhancedInputComponent->BindAction(PrimaryInteractAction, ETriggerEvent::Started, this, &AInv_PlayerController::PrimaryInteract);
		

	}
}

// Called when "E" key (or assigned action) is pressed
void AInv_PlayerController::PrimaryInteract()
{
	UE_LOG(LogTemp, Warning, TEXT("E Key Pressed! "));
}



// Creates and adds the HUD widget to the viewport
void AInv_PlayerController::CreateHUDWidget() 
{
	if (!IsLocalController()) return;

	HUDWidget = CreateWidget< UInv_HUDWidget>(this,HUDWidgetClass);
	if (IsValid(HUDWidget))
	{
		HUDWidget->AddToViewport();
	}


}
