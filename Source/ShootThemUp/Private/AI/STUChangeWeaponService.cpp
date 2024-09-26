// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/STUChangeWeaponService.h"
#include "Components/STUWeaponComponent.h"
#include "STUUtils.h"
#include "STUAIController.h"


USTUChangeWeaponService::USTUChangeWeaponService()
{
	NodeName = "Change Weapon";
}


void USTUChangeWeaponService::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	const auto Controller = OwnerComp.GetAIOwner();
	if (Controller)
	{
		const auto WeaponComponent = STUUtils::GetSTUPlayerComponent<USTUWeaponComponent>(Controller->GetPawn());
		if (WeaponComponent && Probability > 0 && FMath::FRand() < Probability)
		{
			WeaponComponent->NextWeapon();
		}
	}
}
