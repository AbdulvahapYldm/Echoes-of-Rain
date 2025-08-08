#pragma once



#include "Inv_Types.generated.h"


UENUM(BlueprintType)
enum class EInv_InventoryCategory : uint8
{
    None        UMETA(DisplayName = "None"),
    AllItem     UMETA(DisplayName = "AllItem"),
    Weapons     UMETA(DisplayName = "Weapons"),
    Armour      UMETA(DisplayName = "Armour"),
    Food        UMETA(DisplayName = "Food"),
    Books       UMETA(DisplayName = "Books"),
    Materials   UMETA(DisplayName = "Materials"),
    Quest       UMETA(DisplayName = "Quest"),
    Other       UMETA(DisplayName = "Other"),
    Pets        UMETA(DisplayName = "Pets"),

};