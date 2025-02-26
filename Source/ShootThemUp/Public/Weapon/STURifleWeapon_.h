// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "STUBaseWeapon.h"
#include "STURifleWeapon_.generated.h"


class USTU_WeaponFXComponent;
class UNiagaraComponent;
class UNiagaraSystem;

UCLASS()
class SHOOTTHEMUP_API ASTURifleWeapon_ : public ASTUBaseWeapon
{
	GENERATED_BODY()
	
public:
	virtual void StartFire() override;
	virtual void StopFire() override;

	ASTURifleWeapon_();
protected:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float TimeBetweenShots = 0.1f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float BulletSpread = 2.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	float DamageAmount = 10.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	USTU_WeaponFXComponent* WeaponFXComponent;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	UNiagaraSystem* TraceFX;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "VFX")
	FString TraceTargetName = "TraceTarget";

	virtual void MakeShot() override;
	bool GetTraceData(FVector& TraceStart, FVector& TraceEnd) const override;

	virtual void BeginPlay() override;
private:
	FTimerHandle ShotTimerHandle;

	void MakeDamage(const FHitResult& HitResult);

	void InitMuzzleFX();
	void SetMuzzleFXVisibility(bool Visible);
	void SpawnTraceFX(const FVector& TraceStart, const FVector& TraceEnd);

	UPROPERTY()
	UNiagaraComponent* MuzzleFXComponent;
};
