// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrack.generated.h"

class ASprungWheel;

/**
 * TankTrack is used to set maximum driving force, and to apply forces to the tank
 */
UCLASS( meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankTrack : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	UTankTrack();

	// Sets throttle between -1 and +1
	UFUNCTION(BlueprintCallable, Category="Input")
	void SetThrottle(float Throttle);

private:
	void DriveTrack(float CurrentThrottle);

	TArray<ASprungWheel *> GetWheels() const;

	// Max force per track, in kg cm /(s^2)
	UPROPERTY(EditDefaultsOnly)
	float TrackMaxDrivingForce = 90000000.0f;
};
