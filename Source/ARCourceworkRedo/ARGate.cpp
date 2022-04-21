// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGate.h"

// Sets default values
AARGate::AARGate()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AARGate::BeginPlay()
{
	Super::BeginPlay();
	UpdateOverlaps(true);
}

// Called every frame
void AARGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AARGate::SetPlayerStart(FTransform tPStart)
{
	tPlayerStart = tPStart;
}

FTransform AARGate::GetPlayerStart() const
{
	return tPlayerStart;
}

void AARGate::SetAiStart(FTransform tEStart)
{
	tAiStart = tEStart;
}

FTransform AARGate::GetAiStart() const
{
	return tAiStart;
}

