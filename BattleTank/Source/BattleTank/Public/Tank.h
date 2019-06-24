// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimingComponent;
class UTankBarrel;
class UTankTurret;
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

	UTankAimingComponent *TankAimingComponent = nullptr;

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetBarrelReference(UTankBarrel *BarrelToSet);

	UFUNCTION(BlueprintCallable, Category=Setup)
	void SetTurretReference(UTankTurret *TurretToSet);

	void AimAt(const FVector &HitLocation);

	UFUNCTION(BlueprintCallable, Category=Firing)
	void Fire();

private:
	UPROPERTY(EditAnywhere, Category=Firing)
	float LaunchSpeed = 5000.0f;

	UPROPERTY(EditAnywhere, Category=Setup)
	TSubclassOf<AProjectile> ProjectileBlueprint;

	UTankBarrel *Barrel = nullptr;
};
