// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventorySystems/ItemData/Item/Inv_ItemDataManifest.h"
#include "Inv_ItemComponent.generated.h"

class UInv_ItemData;


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class INVENTORYSYSTEM_API UInv_ItemComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UInv_ItemComponent();

	FString GetPickupMessage() const { return ItemDataManifest.ItemName; }
	FInv_ItemDataManifest GetItemDataManifest()const { return ItemDataManifest; }
	UInv_ItemData* GetItemData() const { return ItemData; }
private:

	UPROPERTY(EditAnywhere, Category = "Inventory")//Item data
	FInv_ItemDataManifest ItemDataManifest;

	UPROPERTY(EditAnywhere, Category = "Inventory")//Item data

	UInv_ItemData* ItemData;

	
	


};
