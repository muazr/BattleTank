// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrack.h"
#include "SprungWheel.h"
#include "SpawnPoint.h"

UTankTrack::UTankTrack()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrack::SetThrottle(float Throttle)
{
	float CurrentThrottle = FMath::Clamp<float>(Throttle, -1.0f, 1.0f);
	DriveTrack(CurrentThrottle);
}

void UTankTrack::DriveTrack(float CurrentThrottle)
{
	float ForceApplied = CurrentThrottle * TrackMaxDrivingForce;
	auto Wheels = GetWheels();

	if (!ensure(Wheels.Num() > 0)) return;
	float ForcePerWheel = ForceApplied / Wheels.Num();

	for (ASprungWheel *Wheel : Wheels)
	{
		Wheel->AddDrivingForce(ForcePerWheel);
	}
}

TArray<ASprungWheel*> UTankTrack::GetWheels() const
{
	TArray<USceneComponent *> Children;
	GetChildrenComponents(true, Children);

	TArray<ASprungWheel *> Wheels;

	for (USceneComponent *Child : Children)
	{
			auto SpawnPoint = Cast<USpawnPoint>(Child);
			if (!SpawnPoint) continue;

			ASprungWheel *Wheel = SpawnPoint->GetSpawnedWheel();
			if (!Wheel) continue;

			Wheels.Add(Wheel);
	}

	return Wheels;
}
