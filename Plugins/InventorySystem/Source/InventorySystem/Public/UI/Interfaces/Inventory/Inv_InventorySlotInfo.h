// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_InventorySlotInfo.generated.h"

/**
 * 
 */
class UImage;
class UTextBlock;
class UButton;

UCLASS()
class INVENTORYSYSTEM_API UInv_InventorySlotInfo : public UUserWidget
{
	GENERATED_BODY()
	
public:

	void SetItemIndex(int32 Index) { ItemIndex = Index; }
	int32 GetItemIndex()const { return ItemIndex; }

private:
	UPROPERTY()
	int32 ItemIndex;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UButton>Button_ItemButton;


	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UImage>Image_ItemIcon;


	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemName;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemCount;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemArmor;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemDamage;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemHealty;


	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemWeight;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemPrice;

};
