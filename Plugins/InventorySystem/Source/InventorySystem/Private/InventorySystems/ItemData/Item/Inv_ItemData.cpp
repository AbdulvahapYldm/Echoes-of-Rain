// Fill out your copyright notice in the Description page of Project Settings.


#include "InventorySystems/ItemData/Item/Inv_ItemData.h"

void UInv_ItemData::SetItemDataManifest(const FInv_ItemDataManifest& Manifest)
{

	ItemDataManifest= FInstancedStruct::Make<FInv_ItemDataManifest>(Manifest);
}
