// Fill out your copyright notice in the Description page of Project Settings.


#include "ARPlayer.h"

// Sets default values
AARPlayer::AARPlayer()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	fAccel = 10.0f;
	fMaxS = 100.0f;
	fMinS = 10.0f;
	fForS = 10.0f;
	fRollRateMultiplier = 10.0f;
	fPitchRateMultiplier = 10.0f;

	bIntentionalPitch = false;
	bIntentionalRoll = false;
}

// Called when the game starts or when spawned
void AARPlayer::BeginPlay()
{
	Super::BeginPlay();
	if (GetWorld())
	{
		InstanceRef = Cast<UARGameInstance>(GetWorld()->GetGameInstance());
	}
	UpdateOverlaps(true);
}

void AARPlayer::ProcessKeyPitch(float Rate)
{
	if (FMath::Abs(Rate) > .2f)
	{
		ProcessPitch(Rate * 2.f);
	}
}

void AARPlayer::ProcessKeyRoll(float Rate)
{
	if (FMath::Abs(Rate) > .2f)
	{
		ProcessRoll(Rate * 2.f);
	}
}

void AARPlayer::ProcessRoll(float value)
{
	bIntentionalRoll = FMath::Abs(value) > 0.0f;
	const float fTargetRoll = bIntentionalRoll ? (value * fRollRateMultiplier) : (GetActorRotation().Roll * -2.f);
	//const float fTargetRoll = value * fRollRateMultiplier;
	fCurrentRoll = FMath::FInterpTo(fCurrentRoll, fTargetRoll, GetWorld()->GetDeltaSeconds(), 2.f);
}

void AARPlayer::ProcessPitch(float value)
{
	bIntentionalPitch = FMath::Abs(value) > 0.0f;
	if (bIntentionalPitch && !bIntentionalRoll) return;
	const float fTargetPitch = value * fPitchRateMultiplier;
	fCurrentPitch = FMath::FInterpTo(fCurrentPitch, fTargetPitch, GetWorld()->GetDeltaSeconds(), 2.f);
}

// Called every frame
void AARPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (InstanceRef->GetRacingState() == true)
	{
		ProcessKeyPitch(InstanceRef->GetPitchRate());
		ProcessKeyRoll(InstanceRef->GetTurnRate());
		//Calculate Thrust
		const float fCurrAccel = -GetActorRotation().Pitch * DeltaTime * fAccel;
		const float NewForwardSpeed = fForS + fCurrAccel;
		fForS = FMath::Clamp(NewForwardSpeed, fMinS, fMaxS);

		const FVector localMove = FVector(fForS * DeltaTime, 0.0f, 0.0f);
		AddActorWorldOffset(localMove, true);
		FRotator DeltaRotation(0, 0, 0);
		DeltaRotation.Pitch = fCurrentPitch * DeltaTime;
		DeltaRotation.Yaw = fCurrentYaw * DeltaTime;
		DeltaRotation.Roll = fCurrentRoll * DeltaTime;

		AddActorLocalRotation(DeltaRotation);

		GEngine->AddOnScreenDebugMessage(0, 0.0f, FColor::Green, FString::Printf(TEXT("ForwardSpeed: %f"), fForS));
	}
}

// Called to bind functionality to input
void AARPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("TurnRate", this, &AARPlayer::ProcessKeyRoll);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AARPlayer::ProcessKeyPitch);
}

