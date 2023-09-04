// Fill out your copyright notice in the Description page of Project Settings.


#include "JumpCommand.h"

//Override method to execute the jump command of whatever character is passed in
void UJumpCommand::Execute(AMyCharacter* receiver) {

   //Run the passed in character's jump command
   receiver->CheckJump();
};