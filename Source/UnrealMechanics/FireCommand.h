// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "FireCommand.generated.h"

//Fire command class used to execute a fire command of any character passed into it
UCLASS()
class UNREALMECHANICS_API UFireCommand : public UCommand
{
	GENERATED_BODY()
	
public:

	//Override method to execute the fire command of whatever character is passed in
	virtual void Execute(AMyCharacter* receiver) override;
};

