// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InventorySystems/Interfaces/Inv_InteractableItemInterface.h"
#include "Inv_InteractableBaseItem.generated.h"

// Forward declarations
class UStaticMeshComponent;
class UWidgetComponent;
class UInv_ItemComponent;
class UInv_PickupWidget;


/**
 * Base class for any interactable item placed in the world.
 * Implements IInv_InteractableItemInterface to allow interaction via line trace, etc.
 */
UCLASS()
class INVENTORYSYSTEM_API AInv_InteractableBaseItem : public AActor, public IInv_InteractableItemInterface
{
	GENERATED_BODY()

public:
	AInv_InteractableBaseItem();

	/** Called when the player looks at (or otherwise interacts with) the item */
	virtual void InteractItem_Implementation() override;

	/** Called when the player stops looking at the item */
	virtual void UnInteractItem_Implementation() override;


	virtual void PrimaryInteract_Implementation(APlayerController* Inv_PlayerController) override;

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Inventory")
	TObjectPtr<USceneComponent> RootScene;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UStaticMeshComponent> StaticMesh;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UMaterialInterface> HighlightMaterial;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UWidgetComponent> WidgetComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	TObjectPtr<UInv_ItemComponent> ItemComponent;

private:

	UPROPERTY()
	TObjectPtr<UInv_PickupWidget> PickupWidget;



};
