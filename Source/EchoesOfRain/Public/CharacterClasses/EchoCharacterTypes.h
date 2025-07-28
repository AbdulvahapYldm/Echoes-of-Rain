#pragma once



UENUM(BlueprintType)
enum class EAchoCharacterState : uint8
{
	EACS_UnEquiped UMETA(DisplayName = "UnEquiped"),
	EACS_EquipWeapon UMETA(DisplayName = "EquipWeapon")
};

UENUM(BlueprintType)
enum class EAchoActionState : uint8
{
	EAAS_Unoccupied UMETA(DisplayName = "Unoccupied"),
	EAAS_Attacking UMETA(DisplayName = "Attacking"),
	EAAS_EquipingWeapon UMETA(DisplayName = "EquipingWeapon")
};