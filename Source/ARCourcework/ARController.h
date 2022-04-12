// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Pawn.h"
#include "ARBlueprintLibrary.h"
//#include "ARGameInstance.h"
#include "Sound/SoundCue.h"
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
	virtual void Debug();

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
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> uEnemy;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> uPlayer;
	UPROPERTY(EditAnywhere, meta = (AllowPrivateAccess = "true"))
		USoundCue* RaceMusic;
	AActor* aStart;
	AActor* aGate1;
	AActor* aGate2;
	AActor* aGate3;
	AActor* aGate4;
	AActor* aEnemy;
	AActor* aPlayer;
};


