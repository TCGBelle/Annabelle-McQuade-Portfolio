// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <Runtime/Engine/Classes/Components/BoxComponent.h>
#include "ARGate.generated.h"


UCLASS()
class ARCOURCEWORK_API AARGate : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARGate();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(Category = "Root", VisibleAnywhere, BlueprintReadWrite)
		USceneComponent* SceneComponent;
	UPROPERTY(Category = "MeshCatagorey", VisibleAnywhere, BlueprintReadWrite)
		UStaticMeshComponent* StaticMeshComponent;
	UPROPERTY(Category = "TriggerCatagorey", VisibleAnywhere, BlueprintReadWrite)
		UBoxComponent* BoxCollision;
	UPROPERTY(Category = "Location", BlueprintReadWrite) FVector Location;
};
