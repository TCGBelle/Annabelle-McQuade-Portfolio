// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "ARBlueprintLibrary.h"
#include "ARCheckPoint.h"
//#include "ARGameInstance.h"
#include "ARController.generated.h"

class UARGameInstance;
UCLASS()
class ARCOURCEWORK_API AARController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AARController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void SpawnGate(int Tracking);
	//virtual void FindCandidateImages();

	virtual void FindTrackedImages(int Tracking);

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) USceneComponent* SceneComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) UCameraComponent* CameraComponent;

	FVector CenterPoint;
	bool bGoghFound = false;
	UARSessionConfig* ARPointer;
	bool bContinue;
	UARGameInstance* GameInstanceRef;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> uStartGateActor;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> uGateActor1;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> uGateActor2;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> uGateActor3;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> uGateActor4;
};


