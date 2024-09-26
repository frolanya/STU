// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/STUGameHUD.h"
#include "Engine/Canvas.h"
#include "Blueprint/UserWidget.h"

void ASTUGameHUD::DrawHUD()
{
	Super::DrawHUD();

	//DrawCrosshair();
}

void ASTUGameHUD::BeginPlay()
{
	Super::BeginPlay();
	
	auto PlayerHUDWidget = CreateWidget<UUserWidget>(GetWorld(), PlayerHUDWidgetClass);
	if (PlayerHUDWidget)
	{
		PlayerHUDWidget->AddToViewport();
	}
}

void ASTUGameHUD::DrawCrosshair()
{
	/*int32 SizeX = Canvas->SizeX;
	int32 SizeY = Canvas->SizeY;
	const TInterval<float> Center(SizeX * 0.5f, SizeY * 0.5f);

	const float HalfLineSize = 10.0f;
	const float LineThickness = 2.0f;
	const FLinearColor Color = FLinearColor::Green;

	DrawLine(Center.Min - HalfLineSize, Center.Min + HalfLineSize,
		Center.Max - HalfLineSize, Center.Max + HalfLineSize,
		Color, LineThickness);*/

	const FVector2D Center(Canvas->SizeX * 0.5f, Canvas->SizeY * 0.5f);
	const float HalfLineSize = 10.0f;
	const float LineThickness = 2.0f;
	const FLinearColor Color = FLinearColor::Green;

	// 1-st design of crosshair
	/*DrawLine(Center.X - HalfLineSize, Center.Y,
		Center.X + HalfLineSize, Center.Y,
		Color, LineThickness);
	DrawLine(Center.X, Center.Y - HalfLineSize,
		Center.X, Center.Y + HalfLineSize,
		Color, LineThickness);*/

		// 2-nd design of crosshair
	DrawLine(Center.X - 2.0f * HalfLineSize, Center.Y,
		Center.X - HalfLineSize, Center.Y,
		Color, LineThickness);
	DrawLine(Center.X + 2.0f * HalfLineSize, Center.Y,
		Center.X + HalfLineSize, Center.Y,
		Color, LineThickness);

	DrawLine(Center.X, Center.Y - 2.0f * HalfLineSize,
		Center.X, Center.Y - HalfLineSize,
		Color, LineThickness);
	DrawLine(Center.X, Center.Y + 2.0f * HalfLineSize,
		Center.X, Center.Y + HalfLineSize,
		Color, LineThickness);
}
