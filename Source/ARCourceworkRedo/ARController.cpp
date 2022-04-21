// Fill out your copyright notice in the Description page of Project Settings.

#include "ARController.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "TimerManager.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"

// Sets default values
AARController::AARController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(RootComponent);
	cameraNotifyLoopTime = 4.0f;
	static ConstructorHelpers::FObjectFinder<UARSessionConfig>CofigAsset(TEXT("ARSessionConfig'/Game/Images/COnfig.Config'"));
	ARPointer = CofigAsset.Object;
	ARPointer->bUseSceneDepthForOcclusion = true;
	ARPointer->SetSessionTrackingFeatureToEnable(EARSessionTrackingFeature::SceneDepth);
}
// Called when the game starts or when spawned
void AARController::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this, FString(TEXT("Hello world")),true, true, FLinearColor(0, 0.66, 1, 1), 5);
	UARSessionConfig* Config = NewObject<UARSessionConfig>();
	UARBlueprintLibrary::StartARSession(ARPointer);
	GetWorldTimerManager().SetTimer(cameraTicker, this, &AARController::DisplayCameraInfo, cameraNotifyLoopTime, true, 0.0f);
	if (GetWorld())
	{
		InstanceRef = Cast<UARGameInstance>(GetWorld()->GetGameInstance());
	}
	
}
// Called every frame
void AARController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (InstanceRef->GetScanningState() == true)
	{
		Scanning();
	}
	if (InstanceRef->GetRacingState() == true)
	{
		Racing();
	}
}
// Called to sort position in "game flow chart" and set which image to look for next
void AARController::Scanning()
{
	switch (InstanceRef->GetProgressTracker())
	{
	case 1:
		bContinue = false;
		//InstanceRef->SetRulesState(false);
		FindTrackedImages(1);
		if (bContinue == true)
		{
			InstanceRef->IncProgressTracker();
			InstanceRef->SetScanningState(false);
			//InstanceRef->SetRulesState(true);
		}
		break;
	case 3:
		bContinue = false;
		FindTrackedImages(2);
		if (bContinue == true)
		{
			InstanceRef->IncProgressTracker();
			InstanceRef->SetScanningState(false);
		}
		break;
	case 5:
		bContinue = false;
		FindTrackedImages(3);
		if (bContinue == true)
		{
			InstanceRef->IncProgressTracker();
			InstanceRef->SetScanningState(false);
		}
		break;
	case 7:
		bContinue = false;
		FindTrackedImages(4);
		if (bContinue == true)
		{
			InstanceRef->IncProgressTracker();
			InstanceRef->SetScanningState(false);
		}
		break;
	case 9:
		bContinue = false;
		FindTrackedImages(5);
		if (bContinue == true)
		{
			InstanceRef->IncProgressTracker();
			InstanceRef->SetScanningState(false);
		}
		break;
	default:
		break;
	}
}
// Called to bind functionality to input
void AARController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
//displays position of camera on screen
void AARController::DisplayCameraInfo()
{
		// vars for camera location and rotation.
		FVector camLoc;
		FRotator camRot;
		// get camera details
		UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraViewPoint(camLoc,
			camRot);
		// Convert rotation into a vector as camera orientation
		FVector camOri = camRot.Vector();
		// Print to screen
		UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Camera orientation: (%f,% f, % f)"), camOri.X, camOri.Y, camOri.Z), true, true, FLinearColor(0, 0.66, 1, 1), 5);
}
//uses ar to find selected image and then calls sapwn function with location of the image.
void AARController::FindTrackedImages(int Tracking)
{
	//add in rules state change.
	auto trackedImages = UARBlueprintLibrary::GetAllTrackedImages();
	for (UARTrackedImage* trackedImage : trackedImages)
	{
		if (trackedImage->GetDetectedImage())
		{
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("Gogh"))
			{
				if (Tracking == 1)
				{
					if (!bGoghFound)
					{
						bGoghFound = true;

						auto Tf = trackedImage->GetLocalToTrackingTransform();
						// Setting the scale to the transform. this can be done using matrices too.
						Tf.SetScale3D(FVector(0.05f));
						SpawnGate(Tracking, Tf);
						//spawn the player
						FTransform player_Local_Tf; //, enemy_Local_Tf;
						player_Local_Tf.SetLocation(FVector(0, 0, 1100));
						//enemy_Local_Tf.SetLocation(FVector(0, 100, 0));
						FTransform player_World_Tf = player_Local_Tf * Tf;
						//FTransform enemy_World_Tf = enemy_Local_Tf * Tf;
						//aEnemy = GetWorld()->SpawnActor<AActor>(uEnemy, enemy_World_Tf);
						aPlayer = GetWorld()->SpawnActor<AActor>(uPlayer, player_World_Tf);
						//GameInstanceRef->SetStartTransform(Tf);
						bContinue = true;
					}

				}

			}
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("World"))
			{
				if (Tracking == 2)
				{
					if (!bWorldFound)
					{
						bWorldFound = true;
						auto Tf = trackedImage->GetLocalToTrackingTransform();
						// Setting the scale to the transform. this can be done using matrices too.
						Tf.SetScale3D(FVector(0.01f));
						SpawnGate(Tracking, Tf);
						bContinue = true;
					}
				}
			}
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("Luard"))
			{
				if (Tracking == 3)
				{
					if (!bLuardFound)
					{
						bLuardFound = true;

						auto Tf = trackedImage->GetLocalToTrackingTransform();
						// Setting the scale to the transform. this can be done using matrices too.
						Tf.SetScale3D(FVector(0.01f));
						SpawnGate(Tracking, Tf);
						bContinue = true;
					}
				}
			}
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("Bruce"))
			{
				if (Tracking == 4)
				{
					if (!bBruceFound)
					{
						bBruceFound = true;

						auto Tf = trackedImage->GetLocalToTrackingTransform();
						// Setting the scale to the transform. this can be done using matrices too.
						Tf.SetScale3D(FVector(0.01f));
						SpawnGate(Tracking, Tf);
						bContinue = true;
					}
				}
			}
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("Orfist"))
			{
				if (Tracking == 5)
				{
					if (!bOrfistFound)
					{
						bOrfistFound = true;

						auto Tf = trackedImage->GetLocalToTrackingTransform();
						// Setting the scale to the transform. this can be done using matrices too.
						Tf.SetScale3D(FVector(0.01f));
						SpawnGate(Tracking, Tf);
						bContinue = true;
					}
				}
			}
		}
	}
}
//spawns the start/checkpoints at the correct locations
void AARController::SpawnGate(int Tracking, FTransform Tf)
{
	FActorSpawnParameters SpawnInfo;
	FQuat myRot = Tf.GetRotation();
	FVector myLoc = Tf.GetLocation();
	switch (Tracking) {
	case 1:
		aStart = GetWorld()->SpawnActor<AARGate>(uStartGateActor, Tf);
		break;
	case 2:
		aGate1 = GetWorld()->SpawnActor<AActor>(uGateActor1, Tf);
		break;
	case 3:
		aGate2 = GetWorld()->SpawnActor<AActor>(uGateActor1, Tf);
		break;
	case 4:
		aGate3 = GetWorld()->SpawnActor<AActor>(uGateActor1, Tf);
		break;
	case 5:
		aGate4 = GetWorld()->SpawnActor<AActor>(uGateActor1, Tf);
		break;
	}
}
//called when racing is happening keeps track of whos winning and plays music
void AARController::Racing()
{
	if (!bStartMusic)
	{
		//AudioComponent = UGameplayStatics::SpawnSound2D(this, RaceMusic, 1.0f);
		//AudioComponent->SetActive(true);
		//bStartMusic = true;
	}

	if(InstanceRef->GetPlayerTracker() == 4)
	{
		InstanceRef->SetGG(true);
		//AudioComponent->SetActive(false);
	}
	//if(aiTracker == 5)
	//{InstanceRef->SetBG == true }

}
//reset variables for restart
void AARController::ReInt()
{
	bGoghFound = false;
	bWorldFound = false;
	bLuardFound = false;
	bBruceFound = false;
	bOrfistFound = false;
}
