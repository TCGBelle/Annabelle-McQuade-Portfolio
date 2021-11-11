// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Math/Vector2D.h"
#include "CustomARActor.h"
#include "Camera/CameraComponent.h"
#include "TimerManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "CustomARPawn.generated.h"


UCLASS()
class ARLABS_API ACustomARPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACustomARPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual void OnScreenTouch(const ETouchIndex::Type fingerIndex, const FVector screenPos);
	virtual bool WorldHitTest(const FVector2D touchPos, FHitResult hitResult);
	virtual void DisplayCameraInfo();
	virtual void SpawnCube();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) USceneComponent* ScnComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite) UCameraComponent* CameraComponent;

	FTimerHandle cameraTicker;
	float cameraNotifyLoopTime;
	UARSessionConfig* Config;
};
