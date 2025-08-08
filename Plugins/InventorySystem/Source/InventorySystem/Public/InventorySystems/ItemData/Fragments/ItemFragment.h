#pragma once


#include "CoreMinimal.h"
#include "GameplayTagContainer.h"
#include "ItemFragment.generated.h"


USTRUCT(BlueprintType)

struct FItemFragment
{

	GENERATED_BODY()



public:

	FItemFragment() {};

	FItemFragment(const FItemFragment&) = default;
	FItemFragment& operator=(const FItemFragment&) = default;

	FItemFragment(FItemFragment&&) = default;
	FItemFragment& operator=(FItemFragment&&) = default;

	virtual ~FItemFragment() {};



	FGameplayTag GetFragmentTag()const { return FragmentTag; }

	void SetFragmentTag(FGameplayTag Tag) { FragmentTag = Tag; }

private:

	UPROPERTY(EditAnywhere, Category = "Inventory")
	FGameplayTag FragmentTag = FGameplayTag::EmptyTag;






};


USTRUCT(BlueprintType)

struct FItemIconFragment :public FItemFragment
{

	GENERATED_BODY()


public:

	UTexture2D* GetItemIcon()const { return ItemIcon; }

private:

	UPROPERTY(EditAnywhere, Category = "Inventory")
	TObjectPtr<UTexture2D>ItemIcon{nullptr};




};