// Fill out your copyright notice in the Description page of Project Settings.


#include "Command.h"

//Empty method to be overridden by child classes
void UCommand::Execute(AMyCharacter* receiver) {};

//Empty method to be overridden by child classes
void UCommand::StopExecute(AMyCharacter* receiver) {};