// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ARGameInstance.h"
#include "ARPlayer.generated.h"

UCLASS()
class ARCOURCEWORKREDO_API AARPlayer : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AARPlayer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void ProcessKeyPitch(float Rate);
	void ProcessKeyRoll(float Rate);

	// for calculating the roatation
	void ProcessRoll(float value);
	void ProcessPitch(float value);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere, Category = "Flight")
	float fAccel;
	UPROPERTY(EditAnywhere, Category = "Flight")
	float fMaxS;
	UPROPERTY(EditAnywhere, Category = "Flight")
	float fMinS;
	UPROPERTY(EditAnywhere, Category = "Flight")
	float fForS;
	UPROPERTY(EditAnywhere, Category = "Flight")
	float fRollRateMultiplier;
	UPROPERTY(EditAnywhere, Category = "Flight")
	float fPitchRateMultiplier;
	float fYawRateMultiplier;
	float fCurrentYaw;
	float fCurrentPitch;
	float fCurrentRoll;

	bool bIntentionalPitch;
	bool bIntentionalRoll;

	UARGameInstance* InstanceRef;
};
