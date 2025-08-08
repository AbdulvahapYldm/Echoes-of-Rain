// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/Interfaces/Interface/Inv_InterfaceBase.h"
#include "Inv_PlayerInterface.generated.h"

/**
 * 
 */
class UWidgetSwitcher;
class UButton;

UCLASS()
class INVENTORYSYSTEM_API UInv_PlayerInterface : public UInv_InterfaceBase
{
	GENERATED_BODY()

public:

	virtual void NativeOnInitialized() override;

private:


	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UWidgetSwitcher>InterfaceSwitcher;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Player;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Pets;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Inventory;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Journal;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Map;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Codex;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_Crafting;


	UFUNCTION()
	void Show_Player();

	UFUNCTION()
	void Show_Animals();

	UFUNCTION()
	void Show_Inventory();

	UFUNCTION()
	void Show_Journal();

	UFUNCTION()
	void Show_Map();

	UFUNCTION()
	void Show_Codex();

	UFUNCTION()
	void Show_Crafting();



	void SetActiveIndex(int32 Switcher, UButton* Button);

	// Disables the given button to indicate it is already active
	void DisableButton(UButton* Button);


};
