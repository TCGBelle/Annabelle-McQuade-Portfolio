// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomARActor.h"

// Sets default values
ACustomARActor::ACustomARActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	StaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/MobileStarterContent/Shapes/Shape_Cube.Shape_Cube'"));
	StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	SetRootComponent(SceneComponent);
	initLocation = GetActorLocation();
	t = 0;
}

// Called when the game starts or when spawned
void ACustomARActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomARActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*Location = GetActorLocation();
	float WorldTime = GetWorld()->GetRealTimeSeconds();
	float Scale = 2 / (3 - cos(2 * WorldTime));
	Location.X = (Scale * cos(WorldTime));
	Location.Y = (Scale * sin(2 * WorldTime) / 2);

	SetActorLocation(Location);*/

	t += DeltaTime;
	double x, y;
	double scale = 2 / (3 - cos(2 * t));
	x = scale * cos(t);
	y = scale * sin(2 * t) / 2;

	FVector relativeLoc = FVector4(0, x * 100, y * 100);

	/*	1	0	0	0
		0	1	0	0
		0	0	1	0
		X	Y	Z	1*/

		//set locald Translation Mtrix
		FMatrix mat_local = FMatrix::Identity;
		mat_local.M[3][0] = relativeLoc.X;
		mat_local.M[3][1] = relativeLoc.Y;
		mat_local.M[3][2] = relativeLoc.Z;
		FMatrix mat_init;
		mat_init = FMatrix::Identity;
		mat_init.M[3][0] = initLocation.X;
		mat_init.M[3][1] = initLocation.Y;
		mat_init.M[3][2] = initLocation.Z;
		auto mat_final = mat_local*mat_init;
		SetActorTransform(FTransform(mat_final));
}

