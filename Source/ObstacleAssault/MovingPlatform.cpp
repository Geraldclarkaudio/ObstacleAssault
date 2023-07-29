// Fill out your copyright notice in the Description page of Project Settings.

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	startLocation = GetActorLocation();
}

// Called every frame
void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	MovePlatform(DeltaTime);
	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float deltaTime)
{
	FVector currentLocation = GetActorLocation();
	
	currentLocation = currentLocation + platformVelocity * deltaTime;
	
	SetActorLocation(currentLocation);
	
	float distance = FVector::Dist(startLocation, currentLocation);

	if(distance > distanceMoved)
	{
		FVector moveDirection = platformVelocity.GetSafeNormal();
		startLocation = startLocation + moveDirection * distance;
		SetActorLocation(startLocation);
		platformVelocity = -platformVelocity;
	}
}

void AMovingPlatform::RotatePlatform(float deltaTime)
{
	UE_LOG(LogTemp, Display, TEXT("Rotate"));
}


