// Fill out your copyright notice in the Description page of Project Settings.


#include "NewObstacleSpawner.h"
float timer = 0;
float timeToSpawn = 1.5;

// Sets default values
ANewObstacleSpawner::ANewObstacleSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ANewObstacleSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ANewObstacleSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	timer += DeltaTime;
	if (timer >= timeToSpawn)
	{
		timer = 0;
		GetWorld()->SpawnActor(ActorToSpawn);
	}
}

