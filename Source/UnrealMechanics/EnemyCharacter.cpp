// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCharacter.h"

// Sets default values
AEnemyCharacter::AEnemyCharacter() {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Creates instance of the StateManager Actor component and stores a pointer to it
	stateManager = CreateDefaultSubobject<UStateManager>(TEXT("StateManager"));
}

// Called when the game starts or when spawned
void AEnemyCharacter::BeginPlay() {
	Super::BeginPlay();
	
	//Attaches State Manager component to the enemy character
	stateManager->RegisterComponent();
}

// Called every frame
void AEnemyCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}