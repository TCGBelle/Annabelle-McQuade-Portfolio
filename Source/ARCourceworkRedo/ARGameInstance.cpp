// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGameInstance.h"
void UARGameInstance::Init()
{
	iProgressTracker = 0;
	bScanningState = false;
	bRacingState = false;
	bRulesDisplaying = true;
	fTurnRate = 0.0f;
	fPitchRate = 0.0f;
	iPlayerTracker = 0;
	bGG = false;
	bBG = false;
}

int UARGameInstance::GetProgressTracker()
{
	return iProgressTracker;
}

void UARGameInstance::IncProgressTracker()
{
	iProgressTracker++;
}

bool UARGameInstance::GetScanningState()
{
	return bScanningState;
}

void UARGameInstance::SetScanningState(bool newState)
{
	bScanningState = newState;
}

void UARGameInstance::SetRacingState(bool newState)
{
	bRacingState = newState;
}

bool UARGameInstance::GetRacingState()
{
	return bRacingState;
}

void UARGameInstance::SetDisplayRules(bool Rules)
{
	bRulesDisplaying = Rules;
}

bool UARGameInstance::GetDisplayRules()
{
	return bRulesDisplaying;
}

void UARGameInstance::SetTurnRate(float newRate)
{
	fTurnRate = newRate;
}

float UARGameInstance::GetTurnRate()
{
	return fTurnRate;
}

void UARGameInstance::SetPitchRate(float newRate)
{
	fPitchRate = newRate;
}

float UARGameInstance::GetPitchRate()
{
	return fPitchRate;
}

void UARGameInstance::IncPlayerTracker()
{
	iPlayerTracker++;
}

int UARGameInstance::GetPlayerTracker()
{
	return iPlayerTracker;
}

void UARGameInstance::SetGG(bool winner)
{
	bGG = winner;
}

bool UARGameInstance::GetGG()
{
	return bGG;
}

void UARGameInstance::SetBG(bool winner)
{
	bGG = winner;
}

bool UARGameInstance::GetBG()
{
	return bBG;
}
