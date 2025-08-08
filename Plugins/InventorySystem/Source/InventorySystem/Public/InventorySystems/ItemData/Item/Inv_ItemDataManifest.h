#pragma once

#include "CoreMinimal.h"
#include "InventorySystems/Types/Inv_Types.h"
#include "StructUtils/InstancedStruct.h"
#include "GameplayTagContainer.h"
#include "Engine/Texture2D.h"
#include "Inv_ItemDataManifest.generated.h"


/* Item Manifest contains all of the necessary data for creating new inventory item */

/*ItemData icindeki veriler bu structan geliyor.*/


class UInv_ItemData;
struct FItemFragment;

USTRUCT(BlueprintType)
struct INVENTORYSYSTEM_API FInv_ItemDataManifest
{

	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FString ItemName{"Item Name"};

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 Quantity{ 1 };


	UInv_ItemData* ItemManifest(UObject* NewOuter);

	EInv_InventoryCategory GetItemCategory() const { return ItemCategory; }

	FGameplayTag GetItemType() const { return ItemType; }
	


	template<typename T> requires std::derived_from<T, FItemFragment>
	const T* GetFragmentOfTypeWithByTag(const FGameplayTag& FragmentTag ) const
	{
		for (const TInstancedStruct<FItemFragment>& Fragment : Fragments)
		{
			if (const T* FragmentPtr = Fragment.GetPtr<T>())
			{
				if (!FragmentPtr->GetFragmentTag().MatchesTagExact(FragmentTag)) continue;
				return FragmentPtr;
			}
		}
		return nullptr;
	}

private:

	UPROPERTY(EditAnywhere, Category = "Inventory", meta = (ExcludeBaseStruct))
	TArray<TInstancedStruct<FItemFragment>>Fragments;



	UPROPERTY(EditAnywhere, Category = "Inventory")
	EInv_InventoryCategory ItemCategory{ EInv_InventoryCategory::None };

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTag ItemType;


};