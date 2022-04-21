// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "ARGateTrigger.generated.h"

/**
 * 
 */
UCLASS()
class ARCOURCEWORKREDO_API AARGateTrigger : public ATriggerBox
{
	GENERATED_BODY()
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//getters and setters
	UFUNCTION(BlueprintCallable)
		virtual void SetPlayerStart(FTransform tPStart);
	UFUNCTION(BlueprintCallable)
		FTransform GetPlayerStart() const;
private:
	FTransform tPlayerStart;
};
