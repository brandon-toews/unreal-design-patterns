// Fill out your copyright notice in the Description page of Project Settings.


#include "AttackStateAI.h"

//Override method that takes in a reference to the enemy character and runs the Attack method defined in the Blueprint EnemyCharacter class
void UAttackStateAI::Execute(AEnemyCharacter* owner) {
	//Run Attack behavior of enemy character
	owner->Attack();
};