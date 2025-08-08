// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_Inventory.generated.h"

class UInv_InventorySlot;
class UWidgetSwitcher;
class UButton;

/**
 * 
 */
UCLASS()
class INVENTORYSYSTEM_API UInv_Inventory : public UUserWidget
{
	GENERATED_BODY()
	

public:

	virtual void NativeOnInitialized() override;

private:



	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher>InventorySwitcher;



	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_All;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Weapons;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Armour;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Food;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Books;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Materials;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Quest;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Other;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UInv_InventorySlot>InventorySwitcher_Pets;




	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_All;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Weapons;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Armour;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Food;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Materials;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Quest;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Other;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Pets;


	UFUNCTION()
	void Show_All();

	UFUNCTION()
	void Show_Weapons();

	UFUNCTION()
	void Show_Armour();

	UFUNCTION()
	void Show_Food();

	UFUNCTION()
	void Show_Materials();

	UFUNCTION()
	void Show_Quest();

	UFUNCTION()
	void Show_Other();

	UFUNCTION()
	void Show_Pets();


	void SetActiveSwitcher(UInv_InventorySlot* Switcher, UButton* Button);


	// Disables the given button to indicate it is already active
	void DisableInventoryButton(UButton* Button);


};
