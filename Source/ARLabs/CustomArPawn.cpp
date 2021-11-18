// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomARPawn.h"
#include "Runtime/Engine/Classes/Kismet/KismetSystemLibrary.h"
#include "Runtime/Engine/Classes/Kismet/KismetMathLibrary.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "ARBlueprintLibrary.h"

// Sets default values
ACustomARPawn::ACustomARPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ScnComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Default Scene"));
	RootComponent = ScnComponent;

	CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
	CameraComponent->SetupAttachment(RootComponent);

	cameraNotifyLoopTime = 4.0f;
	scanningTime = 1.0f;
	intialTime = 0.0f;

	static ConstructorHelpers::FObjectFinder<UARSessionConfig> CofigAsset(TEXT("ARSessionConfig'/Game/Images/CustomARSessionCOnfig.CustomARSessionConfig'"));
	Config = CofigAsset.Object;
}

// Called when the game starts or when spawned
void ACustomARPawn::BeginPlay()
{
	Super::BeginPlay();
	UKismetSystemLibrary::PrintString(this, FString(TEXT("Hello world")), true, true, FLinearColor(0, 0.66, 1, 1), 5);
	//UARBlueprintLibrary::StartARSession(Config);
	GetWorldTimerManager().SetTimer(cameraTicker, this, &ACustomARPawn::DisplayCameraInfo, cameraNotifyLoopTime, true, 0.0f);
	//SpawnCube();
}

// Called every frame
void ACustomARPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (intialTime >= 2.0f)
	{
		if (scanningForPlanes == true)
		{
			GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, FString::Printf(TEXT("Scan complete")));
			GetWorldTimerManager().SetTimer(scanningTicker, this, &ACustomARPawn::ScanningForPlanes, scanningTime, true, 0.0f);
		}
		else
		{
			FindCandidateImages();
		}
	}
	else
	{
		intialTime += DeltaTime;
		GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, FString::Printf(TEXT("Please stay still while we scan surrondings")));
	}
}

// Called to bind functionality to input
void ACustomARPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindTouch(IE_Pressed, this, &ACustomARPawn::OnScreenTouch);
}

void ACustomARPawn::DisplayCameraInfo()
{
	FVector camLoc;
	FRotator camRot;

	UGameplayStatics::GetPlayerCameraManager(GetWorld(), 0)->GetCameraViewPoint(camLoc, camRot);

	FVector camOri = camRot.Vector();

	UKismetSystemLibrary::PrintString(this, FString::Printf(TEXT("Camera orientation: (%f, %f, %f)"), camOri.X, camOri.Y, camOri.Z), true, true, FLinearColor(0, 0.66, 1, 1), 5);
}

void ACustomARPawn::OnScreenTouch(const ETouchIndex::Type fingerIndex, const FVector screenPos)
{
	//Get the player controller
	APlayerController* playerCOntroller = UGameplayStatics::GetPlayerController(this, 0);
	//Temporary hit test result object
	FHitResult hitTestResult;

	//prefrom a hittest, get the return values as hitTestResults
	if (!WorldHitTest(FVector2D(screenPos), hitTestResult))
	{
		//HitTest returned false get out
		UKismetSystemLibrary::PrintString(this, "Nothing pressed", true, true, FLinearColor(0, 0.66, 1, 1), 2);
		return;
	}

	//Get object of actor hit.
	UClass* hitActorClass = UGameplayStatics::GetObjectClass(hitTestResult.GetActor());

	//if we hit a target
	if (UKismetMathLibrary::ClassIsChildOf(hitActorClass, ACustomARActor::StaticClass()))
	{
		UKismetSystemLibrary::PrintString(this, "Cube clicked!", true, true, FLinearColor(0, 0.66, 1, 1), 2);

	}
}

bool ACustomARPawn::WorldHitTest(const FVector2D touchPos, FHitResult hitResult)
{
	//Get player controller
	APlayerController* playerController = UGameplayStatics::GetPlayerController(this, 0);

	//Perfrom deprojection taking 2D clicked area and generating refrence in 3D world space.
	FVector worldPosition;
	FVector worldDirection;
	bool deprojectionSuccess = UGameplayStatics::DeprojectScreenToWorld(playerController, touchPos, worldPosition, worldDirection);
	//construct trace vector (from point clicked to 1000.0 units beyond in the same direction)
	FVector traceVector = worldDirection * 1000.0;
	traceVector = worldPosition + traceVector;

	//perfrom line trace
	bool traceSuccess = GetWorld()->LineTraceSingleByChannel(hitResult, worldPosition, traceVector, ECollisionChannel::ECC_WorldDynamic);

	return traceSuccess;
}

void ACustomARPawn::SpawnCube()
{
	FActorSpawnParameters SpawnInfo;
	FRotator myRot(0, 0, 0);
	FVector myLoc(900, 0, 0);
	customActor = GetWorld()->SpawnActor<ACustomARActor>(myLoc, myRot, SpawnInfo);
}

void ACustomARPawn::FindCandidateImages()
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
					SpawnCube();
					bGoghFound = true;
				}
				auto Tf = trackedImage->GetLocalToTrackingTransform();
				// Setting the scale to the transform. this can be done using matrices too.
				Tf.SetScale3D(FVector(0.1f));
				customActor->SetActorTransform(Tf);
				FVector SpawnLoc = Tf.GetLocation();
				GEngine->AddOnScreenDebugMessage(-1, 0, FColor::Red, FString::Printf(TEXT("%f, %f, %f"), SpawnLoc.X, SpawnLoc.Y, SpawnLoc.Z));
			}
	}
}

void ACustomARPawn::ScanningForPlanes()
{

}

