// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BaseStateAI.generated.h"

//Base State class that all other state classes inherit from
UCLASS(Abstract, Blueprintable, BlueprintType)
class UNREALMECHANICS_API UBaseStateAI : public UObject
{
	GENERATED_BODY()
	
public:
	//Method that takes in a reference to the enemy character that owns the State Manager instance that runs this state
	UFUNCTION(BlueprintCallable)
		virtual void Execute(AEnemyCharacter* owner);
};
