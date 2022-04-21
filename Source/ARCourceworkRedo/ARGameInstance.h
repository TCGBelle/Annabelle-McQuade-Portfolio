// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ARGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARCOURCEWORKREDO_API UARGameInstance : public UGameInstance
{
	GENERATED_BODY()
public:
	//functions are all getters and setters for security of specified varabiles passed betwen objects and levels.
	UFUNCTION(BlueprintCallable)
		virtual void Init();//called at start and reset to set varaibles to there default
	UFUNCTION(BlueprintCallable)
		void IncProgressTracker();// a setter that just +1 to specified variable
	UFUNCTION(BlueprintCallable)
		void SetScanningState(bool newState);
	UFUNCTION(BlueprintCallable)
		bool GetScanningState();
	UFUNCTION(BlueprintCallable)
		int GetProgressTracker();
	UFUNCTION(BlueprintCallable)
		void SetRacingState(bool newState);
	UFUNCTION(BlueprintCallable)
		bool GetRacingState();
	UFUNCTION(BlueprintCallable)
		void SetDisplayRules(bool Rules);
	UFUNCTION(BlueprintCallable)
		bool GetDisplayRules();
	UFUNCTION(BlueprintCallable)
		void SetTurnRate(float newRate);
	UFUNCTION(BlueprintCallable)
		float GetTurnRate();
	UFUNCTION(BlueprintCallable)
		void SetPitchRate(float newRate);
	UFUNCTION(BlueprintCallable)
		float GetPitchRate();
	UFUNCTION(BlueprintCallable)
		void IncPlayerTracker();// a setter that just +1 to specified variable
	UFUNCTION(BlueprintCallable)
		int GetPlayerTracker();
	UFUNCTION(BlueprintCallable)
		void SetGG(bool winner);
	UFUNCTION(BlueprintCallable)
		bool GetGG();
	UFUNCTION(BlueprintCallable)
		void SetBG(bool winner);
	UFUNCTION(BlueprintCallable)
		bool GetBG();
private:
	int iProgressTracker;//how far are we through setting up the cource
	bool bScanningState;
	bool bRacingState;
	bool bRulesDisplaying;
	float fTurnRate;
	float fPitchRate;
	int iPlayerTracker;
	bool bGG;
	bool bBG;
};
