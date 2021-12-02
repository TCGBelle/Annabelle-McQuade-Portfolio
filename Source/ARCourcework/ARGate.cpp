// Fill out your copyright notice in the Description page of Project Settings.


#include "ARGate.h"

// Sets default values
AARGate::AARGate()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene Component"));
	SetRootComponent(SceneComponent);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	StaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	//make the mesh blueprint.
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/MobileStarterContent/Architecture/Pillar_50x500.Pillar_50x500'"));
	StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	BoxCollision = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Trigger"));
	BoxCollision->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called when the game starts or when spawned
void AARGate::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AARGate::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

