// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystems/Components/Inv_InventoryComponent.h"
#include "UI/Interfaces/Interface/Inv_InterfaceBase.h"
#include "InventorySystems/ItemData/Item/Inv_ItemData.h"


UInv_InventoryComponent::UInv_InventoryComponent()
{
	
	PrimaryComponentTick.bCanEverTick = false;

	
}



void UInv_InventoryComponent::BeginPlay()
{
	Super::BeginPlay();

	ConstructInterfaceMenu();

	
}



void UInv_InventoryComponent::AddItem(UInv_ItemData* ItemToAdd)
{
	// Öğeyi envanter dizisine ekle
	Inventory.Add(ItemToAdd);

	// Log'a bir mesaj yazdırarak öğenin başarıyla eklendiğini doğrula
	//UE_LOG(LogTemp, Warning, TEXT("Envantere yeni bir öğe eklendi: %s"), *ItemToAdd.ItemName);

}












void UInv_InventoryComponent::ConstructInterfaceMenu()
{
	OwningController=Cast<APlayerController>(GetOwner());

	checkf(OwningController.IsValid(), TEXT("Inventory component should have player controller as owner."));
	if (!OwningController->IsLocalController()) return;

	InterfaceMenu = CreateWidget<UInv_InterfaceBase>(OwningController.Get(), InterfaceMenuClass);
	InterfaceMenu->AddToViewport();

	CloseInterfaceMenu();

}

void UInv_InventoryComponent::ToggleInterfaceMenu()
{
	if (bInventoryMenuOpen)
	{
		CloseInterfaceMenu();
	}
	else
	{
		OpenInterfaceMenu();
	}
}

void UInv_InventoryComponent::OpenInterfaceMenu()
{
	if (!IsValid(InterfaceMenu))return;

	InterfaceMenu->SetVisibility(ESlateVisibility::Visible);
	bInventoryMenuOpen = true;

	if (!OwningController.IsValid())return;

	FInputModeGameAndUI InputMode;
	OwningController->SetInputMode(InputMode);
	OwningController->SetShowMouseCursor(true);

}

void UInv_InventoryComponent::CloseInterfaceMenu()
{

	if (!IsValid(InterfaceMenu))return;

	InterfaceMenu->SetVisibility(ESlateVisibility::Collapsed);
	bInventoryMenuOpen = false;

	if (!OwningController.IsValid())return;

	FInputModeGameOnly InputMode;
	OwningController->SetInputMode(InputMode);
	OwningController->SetShowMouseCursor(false);
}





