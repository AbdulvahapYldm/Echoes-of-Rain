// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Inventory/InventoryBase/Inv_InventoryBase.h"
#include "Inv_SpatialInventory.generated.h"

/**
 * Spatial inventory widget that supports different item categories
 * such as Equippable, Consumable, and Craftable items.
 */

class UInv_InventroyGrid;
class UWidgetSwitcher;
class UButton;

UCLASS()
class INVENTORY_API UInv_SpatialInventory : public UInv_InventoryBase
{
	GENERATED_BODY()
	

public:

	virtual void NativeOnInitialized() override; // Called when the widget is first initialized

private:

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher>Switcher; // Switcher to toggle between different inventory grid widgets

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventroyGrid>Grid_Equippable; // Inventory grid for equippable items


	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventroyGrid>Grid_Consumable;	// Inventory grid for consumable items


	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventroyGrid>Grid_Craftable; 	// Inventory grid for craftable items



	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Equippable; // Button to activate the equippable grid

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Consumable; // Button to activate the consumable grid

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Craftable; // Button to activate the craftable grid

	UFUNCTION()
	void ShowEquippable();	// Called when the Equippable button is clicked

	UFUNCTION()
	void ShowConsumable();// Called when the Consumable button is clicked

	UFUNCTION()
	void ShowCraftable();// Called when the Craftable button is clicked


	// Sets the specified grid to active and disables the corresponding button
	void SetActiveGrid(UInv_InventroyGrid* Grid, UButton* Button);

	// Disables the given button to indicate it is already active
	void DisableButton(UButton* Button);
};
