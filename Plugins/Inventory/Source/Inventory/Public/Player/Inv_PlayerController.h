// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Inv_PlayerController.generated.h"

/**
 * 
 */

 // Forward declarations
class UInputMappingContext;
class UInputAction;
class UInv_HUDWidget;

UCLASS()
class INVENTORY_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override; // Sets up input bindings


private:

	void PrimaryInteract(); // Function triggered by input (e.g., pressing E)
	void CreateHUDWidget(); // Initializes and adds the HUD widget to the viewport

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputMappingContext>Default_Inventory_IMC; // Input mapping context for inventory controls


	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction>PrimaryInteractAction; // Input action for primary interaction (e.g., "E" key)

	UPROPERTY(EditDefaultsOnly, Category = "Widget Class")
	TSubclassOf<UInv_HUDWidget>HUDWidgetClass; // Widget class to be used as the player's HUD (must be a subclass of UInv_HUDWidget)

	UPROPERTY()
	TObjectPtr< UInv_HUDWidget>HUDWidget; // Instance of the HUD widget that is created and displayed during gameplay

};
