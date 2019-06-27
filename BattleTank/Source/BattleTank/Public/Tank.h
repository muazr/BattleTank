// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankBarrel;
class AProjectile;

UCLASS()
class BATTLETANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	UFUNCTION(BlueprintCallable, Category="Firing")
	void Fire();

private:
	// Local barrel reference for spawning projectile
	UTankBarrel *Barrel = nullptr; // TODO Remove

	// TODO Remove
	UPROPERTY(EditDefaultsOnly, Category="Firing")
	float LaunchSpeed = 5000.0f;

	UPROPERTY(EditDefaultsOnly, Category="Setup")
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UPROPERTY(EditDefaultsOnly, Category="Firing")
	float ReloadTimeInSeconds = 3.0f;

	UPROPERTY(EditDefaultsOnly, Category="Firing")
	double LastFireTime = 0.0;
};
