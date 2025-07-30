// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Inv_SpatialInventory.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Widgets/Inventory/Spatial/Inv_InventroyGrid.h"

void UInv_SpatialInventory::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// Bind each button's OnClicked event to corresponding handler functions
	Button_Equippable->OnClicked.AddDynamic(this, &ThisClass::ShowEquippable);
	Button_Consumable->OnClicked.AddDynamic(this, &ThisClass::ShowConsumable);
	Button_Craftable->OnClicked.AddDynamic(this, &ThisClass::ShowCraftable);

	// By default, show the equippable items grid on initialization
	ShowEquippable();
}


// Set the specified grid as active and disable its associated button
void UInv_SpatialInventory::SetActiveGrid(UInv_InventroyGrid* Grid, UButton* Button)
{
	DisableButton(Button);        // Disable the currently active button to indicate selection
	Switcher->SetActiveWidget(Grid);  // Switch to the selected inventory grid widget
}

// Enables all buttons and disables the one passed in (active tab)
void UInv_SpatialInventory::DisableButton(UButton* Button)
{
	Button_Equippable->SetIsEnabled(true);
	Button_Consumable->SetIsEnabled(true);
	Button_Craftable->SetIsEnabled(true);

	// Disable the button corresponding to the active grid (indicate selection)
	Button->SetIsEnabled(false);
	
}

// Show equippable items grid and update button state
void UInv_SpatialInventory::ShowEquippable()
{
	SetActiveGrid(Grid_Equippable, Button_Equippable);
}

// Show consumable items grid and update button state
void UInv_SpatialInventory::ShowConsumable()
{
	SetActiveGrid(Grid_Consumable,Button_Consumable);
}

// Show craftable items grid and update button state
void UInv_SpatialInventory::ShowCraftable()
{
	SetActiveGrid(Grid_Craftable,Button_Craftable);
}

