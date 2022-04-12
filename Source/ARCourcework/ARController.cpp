// Fill out your copyright notice in the Description page of Project Settings.


#include "ARController.h"
#include "Sound/SoundBase.h"
#include "Kismet/GameplayStatics.h"
#include "ARGameInstance.h"

// Sets default values
AARController::AARController()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene"));
	SetRootComponent(SceneComponent);

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(RootComponent);

	static ConstructorHelpers::FObjectFinder<UARSessionConfig>ARConfig(TEXT("ARSessionConfig'/Game/Images/ARSessionConfig2.ARSessionConfig2'"));
	ARPointer = ARConfig.Object;
}

// Called when the game starts or when spawned
void AARController::BeginPlay()
{
	Super::BeginPlay();

		if (GetWorld())
		{
			GameInstanceRef = Cast<UARGameInstance>(GetWorld()->GetGameInstance());
		}
	UARBlueprintLibrary::StartARSession(ARPointer);
	
}

// Called every frame
void AARController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//InputComponent->BindAction("Debug", IE_Released, this, &AARController::Debug);
	// UI rules widget spawned by level 
	if (GameInstanceRef->GetScanningState() == true)
	{ //if 1
		switch (GameInstanceRef->GetProgressTracker()) {
		case 2:
			bContinue = false;
			GameInstanceRef->SetRulesState(false);
			FindTrackedImages(1);//passing start point actor and gameobject start//
			if (bContinue == true)
			{
				aEnemy->SetActorTransform(GameInstanceRef->GetAiStart());
				aPlayer->SetActorTransform(GameInstanceRef->GetPlayerStart());
				GameInstanceRef->IncProgressTracker();
				GameInstanceRef->SetScanningState(false);
				GameInstanceRef->SetRulesState(true);
			}
			break;
		case 4:
			bContinue = false;
			FindTrackedImages(2);//passing checkpoint actor and gameobject Gate 1//
			if (bContinue == true)
			{
				GameInstanceRef->IncProgressTracker();
				GameInstanceRef->SetScanningState(false);
			}
			break;
		case 6:
			bContinue = false;
			FindTrackedImages(3);//passing checkpoint actor and gameobject Gate 2
			if (bContinue == true)
			{
				GameInstanceRef->IncProgressTracker();
				GameInstanceRef->SetScanningState(false);
			}
			break;
		case 8:
			bContinue = false;
			FindTrackedImages(4);//passing checkpoint actor and gameobject Gate 3
			if (bContinue == true)
			{
				GameInstanceRef->IncProgressTracker();
				GameInstanceRef->SetScanningState(false);
			}
			break;
		case 10:
			bContinue = false;
			FindTrackedImages(5);//passing checkpoint actor and gameobject Gate 4
			if (bContinue == true)
			{
				GameInstanceRef->IncProgressTracker();
				GameInstanceRef->SetScanningState(false);
			}
			break;
		default:
			break;
		}
	} //if 1
	// get world position of start, and gates 1 - 4
		// draw beziar curve
			// pass beziar curve to ai for route its going to follow
	//change state to racing.

	if (GameInstanceRef->GetRacingState() == true) { //if 2
		//player movment
		//ai movment
		//Play music
		UGameplayStatics::PlaySound2D(this, RaceMusic);
		switch (GameInstanceRef->GetPlayerTracker()) {
		case 1:
			
			break;
		case 2:
			//check if player has hit check point 2
				//if yes set tracker to 2
			break;
		case 3:
		//check if player has hit check point 3
			//if yes set tracker to 3
			break;
		case 4:
		//check if player has hit check point 4
			//if yes set tracker to 4
		//check if player has hit start
			//if yes player wins*/
			GameInstanceRef->SetGameOver(true);
			break;
		default:
			break;
		}

		switch (GameInstanceRef->GetAiTracker())
		{
		case 0:
			GameInstanceRef->SetNextPoint(GameInstanceRef->GetGate1Transform());
			break;
		case 1:
			GameInstanceRef->SetNextPoint(GameInstanceRef->GetGate2Transform());
			break;
		case 2:
			GameInstanceRef->SetNextPoint(GameInstanceRef->GetGate3Transform());
			//check if ai has hit check point 2
					//if yes set aitracker to 2
			break;
		case 3:
			GameInstanceRef->SetNextPoint(GameInstanceRef->GetGate4Transform());
			//check if ai has hit check point 3
					//if yes set aitracker to 3
			break;
		case 4:
			//check if ai has hit check point 4
					//if yes set aitracker to 4
			GameInstanceRef->SetGameOver(true);
			break;
			//check if ai has hit start
					//if yes ai wins
		default:
			break;
		}
	}//if 2
}

