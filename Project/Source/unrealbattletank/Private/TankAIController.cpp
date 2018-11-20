// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"




void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto controllerdTank = GetControlledTank();
	if (!controllerdTank) {
		UE_LOG(LogTemp, Warning, TEXT("Player Controller not possesing a Tank"))
	}
	else
		UE_LOG(LogTemp, Warning, TEXT("Playre Begin Player Controller Tank %s "), *(controllerdTank->GetName()))
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}


ATank* ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn = GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn)
		return nullptr;

	return Cast<ATank>(PlayerPawn);
}


