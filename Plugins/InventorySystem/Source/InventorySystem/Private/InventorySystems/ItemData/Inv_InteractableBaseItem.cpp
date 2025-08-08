// Fill out your copyright notice in the Description page of Project Settings.

#include "InventorySystems/ItemData/Inv_InteractableBaseItem.h"
#include "Components/StaticMeshComponent.h"
#include "Components/WidgetComponent.h"
#include "InventorySystems/Components/Inv_ItemComponent.h"

#include "UI/HUD/Inv_PickupWidget.h"
#include "GameSystems/Inv_PlayerController.h"
#include "InventorySystems/Components/Inv_InventoryComponent.h"
#include "Kismet/GameplayStatics.h"
#include "InventoryFunctionLibrary/UInv_InventoryStatics.h"

AInv_InteractableBaseItem::AInv_InteractableBaseItem()
{
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	RootComponent = RootScene;


	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMeshComponent"));
	StaticMesh->SetupAttachment(RootScene);


	WidgetComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("WidgetComponent"));
	WidgetComponent->SetupAttachment(StaticMesh);


	ItemComponent = CreateDefaultSubobject<UInv_ItemComponent>(TEXT("ItemComponent"));




	
}

void AInv_InteractableBaseItem::BeginPlay()
{
	Super::BeginPlay();

	// Cache the widget for interaction (avoid repeated casting later)
	if (UUserWidget* UserWidget = WidgetComponent->GetWidget())
	{
		if (UInv_PickupWidget* CastedWidget = Cast<UInv_PickupWidget>(UserWidget))
		{
			PickupWidget = CastedWidget;
		}
	}
}

void AInv_InteractableBaseItem::InteractItem_Implementation()
{
	if (StaticMesh && HighlightMaterial)
	{
		StaticMesh->SetOverlayMaterial(HighlightMaterial);
	}

	// Ensure widget is valid and assigned
	if (!IsValid(PickupWidget))
	{
		PickupWidget = Cast<UInv_PickupWidget>(WidgetComponent->GetWidget());
	}

	if (IsValid(PickupWidget) && ItemComponent)
	{
		PickupWidget->ShowPickupMessage(FString("Pickup ") + ItemComponent->GetPickupMessage());
	}
	
}

void AInv_InteractableBaseItem::UnInteractItem_Implementation()
{
	if (StaticMesh)
	{
		StaticMesh->SetOverlayMaterial(nullptr);
	}

	if (!IsValid(PickupWidget))
	{
		PickupWidget = Cast<UInv_PickupWidget>(WidgetComponent->GetWidget());
	}

	if (IsValid(PickupWidget))
	{
		PickupWidget->HidePickupMessage();
	}
	

}

void AInv_InteractableBaseItem::PrimaryInteract_Implementation(APlayerController* Inv_PlayerController)
{

	// Kontrolcüden envanter bileşenine eriş
	UInv_InventoryComponent* InventoryComponent = UUInv_InventoryStatics::GetInventoryComponent(Inv_PlayerController); // Yeni getter fonksiyonunu kullanıyoruz

	if (!InventoryComponent)
	{
		UE_LOG(LogTemp, Error, TEXT("Envanter Bileşeni geçersiz! Öğeyi ekleyemedi."));
		return;
	}

	if (ItemComponent)
	{
		// Envanter bileşenindeki AddItem fonksiyonunu çağır
		InventoryComponent->AddItem(ItemComponent->GetItemData());

		
	
		// Öğeyi envantere ekledikten sonra dünyadan yok et
		Destroy();
		
	}

}



