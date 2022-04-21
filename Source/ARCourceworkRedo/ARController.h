// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "ARBlueprintLibrary.h"
#include "Camera/CameraComponent.h"
#include "ARGate.h"
#include "ARGameInstance.h"
#include "Sound/SoundCue.h"
#include "Components/AudioComponent.h"
#include "ARController.generated.h"

UCLASS()
class ARCOURCEWORKREDO_API AARController : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AARController();

protected:
	UPROPERTY(Category = "myCatagory", VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* SceneComponent;
	UPROPERTY(Category = "myCameraCatagory", VisibleAnywhere, BlueprintReadWrite)
		UCameraComponent* CameraComponent;
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void SpawnGate(int Tracking, FTransform Tf);
	virtual void FindTrackedImages(int Tracking);
	virtual void Scanning();
	virtual void Racing();
	UFUNCTION(BlueprintCallable)
	virtual void ReInt();
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void DisplayCameraInfo();
	UPROPERTY(EditAnywhere)
	USoundCue* RaceMusic;
private:
	FTimerHandle cameraTicker;
	float cameraNotifyLoopTime;
	bool bGoghFound = false;
	bool bWorldFound = false;
	bool bLuardFound = false;
	bool bBruceFound = false;
	bool bOrfistFound = false;
	bool bContinue;
	UARSessionConfig* ARPointer;
	UARGameInstance* InstanceRef;
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
		TSubclassOf<AActor> uPlayer;
	AARGate* aStart;
	AActor* aGate1;
	AActor* aGate2;
	AActor* aGate3;
	AActor* aGate4;
	AActor* aPlayer;
	bool bStartMusic;
	UAudioComponent* AudioComponent;
};
