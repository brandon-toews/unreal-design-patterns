// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

//Custom Parent Player character class that defines and runs some basic player controls. A Blueprint player character class inherits from this class and overrides the Fire method
UCLASS(Blueprintable, BlueprintType)
class UNREALMECHANICS_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Method runs built in unreal Jump function
	void CheckJump();

	//Method takes in a float value and changes the player max walk speed which can be used to make the player run or return back to normal speed
	void Run(float value);

	//Empty method to fire bullets from the bulletpool actor component that attaches to the child blueprint character class. It is overrideen and defined in the blueprint character class.
	UFUNCTION(BlueprintCallable, BlueprintType, BlueprintImplementableEvent)
	void Fire();

private:
	//Method used to move to player forward and backward based on 'W' and 'S' key inputs
	void ForwardBackwardMove(float value);

	//Method used to strafe player left and right based on 'A' and 'D' key inputs
	void StrafeLeftRightMove(float value);

	//Method used to rotate camera left and right based on horizontal mouse movement
	void LeftRightLook(float value);

	//Method used to rotate camera up and down based on vertical mouse movement
	void UpDownLook(float value);

};
