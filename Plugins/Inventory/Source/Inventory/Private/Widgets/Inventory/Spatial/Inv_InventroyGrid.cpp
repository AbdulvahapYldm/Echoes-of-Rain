// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/Inventory/Spatial/Inv_InventroyGrid.h"
#include "Widgets/Inventory/Spatial/Inv_GridSlot.h"
#include "Components/CanvasPanel.h"
#include "Widgets/Inventory/Utils/Inv_WidgetUtils.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"

void UInv_InventroyGrid::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	// Build the inventory grid when the widget is first initialized
	ConstructGrid();

}

void UInv_InventroyGrid::ConstructGrid()
{
	// Pre-allocate memory for the grid slots to avoid unnecessary allocations
	GridSlots.Reserve(Rows * Columns);

	// Loop through each row and column to create and position grid slots
	for (int32 j = 0; j < Rows; ++j)
	{
		for (int32 i = 0; i < Columns; ++i)
		{
			// Create a new slot widget from the specified class
			UInv_GridSlot* GridSlot = CreateWidget<UInv_GridSlot>(this,GridSlotClass);

			// Add the slot widget to the canvas panel (which handles visual layout)
			CanvasPanel->AddChildToCanvas(GridSlot);

			// Calculate the tile's 1D index and assign it to the slot
			const FIntPoint TilePosition(i, j);
			GridSlot->SetTileIndex(UInv_WidgetUtils::GetIndexFromPosition(TilePosition, Columns));
			
			// Get the slot's layout information so we can position and size it
			UCanvasPanelSlot* GridCanvasPanelSlot = UWidgetLayoutLibrary::SlotAsCanvasSlot(GridSlot);
			
			// Set the size of the slot (width and height in pixels)
			GridCanvasPanelSlot->SetSize(FVector2D(TileSize));

			// Set the position of the slot based on its row and column
			GridCanvasPanelSlot->SetPosition(TilePosition*TileSize);

			// Store a reference to this slot for future access
			GridSlots.Add(GridSlot);
		}
	}
}
