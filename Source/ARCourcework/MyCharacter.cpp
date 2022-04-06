// Fill out your copyright notice in the Description page of Project Settings.

#include "ARGameInstance.h"
#include "MyCharacter.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		GameInstanceRef = Cast<UARGameInstance>(GetWorld()->GetGameInstance());
	}
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (GameInstanceRef->GetRacingState() == true)
	{
		MoveForward();
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AMyCharacter::MoveForward()
{
	AddMovementInput(GetActorForwardVector());
	//if up button pressed
}

