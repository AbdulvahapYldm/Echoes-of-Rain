// Fill out your copyright notice in the Description page of Project Settings.


#include "InventoryFunctionLibrary/UInv_InventoryStatics.h"
#include "InventorySystems/Components/Inv_InventoryComponent.h"
#include "InventorySystems/Components/Inv_ItemComponent.h"
#include "InventorySystems/Types/Inv_Types.h"

UInv_InventoryComponent* UUInv_InventoryStatics::GetInventoryComponent(APlayerController* PlayerController)
{
	if (!IsValid(PlayerController))return nullptr;

	UInv_InventoryComponent* InventoryComponent = PlayerController->FindComponentByClass<UInv_InventoryComponent>();
	return InventoryComponent;
}

EInv_InventoryCategory UUInv_InventoryStatics::GetItemCategoryFromItemComp(UInv_ItemComponent* ItemComp)
{
	if (!IsValid(ItemComp)) return EInv_InventoryCategory::None;
	return ItemComp->GetItemDataManifest().GetItemCategory();

}
