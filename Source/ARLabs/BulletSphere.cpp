// Fill out your copyright notice in the Description page of Project Settings.


#include "BulletSphere.h"
#include "UObject/ConstructorHelpers.h"

// Sets default values
ABulletSphere::ABulletSphere()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	StaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> sphereAsset(TEXT("D:/LocalWorkDir/1502095/ARLabs/Content/MobileStarterContent/Shapes/Shape_Sphere.uasset"));
	StaticMeshComponent->SetStaticMesh(sphereAsset.Object);
	StaticMeshComponent->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));
	StaticMeshComponent->SetWorldScale3D(FVector(1.0f));
}

// Called when the game starts or when spawned
void ABulletSphere::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABulletSphere::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

