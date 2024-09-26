// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "STUBaseWeapon.h"
#include "STULauncherWeapon.generated.h"

class ASTUProjectile;

UCLASS()
class SHOOTTHEMUP_API ASTULauncherWeapon : public ASTUBaseWeapon
{
	GENERATED_BODY()

public:
	virtual void StartFire() override;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TSubclassOf<ASTUProjectile> ProjectileClass;

protected:
	virtual void MakeShot() override;

};
