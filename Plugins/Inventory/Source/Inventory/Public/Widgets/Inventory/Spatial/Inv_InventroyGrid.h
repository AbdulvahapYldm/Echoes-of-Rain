// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Types/Inv_GridTypes.h"
#include "Inv_InventroyGrid.generated.h"

/**
 * Represents a grid layout for inventory items such as Equippables, Consumables, etc.
 * Responsible for dynamically constructing and managing item slots inside a Canvas Panel.
 */

class UInv_GridSlot;
class UCanvasPanel;

UCLASS()
class INVENTORY_API UInv_InventroyGrid : public UUserWidget
{
	GENERATED_BODY()


public:

	virtual void NativeOnInitialized() override; // Called when the widget is first initialized

	// Returns the item category assigned to this grid (e.g. Equippable, Consumable)
	EInv_ItemCategory GetItemCategory() const { return ItemCategory; }
	
private:

	// Dynamically creates and arranges slot widgets in a grid format
	void ConstructGrid();

	// The category of items this grid will store (e.g. Equippable, Consumable, Craftable)
	UPROPERTY(EditAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess="true"), Category = "Inventory")
	EInv_ItemCategory ItemCategory;


	// Number of rows in the grid (vertical count)
	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 Rows;

	// Number of columns in the grid (horizontal count)
	UPROPERTY(EditAnywhere, Category = "Inventory")
	int32 Columns;

	// Size of each tile in pixels (used for layout positioning)
	UPROPERTY(EditAnywhere, Category = "Inventory")
	float TileSize;

	// The widget class used for creating each individual inventory slot
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_GridSlot>GridSlotClass;

	// Internal array storing references to all generated slot widgets
	UPROPERTY()
	TArray<TObjectPtr<UInv_GridSlot>>GridSlots;

	// The canvas panel where all grid slots will be added and positioned
	UPROPERTY(meta = (BindWidget))
	TObjectPtr<UCanvasPanel> CanvasPanel;



};
