
#include "InventorySystems/ItemData/Item/Inv_ItemDataManifest.h"
#include "InventorySystems/ItemData/Item/Inv_ItemData.h"



UInv_ItemData* FInv_ItemDataManifest::ItemManifest(UObject* NewOuter)
{
    
    UInv_ItemData* ItemData= NewObject< UInv_ItemData>(NewOuter, UInv_ItemData::StaticClass());
    ItemData->SetItemDataManifest(*this);
    return ItemData;

}
