// Fill out your copyright notice in the Description page of Project Settings.


#include "RunCommand.h"

//Override method to execute the run command of whatever character is passed in
void URunCommand::Execute(AMyCharacter* receiver) {

	//Change passed in character's run speed to the run speed stored in this class
	receiver->Run(runSpeed);
};

//Override method to stop executing or undo the run command of whatever character is passed in
void URunCommand::StopExecute(AMyCharacter* receiver) {

	//Change passed in character's run speed to the walk speed stored in this class
	receiver->Run(walkSpeed);
};