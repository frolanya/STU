// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "STUCoreTypes.h"
#include "STUHealthComponent.generated.h"



UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class SHOOTTHEMUP_API USTUHealthComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	USTUHealthComponent();

	UFUNCTION()
	float GetHealth() const;

	UFUNCTION(BlueprintCallable)
	float GetHealthPercentage() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "0.0", ClampMax = "1000.0"))
	float MaxHealth = 100.0f;

	UFUNCTION(BlueprintCallable)
	bool IsDead() const;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool IsActiveHeal = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealInterval = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float HealDelay = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VFX")
	TSubclassOf<UCameraShakeBase> CameraShake;

	FOnDeath OnDeath;
	FOnHealthChanged OnHealthChanged;
	

	bool TryToAddHealth(float HealthAmount);
protected:
	virtual void BeginPlay() override;

private:
	float Health = 0.0f;

	FTimerHandle HealTimerHandle;

	void SetHealth(float NewHealth);
	UFUNCTION()
	void OnTakeAnyDamage(AActor* DamagedActor, float Damage, const class UDamageType* DamageType, class AController* InstigatedBy, AActor* DamageCauser);

	UFUNCTION()
	void Heal();

	void PlayCameraShake();
};
