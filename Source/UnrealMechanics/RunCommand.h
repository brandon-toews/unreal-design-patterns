// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "RunCommand.generated.h"

//Run command class used to execute a run command of any character passed into it
UCLASS()
class UNREALMECHANICS_API URunCommand : public UCommand
{
	GENERATED_BODY()
	
public:

	//Override method to execute the run command of whatever character is passed in
	virtual void Execute(AMyCharacter* receiver) override;

	//Override method to stop executing or undo the run command of whatever character is passed in
	virtual void StopExecute(AMyCharacter* receiver) override;

private:

	//Stored normal walk speed
	float walkSpeed = 600.0f;

	//Stored run speed
	float runSpeed = 1200.0f;
};
