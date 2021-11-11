// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyCube.h"

// Sets default values
AEnemyCube::AEnemyCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	StaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> cubeAsset(TEXT("D:/LocalWorkDir/1502095/ARLabs/Content/MobileStarterContent/Shapes/Shape_Cube.uasset"));
	StaticMeshComponent->SetStaticMesh(cubeAsset.Object);
	StaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMeshComponent->SetWorldScale3D(FVector(1.0f));
}

// Called when the game starts or when spawned
void AEnemyCube::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEnemyCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

