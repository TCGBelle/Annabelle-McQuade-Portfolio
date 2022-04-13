// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "ARGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class ARCOURCEWORK_API UARGameInstance : public UGameInstance
{
	GENERATED_BODY()

public: 
	UFUNCTION()
	virtual void Init();

	UFUNCTION(BlueprintCallable)
	void SetScanningState(bool NewState);
	UFUNCTION(BlueprintCallable)
	bool GetScanningState() const;
	UFUNCTION(BlueprintCallable)
	void SetScanningTracking(int NewTracking);
	UFUNCTION(BlueprintCallable)
	int GetScanningTracking() const;
	UFUNCTION(BlueprintCallable)
	void SetRacingState(bool NewState);
	UFUNCTION(BlueprintCallable)
	bool GetRacingState() const;
	UFUNCTION(BlueprintCallable)
	void SetProgressTracker(int NewTracker);
	UFUNCTION(BlueprintCallable)
	int GetProgressTracker() const;
	UFUNCTION(BlueprintCallable)
	void SetRulesState(bool NewState);
	UFUNCTION(BlueprintCallable)
	bool GetRulesState() const;
	UFUNCTION(BlueprintCallable)
	void SetStartTransform(FTransform NewState);
	UFUNCTION(BlueprintCallable)
	FTransform GetStartTransform() const;
	UFUNCTION(BlueprintCallable)
	void SetGate1Transform(FTransform NewState);
	UFUNCTION(BlueprintCallable)
	FTransform GetGate1Transform() const;
	UFUNCTION(BlueprintCallable)
	void SetGate2Transform(FTransform NewState);
	UFUNCTION(BlueprintCallable)
	FTransform GetGate2Transform() const;
	UFUNCTION(BlueprintCallable)
	void SetGate3Transform(FTransform NewState);
	UFUNCTION(BlueprintCallable)
	FTransform GetGate3Transform() const;
	UFUNCTION(BlueprintCallable)
	void SetGate4Transform(FTransform NewState);
	UFUNCTION(BlueprintCallable)
	FTransform GetGate4Transform() const;
	UFUNCTION(BlueprintCallable)
		void IncPlayerTracker();
	UFUNCTION(BlueprintCallable)
		int GetPlayerTracker() const;
	UFUNCTION(BlueprintCallable)
		void SetPlayerTracker(int tracker);//only used to reset game.
	UFUNCTION(BlueprintCallable)
		void IncAiTracker();
	UFUNCTION(BlueprintCallable)
		int GetAiTracker() const;
	UFUNCTION(BlueprintCallable)
		void SetAiTracker(int tracker);//only used to reset game.
	UFUNCTION(BlueprintCallable)
		void SetPlayerStart(FTransform trans);
	UFUNCTION(BlueprintCallable)
		FTransform GetPlayerStart() const;
	UFUNCTION(BlueprintCallable)
		void SetAiStart(FTransform trans);
	UFUNCTION(BlueprintCallable)
		FTransform GetAiStart() const;
	UFUNCTION(BlueprintCallable)
		void SetUp(float Up);
	UFUNCTION(BlueprintCallable)
		float GetUp() const;
	UFUNCTION(BlueprintCallable)
		void SetRight(float Right);
	UFUNCTION(BlueprintCallable)
		float GetRight() const;
	UFUNCTION(BlueprintCallable)
		void SetAiBoxTrigger(bool hit);
	UFUNCTION(BlueprintCallable)
		bool GetAiBoxTrigger() const;
	UFUNCTION(BlueprintCallable)
		void SetNextPoint(FTransform nextPoint);
	UFUNCTION(BlueprintCallable)
		FTransform GetNextPoint() const;
	UFUNCTION(BlueprintCallable)
		void SetGameOver(bool GG);
	UFUNCTION(BlueprintCallable)
		bool GetGameOver() const;
	UFUNCTION(BlueprintCallable)
		void IncProgressTracker();
private:
	UPROPERTY(BlueprintGetter = GetScanningState)
	bool bScanningState;
	UPROPERTY(BlueprintGetter = GetScanningTracking)
	int iScanningTracking;
	UPROPERTY(BlueprintGetter = GetRacingState)
	bool bRacingState;
	UPROPERTY(BlueprintGetter = GetProgressTracker)
	int iProgressTracker;
	UPROPERTY(BlueprintGetter = GetScanningState)
	bool bRulesState;
	UPROPERTY(BlueprintGetter = GetStartTransform)
	FTransform UTstart;
	UPROPERTY(BlueprintGetter = GetGate1Transform)
	FTransform UTgate1;
	UPROPERTY(BlueprintGetter = GetGate2Transform)
		FTransform UTgate2;
	UPROPERTY(BlueprintGetter = GetGate3Transform)
		FTransform UTgate3;
	UPROPERTY(BlueprintGetter = GetGate4Transform)
		FTransform UTgate4;
	UPROPERTY(BlueprintGetter = GetPlayerTracker)
		int iPlayerTracking;
	UPROPERTY(BlueprintGetter = GetAiTracker)
		int iAiTracking;
		FTransform tPlayerStart;
	UPROPERTY(BlueprintGetter = GetAiStart)
		FTransform tAiStart;
	UPROPERTY(BlueprintGetter = GetUp)
		float iUp;
	UPROPERTY(BlueprintGetter = GetRight)
		float iRight;
	UPROPERTY(BlueprintGetter = GetAiBoxTrigger)
		bool bAiBoxTrigger;
	UPROPERTY(BlueprintGetter = GetNextPoint)
		FTransform UTnextPoint;
	UPROPERTY(BlueprintGetter = GetGameOver)
		bool bGG;
};
