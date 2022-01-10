// Fill out your copyright notice in the Description page of Project Settings.


#include "ARController.h"

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
	//GameInstanceRef = Cast<UARGameInstance>(GEngine->GetWorld()->GetGameInstance());
}

// Called when the game starts or when spawned
void AARController::BeginPlay()
{
	Super::BeginPlay();
	
	UARBlueprintLibrary::StartARSession(ARPointer);
}

// Called every frame
void AARController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	// UI rules widget spawned by level 
	//if (GameInstanceRef->GetScanningState() == true){ if 1
		//switch (GameInstanceRef->GetScanningTracking()) {
		//case 1:
	bContinue = false;
	while (bContinue == false)
	{
		FindTrackedImages(1);//passing start point actor and gameobject start//
	}
		//GameInstanceRef->SetProgressTracker(2);
		// GameInstanceRef->SetScanningState(false)
		//break;
		//case 2:
	bContinue = false;
	while (bContinue == false)
	{
		FindTrackedImages(2);//passing checkpoint actor and gameobject Gate 1//
	}
		//GameInstanceRef->SetProgressTracker(3);
		// GameInstanceRef->SetScanningState(false)
		//break;
		//case 3:
	bContinue = false;
	while (bContinue == false)
	{
		FindTrackedImages(3);//passing checkpoint actor and gameobject Gate 2
	}
		//GameInstanceRef->SetProgressTracker(4);
		// GameInstanceRef->SetScanningState(false)
		//break;
		//case 4:
	bContinue = false;
	while (bContinue == false)
	{
		FindTrackedImages(4);//passing checkpoint actor and gameobject Gate 3
	}
		//GameInstanceRef->SetProgressTracker(5);
		// GameInstanceRef->SetScanningState(false)
		//break;
		//case 5:
	bContinue = false;
	while (bContinue == false)
	{
		FindTrackedImages(5);//passing checkpoint actor and gameobject Gate 4
	}
		//GameInstanceRef->SetProgressTracker(6);
		// GameInstanceRef->SetScanningState(false)
		//break;
	//} if 1
	// get world position of start, and gates 1 - 4
		// draw beziar curve
			// pass beziar curve to ai for route its going to follow
	//change state to racing.

	// if (GameInstanceRef->GetRacingState==true) { if 2
	/*check if player has hit check point 1
		if yes set tracker to 1
	if tracker equals 1
		check if player has hit check point 2
			if yes set tracker to 2
	if tracker equals 2
		check if player has hit check point 3
			if yes set tracker to 3
	if tracker equals 3
		check if player has hit check point 4
			if yes set tracker to 4
	if tracker equals 4
		check if player has hit start
			if yes player wins*/

	/*check if ai has hit check point 1
			if yes set aitracker to 1
	if tracker equals 1
		check if ai has hit check point 2
				if yes set aitracker to 2
	if tracker equals 2
		check if ai has hit check point 3
				if yes set aitracker to 3
	if tracker equals 3
		check if ai has hit check point 4
				if yes set aitracker to 4
	if tracker equals 4
		check if ai has hit start
				if yes ai wins*/
	//}if 2
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
		//Start = GetWorld()->SpawnActor<AARCheckerFlag>(myLoc, myRot, SpawnInfo);
		break;
	case 2:
		Gate1 = GetWorld()->SpawnActor<AARCheckPoint>(myLoc, myRot, SpawnInfo);
		break;
	case 3:
		Gate2 = GetWorld()->SpawnActor<AARCheckPoint>(myLoc, myRot, SpawnInfo);
		break;
	case 4:
		Gate3 = GetWorld()->SpawnActor<AARCheckPoint>(myLoc, myRot, SpawnInfo);
		break;
	case 5:
		Gate4 = GetWorld()->SpawnActor<AARCheckPoint>(myLoc, myRot, SpawnInfo);
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
	auto trackedImages = UARBlueprintLibrary::GetAllTrackedImages();
	for (UARTrackedImage* trackedImage : trackedImages)
	{
		if (trackedImage->GetDetectedImage())
		{
			if (trackedImage->GetDetectedImage()->GetFriendlyName().Equals("Vangogh")/*&& Tracking = 1*/)//change to my van gogh freidnly anme when i have access
			{
				if (!bGoghFound)
				{
					SpawnGate(Tracking);
					bGoghFound = true;

					auto Tf = trackedImage->GetLocalToTrackingTransform();
					// Setting the scale to the transform. this can be done using matrices too.
					Tf.SetScale3D(FVector(0.01f));
					switch (Tracking) {
						//break up into 5 diffrent tracked images
					case 1:
						//Start->SetActorTransform(Tf); //set the Start tranform to that of the picture.
						break;
					case 2:
						Gate1->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						break;
					case 3:
						Gate2->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						break;
					case 4:
						Gate3->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						break;
					case 5:
						Gate4->SetActorTransform(Tf); //set the gates tranform to that of the picture.
						break;
					}
					bContinue = true;
				}
			}
		}
	}
}

