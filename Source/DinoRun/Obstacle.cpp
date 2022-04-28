// Fill out your copyright notice in the Description page of Project Settings.


#include "Obstacle.h"
FVector position;

// Sets default values
AObstacle::AObstacle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AObstacle::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AObstacle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	position = GetActorLocation();
	SetActorLocation(FVector(0, position.Y-5, position.Z), false, nullptr, ETeleportType::None);
}

