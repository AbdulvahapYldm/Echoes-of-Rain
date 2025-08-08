// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/Interfaces/Inventory/Inv_InventorySlot.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Components/Button.h"
#include "Components/VerticalBox.h"
#include "UI/Interfaces/Inventory/Inv_InventorySlotInfo.h"

#include "InventoryFunctionLibrary/UInv_InventoryStatics.h"


void UInv_InventorySlot::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	ConstructInventorySlot();

	InventoryComponent = UUInv_InventoryStatics::GetInventoryComponent(GetOwningPlayer());

}

void UInv_InventorySlot::ConstructInventorySlot()
{

	//InventorySlotInfos.Reserve(Rows);

	// Loop through each row and column to create and position grid slots
	for (int32 j = 0; j < Rows; ++j)
	{
		
		
		// Create a new slot widget from the specified class
		UInv_InventorySlotInfo* SlotInfo = CreateWidget<UInv_InventorySlotInfo>(this, InventorySlotInfoClass);

		// Add the slot widget to the canvas panel (which handles visual layout)
		Item_VerticalBox->AddChildToVerticalBox(SlotInfo);

		SlotInfo->SetItemIndex(j);
			


		// Store a reference to this slot for future access
		InventorySlotInfos.Add(SlotInfo);
		
	}

}
