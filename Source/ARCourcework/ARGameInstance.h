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
private:
	UPROPERTY(BlueprintGetter = GetScanningState)
	bool bScanningState;
	UPROPERTY(BlueprintGetter = GetScanningTracking)
	int iScanningTracking;
	UPROPERTY(BlueprintGetter = GetRacingState)
	bool bRacingState;

};
