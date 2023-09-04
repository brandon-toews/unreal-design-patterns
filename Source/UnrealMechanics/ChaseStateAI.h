// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealMechanics.h"
#include "BaseStateAI.h"
#include "ChaseStateAI.generated.h"

//Chase state class that executes the enemy character's Chase state behavior
UCLASS(Blueprintable, BlueprintType)
class UNREALMECHANICS_API UChaseStateAI : public UBaseStateAI
{
	GENERATED_BODY()

public:
	//Override method that takes in a reference to the enemy character and runs the Chase method defined in the Blueprint EnemyCharacter class
	virtual void Execute(AEnemyCharacter* owner) override;
};
