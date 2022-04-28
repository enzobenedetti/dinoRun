// Fill out your copyright notice in the Description page of Project Settings.


#include "Dinomovement.h"
bool isJumping = false;
bool isCrouching = false;
float timeInAir = 1;
float timer = 0;

// Sets default values
ADinomovement::ADinomovement()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AutoPossessPlayer = EAutoReceiveInput::Player0;
}

// Called when the game starts or when spawned
void ADinomovement::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADinomovement::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	{
		if (isJumping) {
			SetActorLocation(FVector(0, 0, 100), false, nullptr, ETeleportType::None);
			timer += DeltaTime;
			if (timer >= timeInAir) {
				timer = 0;
				isJumping = false;
			}
		}
		else if (isCrouching)
		{
			SetActorLocation(FVector(0, 0, -30), false, nullptr, ETeleportType::None);
			SetActorScale3D(FVector(1, 1, 0.5));
			timer += DeltaTime;
			if (timer >= timeInAir) {
				timer = 0;
				isCrouching = false;
			}
		}
		else
		{
			SetActorLocation(FVector(0, 0, 0), false, nullptr, ETeleportType::None);
			SetActorScale3D(FVector(1, 1, 1));
		}
	}
}

// Called to bind functionality to input
void ADinomovement::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	InputComponent->BindAction("Jump",	IE_Pressed, this, &ADinomovement::Jump);
	InputComponent->BindAction("Crouch", IE_Pressed, this, &ADinomovement::Crouch);
}

void ADinomovement::Jump()
{
	if (!isCrouching)
	isJumping = true;
}

void ADinomovement::Crouch()
{
	if (!isJumping)
	isCrouching = true;
}