// Called to bind functionality to input
void AARController::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AARController::SpawnGate(int Tracking)
{
	FActorSpawnParameters SpawnInfo;
	FRotator myRot(0, 0, 0);
	FVector myLoc(900, 0, 0);
	switch (Tracking) {
	case 1 : 
		//Start = GetWorld()->SpawnActor<AActor>(myLoc, myRot, SpawnInfo);
		aStart = GetWorld()->SpawnActor<AActor>(uStartGateActor, myLoc, myRot);
		aEnemy = GetWorld()->SpawnActor<AActor>(uEnemy, myLoc, myRot);
		aPlayer = GetWorld()->SpawnActor<AActor>(uPlayer, myLoc, myRot);
		//move player
		//spawn ai
		break;
	case 2:
		aGate1 = GetWorld()->SpawnActor<AActor>(uGateActor1, myLoc, myRot);
		break;
	case 3:
		aGate2 = GetWorld()->SpawnActor<AActor>(uGateActor1, myLoc, myRot);
		break;
	case 4:
		aGate3 = GetWorld()->SpawnActor<AActor>(uGateActor1, myLoc, myRot);
		break;
	case 5:
		aGate4 = GetWorld()->SpawnActor<AActor>(uGateActor1, myLoc, myRot);
		break;
	}
}

/*void AARController::FindCandidateImages()
{
	
	auto trackedImages = UARBlueprintLibrary::GetAllTrackedImages();
	GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, FString::Printf(TEXT("Images number %d"), trackedImages.Num()));
	//UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Images number %d"), trackedImages), true, true, FLinearColor(1, 0, 0, 1), 5);
	for (UARTrackedImage* trackedImage : trackedImages)
	{
		if (trackedImage->GetDetectedImage())
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("Vangogh"))//change to my van gogh freidnly anme when i have access
			{
				//If the VanGogh image is first seen then spawn an actor in its location
				if (!bGoghFound)
				{
					SpawnGate();
					bGoghFound = true;
				}
					auto Tf = trackedImage->GetLocalToTrackingTransform();
					// Setting the scale to the transform. this can be done using matrices too.
					Tf.SetScale3D(FVector(0.01f));
					Gate1->SetActorTransform(Tf); //set the gates tranform to that of the picture.
				FVector SpawnLoc = Tf.GetLocation();
				GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, FString::Printf(TEXT("%f, %f, %f"), SpawnLoc.X, SpawnLoc.Y, SpawnLoc.Z));
			}
	}
}*/

void AARController::FindTrackedImages(int Tracking)
{
	//add in rules state change.
	auto trackedImages = UARBlueprintLibrary::GetAllTrackedImages();
	for (UARTrackedImage* trackedImage : trackedImages)
	{
		if (trackedImage->GetDetectedImage())
		{
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("Vangogh") /*&& Tracking = 1*/)//change to my van gogh freidnly anme when i have access
			{
				if (Tracking == 1)
				{
					if (!bGoghFound)
					{
						SpawnGate(Tracking);
						bGoghFound = true;

						auto Tf = trackedImage->GetLocalToTrackingTransform();
						// Setting the scale to the transform. this can be done using matrices too.
						Tf.SetScale3D(FVector(0.01f));

						aStart->SetActorTransform(Tf); //set the Start tranform to that of the picture.

						GameInstanceRef->SetStartTransform(Tf);
						bContinue = true;
					}
				
				}
			
			}
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("World"))
			{
				if (Tracking > 1)
				{
					SpawnGate(Tracking);
					auto Tf = trackedImage->GetLocalToTrackingTransform();
					// Setting the scale to the transform. this can be done using matrices too.
					Tf.SetScale3D(FVector(0.01f));
					switch (Tracking) {
					case 2:
						aGate1->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						GameInstanceRef->SetGate1Transform(Tf);
						break;
					case 3:
						aGate2->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						GameInstanceRef->SetGate2Transform(Tf);
						break;
					case 4:
						aGate3->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						GameInstanceRef->SetGate3Transform(Tf);
						break;
					case 5:
						aGate4->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						GameInstanceRef->SetGate4Transform(Tf);
						break;
					}
					bContinue = true;
				}
			}
			
		}
	}
}

void AARController::Debug()
{
	GameInstanceRef->IncProgressTracker();
}

