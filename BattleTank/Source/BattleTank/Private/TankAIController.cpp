// Fill out your copyright notice in the Description page of Project Settings.


#include "TankAIController.h"
#include "TankAimingComponent.h"
#include "Tank.h"
#include "Engine/World.h"
#include "GameFramework/PlayerController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();

}

void ATankAIController::SetPawn(APawn *InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		auto PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) return;

		// Subscribe our local method to the tank's death event
		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	APawn *PlayerTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	APawn *ControlledTank = GetPawn();
	if (!(PlayerTank && ControlledTank)) return;

	// Move towards the player
	MoveToActor(PlayerTank, AcceptanceRadius);

	auto AimingComponent = ControlledTank->FindComponentByClass<UTankAimingComponent>();
	if (!ensure(AimingComponent)) return;

	AimingComponent->AimAt(PlayerTank->GetActorLocation());

	if (AimingComponent->GetFiringState() == EFiringState::Locked)
	{
		AimingComponent->Fire();
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	APawn *PossessedTank = GetPawn();
	if (!ensure(PossessedTank)) return;

	PossessedTank->DetachFromControllerPendingDestroy();
}
