// Fill out your copyright notice in the Description page of Project Settings.


#include "ChaseStateAI.h"

//Override method that takes in a reference to the enemy character and runs the Chase method defined in the Blueprint EnemyCharacter class
void UChaseStateAI::Execute(AEnemyCharacter* owner) {
	//Run Chase behavior of enemy character
	owner->Chase();
};