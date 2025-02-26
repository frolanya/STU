// Fill out your copyright notice in the Description page of Project Settings.


#include "AI/STUAIController.h"
#include "AI/STUAICharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Components/STUAIPerceptionComponent.h"

ASTUAIController::ASTUAIController()
{
	STUAIPerceptionComponent = CreateDefaultSubobject<USTUAIPerceptionComponent>("STUPerceptionComponent");
	SetPerceptionComponent(*STUAIPerceptionComponent);
}

void ASTUAIController::OnPossess(APawn* InPawn) 
{
	Super::OnPossess(InPawn);

	const auto STUCharacter = Cast<ASTUAICharacter>(InPawn);
	if (STUCharacter)
	{
		RunBehaviorTree(STUCharacter->BehaviorTreeAsset);
	}

}

void ASTUAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const auto AimActor = GetFocusOnActor();
	SetFocus(AimActor);

	
}

AActor* ASTUAIController::GetFocusOnActor() const
{
	if (!GetBlackboardComponent())
	{
		return nullptr;
	}
	return Cast<AActor>(GetBlackboardComponent()->GetValueAsObject(FocusOnKeyName));

}