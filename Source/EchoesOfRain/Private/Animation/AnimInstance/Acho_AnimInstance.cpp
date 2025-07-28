// Fill out your copyright notice in the Description page of Project Settings.


#include "Animation/AnimInstance/Acho_AnimInstance.h"
#include "CharacterClasses/Player/AchoCharacter.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"


void UAcho_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	AchoCharacter = Cast<AAchoCharacter>(TryGetPawnOwner());

	if (AchoCharacter)
	{
		AchoCharacterMovement = AchoCharacter->GetCharacterMovement();
	}
}

void UAcho_AnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);

	if (AchoCharacterMovement)
	{
		GroundSpeed = UKismetMathLibrary::VSizeXY(AchoCharacterMovement->Velocity);
		IsFalling = AchoCharacterMovement->IsFalling();
		AchoCharacterState = AchoCharacter->GetCharacterState();
	}
}
