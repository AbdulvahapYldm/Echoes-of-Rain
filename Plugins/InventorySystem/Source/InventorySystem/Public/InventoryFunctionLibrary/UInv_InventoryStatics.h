// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "UInv_InventoryStatics.generated.h"

/**
 * 
 */


class UInv_InventoryComponent;
class UInv_ItemComponent;

UCLASS()
class INVENTORYSYSTEM_API UUInv_InventoryStatics : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	

public:

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	static UInv_InventoryComponent* GetInventoryComponent(APlayerController* PlayerController);


	UFUNCTION(BlueprintCallable, Category = "Inventory")
	static EInv_InventoryCategory GetItemCategoryFromItemComp(UInv_ItemComponent* ItemComp);





};
