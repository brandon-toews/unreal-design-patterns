// Fill out your copyright notice in the Description page of Project Settings.


#include "IdleStateAI.h"

//Override method that takes in a reference to the enemy character and runs the Idle method defined in the Blueprint EnemyCharacter class
void UIdleStateAI::Execute(AEnemyCharacter* owner) {
	//Run Idle behavior of enemy character
	owner->Idle();

};