// Fill out your copyright notice in the Description page of Project Settings.


#include "FireCommand.h"

//Override method to execute the fire command of whatever character is passed in
void UFireCommand::Execute(AMyCharacter* receiver) {

	//Run the passed in character's fire command
	receiver->Fire();
};