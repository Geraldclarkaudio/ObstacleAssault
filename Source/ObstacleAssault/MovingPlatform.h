// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingPlatform();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private: 
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	FVector platformVelocity = FVector(100,0,0);
	UPROPERTY(EditAnywhere, Category = "Moving Platform")
	float distanceMoved = 100;
	UPROPERTY(EditAnywhere, Category = "Rotation")
	FRotator rotationVelocity;
	
	FVector startLocation;

	void MovePlatform(float deltaTime);
	void RotatePlatform(float deltaTime);

	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};
