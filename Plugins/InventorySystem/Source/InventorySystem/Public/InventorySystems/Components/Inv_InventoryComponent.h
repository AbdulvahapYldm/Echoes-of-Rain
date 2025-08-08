// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "InventorySystems/ItemData/Item/Inv_ItemDataManifest.h"
#include "Inv_InventoryComponent.generated.h"

class UInv_InterfaceBase;
class UInv_ItemComponent;
class UInv_ItemData;




UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent),Blueprintable )
class INVENTORYSYSTEM_API UInv_InventoryComponent : public UActorComponent
{
	GENERATED_BODY()

public:	

	// Bir öğeyi envantere eklemek için fonksiyon
	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void AddItem(UInv_ItemData* ItemToAdd);

	// Envanterdeki öğelerin bir kopyasını döndürür
	UFUNCTION(BlueprintPure, Category = "Inventory")
	TArray<FInv_ItemDataManifest> GetPlayerInventory() const { return PlayerInventory; }



	UInv_InventoryComponent();

	UFUNCTION(BlueprintCallable, Category = "Inventory")
	void ToggleInterfaceMenu();

	
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TArray<UInv_ItemData*> Inventory;
	
protected:
	
	virtual void BeginPlay() override;


private:

	// Envanterdeki öğeleri tutan dizi. Artık FInv_ItemDataManifest kullanıyor.
	UPROPERTY(EditAnywhere, Category = "Inventory")
	TArray<FInv_ItemDataManifest> PlayerInventory;


	void ConstructInterfaceMenu();
	
	/*Interfaces Widget*/
	TWeakObjectPtr<APlayerController>OwningController;

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TSubclassOf<UInv_InterfaceBase>InterfaceMenuClass; 
		
	UPROPERTY()
	TObjectPtr<UInv_InterfaceBase>InterfaceMenu;

	bool bInventoryMenuOpen;

	void OpenInterfaceMenu();
	void CloseInterfaceMenu();

	/*Interfaces widget finish*/







};
