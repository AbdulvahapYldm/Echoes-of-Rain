// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Inv_WidgetUtils.generated.h"

/**
 * A static utility class that provides helper functions for widgets.
 * Typically used for grid calculations and UI logic.
 */

UCLASS()
class INVENTORY_API UInv_WidgetUtils : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:

	/**
	 * Converts a 2D grid position (row, column) to a linear array index.
	 * For example: (1, 2) in a grid with 5 columns becomes index = 1 * 5 + 2 = 7.
	 *
	 * @param Position - The 2D position in the grid.
	 * @param Columns - The number of columns in the grid.
	 * @return The linear index corresponding to the grid position.
	 */
	static int32 GetIndexFromPosition(const FIntPoint&Position,const int32 Columns);

};
