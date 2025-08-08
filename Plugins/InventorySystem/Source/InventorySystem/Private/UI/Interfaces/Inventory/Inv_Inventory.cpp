// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Interfaces/Inventory/Inv_Inventory.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "UI/Interfaces/Inventory/Inv_InventorySlot.h"

void UInv_Inventory::NativeOnInitialized()
{

	Super::NativeOnInitialized();

	Button_All->OnClicked.AddDynamic(this, &UInv_Inventory::Show_All);
	Button_Weapons->OnClicked.AddDynamic(this, &UInv_Inventory::Show_Weapons);
	Button_Armour->OnClicked.AddDynamic(this, &UInv_Inventory::Show_Armour);
	Button_Food->OnClicked.AddDynamic(this, &UInv_Inventory::Show_Food);
	Button_Materials->OnClicked.AddDynamic(this, &UInv_Inventory::Show_Materials);
	Button_Quest->OnClicked.AddDynamic(this, &UInv_Inventory::Show_Quest);
	Button_Other->OnClicked.AddDynamic(this, &UInv_Inventory::Show_Other);
	Button_Pets->OnClicked.AddDynamic(this, &UInv_Inventory::Show_Pets);

	Show_All();

}







void UInv_Inventory::SetActiveSwitcher(UInv_InventorySlot* Switcher, UButton* Button)
{
	InventorySwitcher->SetActiveWidget(Switcher);

	DisableInventoryButton(Button);// Disable the currently active button to indicate selection
}

void UInv_Inventory::DisableInventoryButton(UButton* Button)
{
	Button_All->SetIsEnabled(true);
	Button_Weapons->SetIsEnabled(true);
	Button_Armour->SetIsEnabled(true);
	Button_Food->SetIsEnabled(true);
	Button_Materials->SetIsEnabled(true);
	Button_Quest->SetIsEnabled(true);
	Button_Other->SetIsEnabled(true);
	Button_Pets->SetIsEnabled(true);

	Button->SetIsEnabled(false);

}

void UInv_Inventory::Show_All()
{
	SetActiveSwitcher(InventorySwitcher_All, Button_All);
	
}

void UInv_Inventory::Show_Weapons()
{
	SetActiveSwitcher(InventorySwitcher_Weapons,Button_Weapons);
}

void UInv_Inventory::Show_Armour()
{
	SetActiveSwitcher(InventorySwitcher_Armour,Button_Armour);
}

void UInv_Inventory::Show_Food()
{
	SetActiveSwitcher(InventorySwitcher_Food,Button_Food);
}

void UInv_Inventory::Show_Materials()
{
	SetActiveSwitcher(InventorySwitcher_Materials,Button_Materials);
}

void UInv_Inventory::Show_Quest()
{
	SetActiveSwitcher(InventorySwitcher_Quest,Button_Quest);

}

void UInv_Inventory::Show_Other()
{
	SetActiveSwitcher(InventorySwitcher_Other,Button_Other);
}

void UInv_Inventory::Show_Pets()
{
	SetActiveSwitcher(InventorySwitcher_Pets,Button_Pets);
}
