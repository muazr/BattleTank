// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PhysicsEngine/PhysicsConstraintComponent.h"
#include "Components/SphereComponent.h"
#include "SprungWheel.generated.h"

UCLASS()
class BATTLETANK_API ASprungWheel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASprungWheel();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void AddDrivingForce(float ForceMagnitude);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:
	void SetupConstraint();

	UPROPERTY(VisibleAnywhere, Category="Components")
	UPhysicsConstraintComponent *SpringConstraint = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent *Axle = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UPhysicsConstraintComponent *AxleWheelConstraint = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Components")
	USphereComponent *Wheel = nullptr;
};
