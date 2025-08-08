// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "InventorySystems/ItemData/Item/Inv_ItemDataManifest.h"
#include "Inv_ItemData.generated.h"

/**
 * //Inventory Item Data(Inventorydeki item)
 */


UCLASS(Blueprintable)
class INVENTORYSYSTEM_API UInv_ItemData : public UObject
{
	GENERATED_BODY()
	
public:

    void SetItemDataManifest(const FInv_ItemDataManifest& Manifest);
 
    const FInv_ItemDataManifest& GetItemDataManifest()const { return ItemDataManifest.Get<FInv_ItemDataManifest>(); }

  
    FInv_ItemDataManifest& GetItemDataManifesMutable() { return ItemDataManifest.GetMutable< FInv_ItemDataManifest>(); }

private:

    UPROPERTY(VisibleAnywhere, meta = (BaseStruct = "/Script/InventorySystems.Inv_ItemDataManifest"))
    FInstancedStruct ItemDataManifest;

};
