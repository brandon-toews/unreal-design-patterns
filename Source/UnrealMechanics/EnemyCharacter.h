// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "UnrealMechanics.h"
#include "EnemyCharacter.generated.h"

//Enemy Character used as a base class and to handle the state management for a blueprint enemy character class
UCLASS(Blueprintable, BlueprintType)
class UNREALMECHANICS_API AEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Method declaration that handles the actions the ememy takes while in the Idle state. This is an empty function that is overridden in the derived blueprint enemy character classes
	UFUNCTION(BlueprintCallable, BlueprintType, BlueprintImplementableEvent)
	void Idle();

	//Method declaration that handles the actions the ememy takes while in the Chase state. This is an empty function that is overridden in the derived blueprint enemy character classes
	UFUNCTION(BlueprintCallable, BlueprintType, BlueprintImplementableEvent)
	void Chase();

	//Method declaration that handles the actions the ememy takes while in the Attack state. This is an empty function that is overridden in the derived blueprint enemy character classes
	UFUNCTION(BlueprintCallable, BlueprintType, BlueprintImplementableEvent)
	void Attack();

	//Variable to hold pointer to the stateManager Actor component instance that is attached to this enemy character
	UPROPERTY(VisibleAnywhere, Category = Variables)
	UActorComponent* stateManager = nullptr;

};
