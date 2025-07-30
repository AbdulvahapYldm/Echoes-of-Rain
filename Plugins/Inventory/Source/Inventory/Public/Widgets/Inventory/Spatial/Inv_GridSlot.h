// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Inv_GridSlot.generated.h"

/**
 * Represents a single tile (slot) in the inventory grid.
 * Each slot knows its index and can hold a visual image (e.g. background or item preview).
 */

class UImage;
UCLASS()
class INVENTORY_API UInv_GridSlot : public UUserWidget
{
	GENERATED_BODY()
	
public:

	// Sets the index of this tile (based on its position in the grid)
	void SetTileIndex(int32 Index){ TileIndex = Index; }

	// Returns the index of this tile
	int32 GetTileIndex()const { return TileIndex; }

private:

	// Stores the index of this tile in the overall grid (e.g., from 0 to N)
	int32 TileIndex;

	// The visual image used to represent the slot (e.g., a background box)
	UPROPERTY(Meta=(BindWidget))
	TObjectPtr<UImage>Image_GridSlot;





};
