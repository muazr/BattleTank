// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimingComponent.generated.h"

class UTankBarrel;
class UTankTurret;

UENUM()
enum class EFiringStatus : uint8
{
	Reloading,
	Aiming,
	Locked,
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLETANK_API UTankAimingComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimingComponent();

	UFUNCTION(BlueprintCallable, Category="Setup")
	void Initialize(UTankTurret *TurretToSet, UTankBarrel *BarrelToSet);

	void AimAt(const FVector &HitLocation, float LaunchSpeed);

protected:
	UPROPERTY(BlueprintReadOnly, Category="State")
	EFiringStatus FiringStatus = EFiringStatus::Aiming;

private:
	void MoveBarrelTowards(const FVector &AimDirection);

	UTankBarrel *Barrel = nullptr;
	UTankTurret *Turret = nullptr;

};
