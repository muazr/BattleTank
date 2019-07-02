// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "Projectile.generated.h"

UCLASS()
class BATTLETANK_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void LaunchProjectile(float Speed);

private:
	UFUNCTION()
	void OnHit(UPrimitiveComponent *HitComponent, AActor *OtherActor, UPrimitiveComponent *OtherComp, FVector NormalImpulse, const FHitResult &Hit);

	UPROPERTY(VisibleAnywhere, Category="Components")
	UStaticMeshComponent *CollisionMesh = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UParticleSystemComponent *LaunchBlast = nullptr;

	UPROPERTY(VisibleAnywhere, Category="Components")
	UParticleSystemComponent *ImpactBlast = nullptr;

	UProjectileMovementComponent *ProjectileMovement = nullptr;
};
