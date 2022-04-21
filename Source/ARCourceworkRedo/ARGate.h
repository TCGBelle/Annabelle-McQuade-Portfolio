// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ARGate.generated.h"

UCLASS()
class ARCOURCEWORKREDO_API AARGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARGate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	//getters and setters
	virtual void Tick(float DeltaTime) override;
	UFUNCTION(BlueprintCallable)
		virtual void SetPlayerStart(FTransform tPStart);
	UFUNCTION(BlueprintCallable)
		FTransform GetPlayerStart() const;
	UFUNCTION(BlueprintCallable)
		virtual void SetAiStart(FTransform tEStart);
	UFUNCTION(BlueprintCallable)
		FTransform GetAiStart() const;
private:
	FTransform tPlayerStart;
	FTransform tAiStart;
};
