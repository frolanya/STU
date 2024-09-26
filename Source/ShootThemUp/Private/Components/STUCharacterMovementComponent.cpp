// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/STUCharacterMovementComponent.h"
#include "Player/STUBaseCharacter.h"

float USTUCharacterMovementComponent::GetMaxSpeed() const
{
	float MaxSpeed = Super::GetMaxSpeed();
	ASTUBaseCharacter* Player = Cast<ASTUBaseCharacter>(GetPawnOwner());
	if (Player && Player->IsRunning()) 
		return MaxSpeed * 2.0;
	return MaxSpeed;
}

