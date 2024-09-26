// Fill out your copyright notice in the Description page of Project Settings.


#include "Components/STUHealthComponent.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/Controller.h"
#include "Camera/CameraShakeBase.h"
#include "TimerManager.h"
#include "STUFireDamageType.h"
#include "STUIceDamageType.h"

// Sets default values for this component's properties
USTUHealthComponent::USTUHealthComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}


bool USTUHealthComponent::IsDead() const
{
	return Health <= 0;
}

// Called when the game starts
void USTUHealthComponent::BeginPlay()
{
	Super::BeginPlay();

	check(MaxHealth > 0);

	SetHealth(MaxHealth);

	AActor* ComponentOwner = GetOwner();
	if (ComponentOwner)
	{
		ComponentOwner->OnTakeAnyDamage.AddDynamic(this, &USTUHealthComponent::OnTakeAnyDamage);
	}
}

float USTUHealthComponent::GetHealth() const
{
	return Health;
}

float USTUHealthComponent::GetHealthPercentage() const
{
	return Health / MaxHealth;
}


void USTUHealthComponent::SetHealth(float NewHealth)
{
	const auto NextHealth = FMath::Clamp(NewHealth, 0.0f, MaxHealth);
	const auto HealthDelta = NextHealth - Health;

	Health = NextHealth;
	OnHealthChanged.Broadcast(Health, HealthDelta);
}

void USTUHealthComponent::OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser)
{
	if (Damage <= 0 || IsDead() || !GetWorld()) return;

	SetHealth(Health - Damage);;

	GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	if (IsDead())
	{
		OnDeath.Broadcast();
	}

	if (IsActiveHeal)
	{
		GetWorld()->GetTimerManager().SetTimer(HealTimerHandle, this, &USTUHealthComponent::Heal, HealInterval, true, HealDelay);
	}
	if (DamageType)
	{
		if (DamageType->IsA<USTUFireDamageType>())
		{
			UE_LOG(LogTemp, Warning, TEXT("FIRE Damage!"));
		}
		else if (DamageType->IsA<USTUIceDamageType>())
		{
			UE_LOG(LogTemp, Warning, TEXT("ICE Damage!"));
		}
	}
	PlayCameraShake();
}
void USTUHealthComponent::Heal()
{

	SetHealth(Health+HealRate);

	if (FMath::IsNearlyEqual(Health,MaxHealth))
	{
		GetWorld()->GetTimerManager().ClearTimer(HealTimerHandle);
	}
}
bool USTUHealthComponent::TryToAddHealth(float HealthAmount)
{
	if (IsDead() || FMath::IsNearlyEqual(Health, MaxHealth))
	{
		return false;
	}

	SetHealth(Health + HealthAmount);
	return true;
}
void USTUHealthComponent::PlayCameraShake()
{
	if (IsDead()) return;

	auto Player = Cast<APawn>(GetOwner());
	if (!Player) return;

	auto Controller = Player->GetController<APlayerController>();
	if (!Controller || !Controller->PlayerCameraManager) return;

	Controller->PlayerCameraManager->StartCameraShake(CameraShake);
}