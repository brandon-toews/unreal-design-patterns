// Fill out your copyright notice in the Description page of Project Settings.


#include "StateManager.h"

// Sets default values for this component's properties
UStateManager::UStateManager() {
	// Set this component to be initialized when the game starts, and to be ticked every frame.
	PrimaryComponentTick.bCanEverTick = true;

}



// Called when the game starts
void UStateManager::BeginPlay() {
	Super::BeginPlay();

	//Get a reference to the enemy character that owns this instance of the state manager and store it in the owner variable
	owner = Cast<AEnemyCharacter>(GetOwner());

	//Get a reference to the player character and store it in the player variable
	player = Cast<AMyCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));

	//Run function to create state objects and store them in the stateMap dictionary
	InitializeStates();

	//Initially set the current state to the Idle state
	currentState = stateMap["Idle"];
}


// Called every frame
void UStateManager::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) {
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//Run the current state
	RunCurrentState();

	//Calculate the distance from enemy to player and store in distance float
	CalculateDistanceToPlayer();

	//Use the distance float to evaluate if the state should be changed
	SwitchState();

}

//Method used to create state objects and store them in the stateMap dictionary
void UStateManager::InitializeStates() {
	//Create Idle state object from the UIdleStateAI class and add it to the stateMap dictionary
	stateMap.Add(TEXT("Idle"), NewObject<UIdleStateAI>());

	//Create Chase state object from the UChaseStateAI class and add it to the stateMap dictionary
	stateMap.Add(TEXT("Chase"), NewObject<UChaseStateAI>());

	//Create Attack state object from the UAttackStateAI class and add it to the stateMap dictionary
	stateMap.Add(TEXT("Attack"), NewObject<UAttackStateAI>());
}

//Method used to switch states based on the distance between the enemy and player
void UStateManager::SwitchState() {
	//If the distance to player is greater then what the chaseDistance is set to then change the current state to Idle state
	if (distanceToPlayer > chaseDistance) {

		//Only change the state to Idle if it isn't already in the Idle state
		if(currentState != stateMap["Idle"]) currentState = stateMap["Idle"];
	}
	//If the distance to player is between the chaseDistance and attackDistance then change the current state to Chase state
	else if (distanceToPlayer < chaseDistance && distanceToPlayer > attackDistance) {

		//Only change the state to Chase if it isn't already in the Chase state
		if (currentState != stateMap["Chase"]) currentState = stateMap["Chase"];
	}
	//If the first two conditions aren't true then the player must be what the attackDistance is set to so change current state to Attack state
	else {

		//Only change the state to Chase if it isn't already in the Chase state
		if (currentState != stateMap["Attack"]) currentState = stateMap["Attack"];
	}
}

//Method used to run whatever the current state is set to
void UStateManager::RunCurrentState() {
	//If current state isn't null then run the state passing in a reference to the enemy character that this state manager instance is attached to
	if (currentState) currentState->Execute(owner);
	
}

//Method used to calculate the distance from enemy to player and store in distance float 
void UStateManager::CalculateDistanceToPlayer() {

	//Both player and owner pointers aren't null
	if (player && owner) {

		//Get the owner and player locations and calculate the distance between the two using an unreal method
		float distance = FVector::Distance(owner->GetActorLocation(), player->GetActorLocation());

		//store calculated distance in variable to be used in the SwitchState method
		distanceToPlayer = distance;
	}
	
}



