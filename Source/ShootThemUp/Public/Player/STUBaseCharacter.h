// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/STUHealthComponent.h"
#include "Components/STUWeaponComponent.h"
#include "Components/TextRenderComponent.h"
#include "STUBaseCharacter.generated.h"

class UTextRenderComponent;
class ASTUBaseWeapon;

UCLASS()
class SHOOTTHEMUP_API ASTUBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASTUBaseCharacter(const FObjectInitializer& ObjInit);

protected:
	// Called when the game starts or when spawned
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	UCameraComponent* CameraComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	USpringArmComponent* SpringArmComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	USTUHealthComponent* HealthComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	USTUWeaponComponent* WeaponComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Components")
	UTextRenderComponent* HealthTextComponent;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Movement")
	bool bIsJumping = false;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	bool IsRunning() const;

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float  GetDirection() const;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FVector2D LandedDamageVelocity = FVector2D(900.0f, 1200.0f);

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
	FVector2D LandedDamage = FVector2D(20.0f, 100.0f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
	UAnimMontage* DeathAnimMontage;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	virtual void OnDeath();

private:
	bool ReadyToRun = false;
	bool IsMovingForward = false;

	void MoveForward(float Amount);
	void MoveRight(float Amount);

	void OnStartRunning();
	void OnStopRunning();

	UFUNCTION()
	void OnHealthChanged(float Health, float HealthDelta);

	UFUNCTION()
	void OnGroundLanded(const FHitResult& Hit);

};
