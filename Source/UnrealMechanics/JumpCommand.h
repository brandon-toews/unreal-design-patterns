// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Command.h"
#include "JumpCommand.generated.h"

//Jump command class used to execute a jump command of any character passed into it
UCLASS()
class UNREALMECHANICS_API UJumpCommand : public UCommand
{
	GENERATED_BODY()

public:

	//Override method to execute the jump command of whatever character is passed in
	virtual void Execute(AMyCharacter* receiver) override;
};
