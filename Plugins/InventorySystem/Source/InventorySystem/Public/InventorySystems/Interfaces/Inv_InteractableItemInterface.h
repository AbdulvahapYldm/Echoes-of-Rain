// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Inv_InteractableItemInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UInv_InteractableItemInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class INVENTORYSYSTEM_API IInv_InteractableItemInterface
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
	void InteractItem();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
	void UnInteractItem();

	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Interact")
	void PrimaryInteract(APlayerController* Inv_PlayerController);

};
