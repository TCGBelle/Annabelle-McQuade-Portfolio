// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGateTrigger.h"

void AARGateTrigger::BeginPlay()
{
	Super::BeginPlay();
	UpdateOverlaps(true);
}

void AARGateTrigger::SetPlayerStart(FTransform tPStart)
{
	tPlayerStart = tPStart;
}

FTransform AARGateTrigger::GetPlayerStart() const
{
	return tPlayerStart;
}
