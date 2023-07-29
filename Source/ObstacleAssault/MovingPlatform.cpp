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
	
	//move platform forward
		// get current location 
		FVector currentLocation = GetActorLocation();
		currentLocation = currentLocation + platformVelocity * DeltaTime;
		//set the location
		SetActorLocation(currentLocation);
	//send platform back if gone too far
		//check how far we've moved 
		float distance = FVector::Dist(startLocation, currentLocation);
		//reverse direction of motion if gone too far. 
		if(distance > distanceMoved)
		{
			platformVelocity = -platformVelocity;
			startLocation = currentLocation;
		}

}

