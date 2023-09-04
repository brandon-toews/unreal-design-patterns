// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UnrealMechanics.h"
#include "BaseStateAI.h"
#include "AttackStateAI.generated.h"


//Attack state class that executes the enemy character's Attack state behavior
UCLASS(Blueprintable, BlueprintType)
class UNREALMECHANICS_API UAttackStateAI : public UBaseStateAI
{
	GENERATED_BODY()
	
public:
	//Override method that takes in a reference to the enemy character and runs the Attack method defined in the Blueprint EnemyCharacter class
	virtual void Execute(AEnemyCharacter* owner) override;
};
