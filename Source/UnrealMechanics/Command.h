// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "MyCharacter.h"
#include "Command.generated.h"


//Base command class that child command objects inherit from
UCLASS(Abstract, Blueprintable, BlueprintType)
class UNREALMECHANICS_API UCommand : public UObject
{
	GENERATED_BODY()

public:

	//Empty method to be overridden by child class to execute the specific command object's command. Passes in reference to the player character to run the specific behavior that the command invokes.
	UFUNCTION(BlueprintCallable)
	virtual void Execute(AMyCharacter* receiver);

	//Empty method to be overridden by child class to stop executing the specific command object's command. Passes in reference to the player character to run or undo the specific behavior that the command invokes.
	UFUNCTION(BlueprintCallable)
		virtual void StopExecute(AMyCharacter* receiver);
};
