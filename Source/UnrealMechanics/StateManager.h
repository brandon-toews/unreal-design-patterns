// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "MyCharacter.h"
#include "UnrealMechanics.h"
#include "Kismet/GameplayStatics.h"
#include "StateManager.generated.h"

// This Class is for managing the the different states that an enemy character can have. This class is an Actor component that is created in the EnemyCharacter class and attached to the enemy character
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable, BlueprintType)
class UNREALMECHANICS_API UStateManager : public UActorComponent
{
	GENERATED_BODY()

public:

	// Sets default values for this component's properties
	UStateManager();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	//An Unreal Dictionary with strings as key and state objects that inherit from UBaseStateAI class to store all the different states available to an enemy character
	UPROPERTY(EditAnywhere, Category = Variables, BlueprintReadWrite)
		TMap<FString, UBaseStateAI*> stateMap;

	//Pointer to the current state the enemy character is in
	UPROPERTY(EditAnywhere, Category = Variables, BlueprintReadWrite)
		UBaseStateAI* currentState = nullptr;

	//This pointer stores a reference to the enemy character instance that it is attached to
	UPROPERTY(VisibleAnywhere, Category = Variables)
		AEnemyCharacter* owner = nullptr;

	//This pointer stores a reference to the player character
	UPROPERTY(EditAnywhere, Category = Variables)
		AMyCharacter* player = nullptr;

	//This float variable stores the distance between the enemy character and the player
	UPROPERTY(VisibleAnywhere, Category = Variables)
		float distanceToPlayer = 0;

	//A public variable that stores the distance that the enemy will be triggered to enter the chase state. This is editable in the inspector so that it can be easily customized for the various enemy characters.
	UPROPERTY(EditAnywhere, Category = Variables)
		float chaseDistance = 1000;

	//A public variable that stores the distance that the enemy will be triggered to enter the attack state. This is editable in the inspector so that it can be easily customized for the various enemy characters.
	UPROPERTY(EditAnywhere, Category = Variables)
		float attackDistance = 100;

	
//Private functions that do not need to be access in blueprints
private:

	//Function that creates the three different state objects that are stored in the stateMap dictionary
	void InitializeStates();

	//Function used to trigger state changes based on the distance the enemy ins from the player
	void SwitchState();

	//Function used to run to run the current state
	void RunCurrentState();

	//Function used to calculate the distance from the enemy character to the player
	void CalculateDistanceToPlayer();
};
