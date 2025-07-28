// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include"CharacterClasses/EchoCharacterTypes.h"
#include "Acho_AnimInstance.generated.h"

/**
 * 
 */
class AAchoCharacter;
class UCharacterMovementComponent;

UCLASS()
class ECHOESOFRAIN_API UAcho_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()


public:

	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaTime) override;

	UPROPERTY(BlueprintReadOnly, Category = "Acho AnimInstance")
	AAchoCharacter* AchoCharacter;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	UCharacterMovementComponent* AchoCharacterMovement;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	float GroundSpeed;

	UPROPERTY(BlueprintReadWrite, Category = Movement)
	bool IsFalling;

	UPROPERTY(BlueprintReadOnly, Category = Movement)
	EAchoCharacterState AchoCharacterState;
	
};
