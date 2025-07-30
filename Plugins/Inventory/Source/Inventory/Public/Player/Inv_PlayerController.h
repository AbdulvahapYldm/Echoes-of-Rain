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
class UInv_InventoryComponent;

UCLASS()
class INVENTORY_API AInv_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:

	AInv_PlayerController();
	
	virtual void Tick(float DeltaTime) override;

	/*INPUT*/
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInventory();

protected:

	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override; // Sets up input bindings
	


private:

	/*INPUT*/

	void PrimaryInteract(); // Function triggered by input (e.g., pressing E)

	TWeakObjectPtr<UInv_InventoryComponent>InventoryComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputMappingContext>Default_Inventory_IMC; // Input mapping context for inventory controls



	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction>PrimaryInteractAction; // Input action for primary interaction (e.g., "E" key)

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TObjectPtr<UInputAction>ToggleInventoryAction;



	void CreateHUDWidget(); // Initializes and adds the HUD widget to the viewport
	void TraceForItem();   // Performs a line trace from the screen center to detect items

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TSubclassOf<UInv_HUDWidget>HUDWidgetClass; // Widget class to be used as the player's HUD (must be a subclass of UInv_HUDWidget)

	UPROPERTY()
	TObjectPtr< UInv_HUDWidget>HUDWidget; // Instance of the HUD widget that is created and displayed during gameplay

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	double TraceLength; // Maximum distance for item detection trace

	UPROPERTY(EditDefaultsOnly, Category = "Inventory")
	TEnumAsByte<ECollisionChannel> ItemTraceChannel; // Collision channel used for tracing interactable items


	// Currently traced actor under the crosshair
	TWeakObjectPtr<AActor> ThisActor;

	// Previously traced actor (used to detect changes)
	TWeakObjectPtr<AActor> LastActor;
	

};
