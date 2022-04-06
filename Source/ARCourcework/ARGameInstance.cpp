// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGameInstance.h"

void UARGameInstance::Init()
{
	bScanningState = false;
	iScanningTracking = 0;
	bRacingState = false;
	bRulesState = true;
	iPlayerTracking = 0;
	iAiTracking = 0;
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

void UARGameInstance::SetStartTransform(FTransform NewTransform)
{
	UTstart = NewTransform;
}

FTransform UARGameInstance::GetStartTransform() const
{
	return FTransform(UTstart);
}

void UARGameInstance::SetGate1Transform(FTransform NewTransform)
{
	UTgate1 = NewTransform;
}

FTransform UARGameInstance::GetGate1Transform() const
{
	return FTransform(UTgate1);
}


void UARGameInstance::SetGate2Transform(FTransform NewTransform)
{
	UTgate2 = NewTransform;
}

FTransform UARGameInstance::GetGate2Transform() const
{
	return FTransform(UTgate2);
}

void UARGameInstance::SetGate3Transform(FTransform NewTransform)
{
	UTgate3 = NewTransform;
}

FTransform UARGameInstance::GetGate3Transform() const
{
	return FTransform(UTgate3);
}

void UARGameInstance::SetGate4Transform(FTransform NewTransform)
{
	UTgate4 = NewTransform;
}

FTransform UARGameInstance::GetGate4Transform() const
{
	return FTransform(UTgate4);
}

void UARGameInstance::IncPlayerTracker()
{
	iPlayerTracking++;
}

int UARGameInstance::GetPlayerTracker() const
{
	return iPlayerTracking;
}

void UARGameInstance::SetPlayerTracker(int tracker)
{
	iPlayerTracking = tracker;
}

void UARGameInstance::IncAiTracker()
{
	iAiTracking++;
}

int UARGameInstance::GetAiTracker() const
{
	return iAiTracking;
}

void UARGameInstance::SetAiTracker(int tracker)
{
	iAiTracking = tracker;
}

void UARGameInstance::SetPlayerStart(FTransform trans)
{
	tPlayerStart = trans;
}

FTransform UARGameInstance::GetPlayerStart() const
{
	return tPlayerStart;
}

void UARGameInstance::SetAiStart(FTransform trans)
{
	tAiStart = trans;
}

FTransform UARGameInstance::GetAiStart() const
{
	return tAiStart;
}





