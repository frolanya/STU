// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "STUProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class USTU_WeaponFXComponent;

UCLASS()
class SHOOTTHEMUP_API ASTUProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASTUProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = "Weapon")
	UProjectileMovementComponent* MovementComponent;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	float DamageRadius = 200.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	float DamageAmount = 50.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	bool DoFullDamage = false;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Weapon")
	float LifeSeconds = 5.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	USTU_WeaponFXComponent* WeaponFXComponent;

	void SetShotDirection(FVector Direction);

private:
	FVector ShotDirection;

	UFUNCTION()
	void OnProjectileHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	AController* GetController() const;
};
