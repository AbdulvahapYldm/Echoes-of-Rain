// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Inv_InventoryComponent.generated.h"


class UInv_InventoryBase;
class UInv_InventoryItem;
class UInv_ItemComponent;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FInventoryItemChange, UInv_InventoryItem*,Item);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FNoRoomInInventory);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class INVENTORY_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	UInv_InventoryComponent();

	void ToggleInventoryMenu();


	FInventoryItemChange OnItemAdded;
	FInventoryItemChange OnItemRemoved;
	FNoRoomInInventory NoRoomInInventory;

	UFUNCTION(BlueprintCallable, BlueprintAuthorityOnly, Category = "Inventory")
	void TryAddItem(UInv_ItemComponent* ItemComponent);

protected:

	virtual void BeginPlay() override;

private:

	TWeakObjectPtr<APlayerController>OwningController;

	void ConstructInventory();

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf< UInv_InventoryBase>InventoryMenuClass;

	UPROPERTY()
	TObjectPtr< UInv_InventoryBase>InventoryMenu;

	bool bInventoryMenuOpen;

	void OpenInventoryMenu();
	void CloseInventoryMenu();
		
};
