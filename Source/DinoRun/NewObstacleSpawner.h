// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NewObstacleSpawner.generated.h"

UCLASS()
class DINORUN_API ANewObstacleSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ANewObstacleSpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, meta = (AllowPrivateAcces = "true"))
	TSubclassOf<AActor> ActorToSpawn;
};
