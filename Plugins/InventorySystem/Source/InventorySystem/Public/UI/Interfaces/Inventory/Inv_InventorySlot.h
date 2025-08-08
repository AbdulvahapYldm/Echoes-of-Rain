// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "InventorySystems/Types/Inv_Types.h"
#include "Inv_InventorySlot.generated.h"

/**
 * 
 */
class UImage;
class UTextBlock;
class UButton;
class UVerticalBox;
class UInv_InventorySlotInfo;

class UInv_InventoryComponent;

UCLASS()
class INVENTORYSYSTEM_API UInv_InventorySlot : public UUserWidget
{
	GENERATED_BODY()

public:

	virtual void NativeOnInitialized() override;

	EInv_InventoryCategory GetInventoryCategory()const { return InventoryCategory; }




private:

	void ConstructInventorySlot();


	TWeakObjectPtr<UInv_InventoryComponent>InventoryComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Inventory")
	EInv_InventoryCategory InventoryCategory;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UTextBlock>Text_ItemCategory;


	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_InventorySlotInfo>InventorySlotInfoClass;

	UPROPERTY()
	TArray<TObjectPtr<UInv_InventorySlotInfo>>InventorySlotInfos;

	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UVerticalBox>Item_VerticalBox;


	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 Rows{1};



};
