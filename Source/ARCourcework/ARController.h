// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "ARBlueprintLibrary.h"
#include "ARCheckPoint.h"
#include "ARController.generated.h"

UCLASS()
class ARCOURCEWORK_API AARController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AARController();
	enum GameStates { Checking, Racing };
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SpawnGate(int Tracking);
	virtual void FindCandidateImages();

	bool FindTrackedImages(int Tracking);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) UCameraComponent* CameraComponent;

	FVector CenterPoint;
	bool bGoghFound = false;
	UARSessionConfig* ARPointer;
	AARCheckPoint* Gate1;
	AARCheckPoint* Gate2;
	AARCheckPoint* Gate3;
	AARCheckPoint* Gate4;
	GameStates State;
};
