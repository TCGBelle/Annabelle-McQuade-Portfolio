// Fill out your copyright notice in the Description page of Project Settings.


#include "CustomArPlane.h"

// Sets default values
ACustomArPlane::ACustomArPlane()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	SetRootComponent(SceneComponent);
	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	StaticMeshComponent->AttachToComponent(SceneComponent, FAttachmentTransformRules::KeepRelativeTransform);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("StaticMesh'/Game/MobileStarterContent/Shapes/Shape_Plane.Shape_Plane'"));
	BaseMaterial = CreateDefaultSubobject<UMaterialInterface>("Base");
	SelectedMaterial = CreateDefaultSubobject<UMaterialInterface>("Selected");
	Selected = false;

}

// Called when the game starts or when spawned
void ACustomArPlane::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACustomArPlane::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (Selected == true)
	{
		StaticMeshComponent->SetMaterial(0, BaseMaterial);
	}
	else
	{
		StaticMeshComponent->SetMaterial(0, SelectedMaterial);
	}
}

