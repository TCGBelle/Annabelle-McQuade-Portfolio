// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGameInstance.h"

void UARGameInstance::Init()
{
	bScanningState = false;
	iScanningTracking = 0;
	bRacingState = false;
	bRulesState = true;
}

void UARGameInstance::SetScanningState(bool NewState)
{
	bScanningState = NewState;
}

bool UARGameInstance::GetScanningState() const
{
	return bScanningState;
}

void UARGameInstance::SetScanningTracking(int NewTracking)
{
	iScanningTracking = NewTracking;
}

int UARGameInstance::GetScanningTracking() const
{
	return iScanningTracking;
}

void UARGameInstance::SetRacingState(bool NewState)
{
	bRacingState = NewState;
}

bool UARGameInstance::GetRacingState() const
{
	return bRacingState;
}

void UARGameInstance::SetProgressTracker(int NewTracker)
{
	iProgressTracker = NewTracker;
}

int UARGameInstance::GetProgressTracker() const
{
	return iProgressTracker;
}

void UARGameInstance::SetRulesState(bool NewState)
{
	bRulesState = NewState;
}

bool UARGameInstance::GetRulesState() const
{
	return bRulesState;
}
