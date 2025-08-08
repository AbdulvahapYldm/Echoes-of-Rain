// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Interfaces/Interface/Inv_PlayerInterface.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"






void UInv_PlayerInterface::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Button_Player->OnClicked.AddDynamic(this, &UInv_PlayerInterface::Show_Player);
	Button_Pets->OnClicked.AddDynamic(this, &UInv_PlayerInterface::Show_Animals);

	Button_Inventory->OnClicked.AddDynamic(this, &UInv_PlayerInterface::Show_Inventory);
	Button_Journal->OnClicked.AddDynamic(this, &UInv_PlayerInterface::Show_Journal);
	Button_Map->OnClicked.AddDynamic(this, &UInv_PlayerInterface::Show_Map);
	Button_Codex->OnClicked.AddDynamic(this, &UInv_PlayerInterface::Show_Codex);
	Button_Crafting->OnClicked.AddDynamic(this, &UInv_PlayerInterface::Show_Crafting);

	Show_Inventory();
}





void UInv_PlayerInterface::Show_Player()
{
	SetActiveIndex(0, Button_Player);
}

void UInv_PlayerInterface::Show_Animals()
{
	SetActiveIndex(1, Button_Pets);
}

void UInv_PlayerInterface::Show_Inventory()
{
	SetActiveIndex(2, Button_Inventory);
}

void UInv_PlayerInterface::Show_Journal()
{
	SetActiveIndex(3, Button_Journal);
}

void UInv_PlayerInterface::Show_Map()
{
	SetActiveIndex(4, Button_Map);
}

void UInv_PlayerInterface::Show_Codex()
{
	SetActiveIndex(5, Button_Codex);
}

void UInv_PlayerInterface::Show_Crafting()
{
	SetActiveIndex(6, Button_Crafting);
}










void UInv_PlayerInterface::SetActiveIndex(int32 Switcher, UButton* Button)
{
	InterfaceSwitcher->SetActiveWidgetIndex(Switcher);

	DisableButton(Button);// Disable the currently active button to indicate selection

}


void UInv_PlayerInterface::DisableButton(UButton* Button)
{
	Button_Player->SetIsEnabled(true);
	Button_Pets->SetIsEnabled(true);
	Button_Inventory->SetIsEnabled(true);
	Button_Journal->SetIsEnabled(true);
	Button_Map->SetIsEnabled(true);
	Button_Codex->SetIsEnabled(true);
	Button_Crafting->SetIsEnabled(true);


	Button->SetIsEnabled(false);
}
