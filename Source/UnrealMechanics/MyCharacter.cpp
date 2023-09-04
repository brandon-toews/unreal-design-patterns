// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter() {
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Automatically sets this character to the first player
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind unreal input mappings to this player the movement methods in this class
	InputComponent->BindAxis("Forward_Backward", this, &AMyCharacter::ForwardBackwardMove);
	InputComponent->BindAxis("Strafe_Left_Right", this, &AMyCharacter::StrafeLeftRightMove);
	InputComponent->BindAxis("Look_Left_Right", this, &AMyCharacter::LeftRightLook);
	InputComponent->BindAxis("Look_Up_Down", this, &AMyCharacter::UpDownLook);
}

//Method used to move to player forward and backward based on 'W' and 'S' key inputs
void AMyCharacter::ForwardBackwardMove(float value) {

	//Value passed in dictates either foward or backward movement
	if (value) AddMovementInput(GetActorForwardVector(), value);
}

//Method for left right movement
void AMyCharacter::StrafeLeftRightMove(float value) {

	//Value passed in dictates either left or right strafe movement
	if (value) AddMovementInput(GetActorRightVector(), value);
}

//Method for rotating left or right
void AMyCharacter::LeftRightLook(float value) {

	//Value passed in dictates either left or right rotation
	if (value) AddControllerYawInput(value);
}

//Method for rotating camera view up or down
void AMyCharacter::UpDownLook(float value) {

	//Value passed in dictates either up or down rotation
	if (value) AddControllerPitchInput(value);
}

//Method runs Jump method inherited from the ACharacter class
void AMyCharacter::CheckJump() {

	//Method to make player jump
	Jump();
}

//Method to change player's max walk speed to make to player run or return back to normal speed
void AMyCharacter::Run(float value) {

	//set player's max walk speed to the value parameter passed into the method
	GetCharacterMovement()->MaxWalkSpeed = value;
}