// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CharacterClasses/BaseCharacter.h"
#include "CharacterClasses/EchoCharacterTypes.h"
#include "AchoCharacter.generated.h"

/**
 * 
 */

class UInputMappingContext;
class UInputAction;
struct FInputActionValue;

class USpringArmComponent;
class UCameraComponent;
class UGroomComponent;



UCLASS()
class ECHOESOFRAIN_API AAchoCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
public:

	AAchoCharacter();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	/**
	*  InputMappingContex
	**/
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputMappingContext* AchoInputMappingContex;

	/**
	*  Acho Input Action
	**/
	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* MovementAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere, Category = "Input")
	UInputAction* JumpAction;

	/**
	*  Callback function for input
	**/
	void AchoMovement(const FInputActionValue& Value);
	void AchoLook(const FInputActionValue& Value);

protected:

	/**
	*  GroomComponent Variables
	**/
	UPROPERTY(VisibleAnywhere, Category = "GroomAsset")
	UGroomComponent* AchoHair;

	UPROPERTY(VisibleAnywhere, Category = "GroomAsset")
	UGroomComponent* AchoAyebrows;

	UPROPERTY(VisibleAnywhere)
	USpringArmComponent* CameraBoom;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;

private:

	EAchoCharacterState AchoCharacterState = EAchoCharacterState::EACS_UnEquiped;

public:

	FORCEINLINE EAchoCharacterState GetCharacterState() const { return AchoCharacterState; }



};
