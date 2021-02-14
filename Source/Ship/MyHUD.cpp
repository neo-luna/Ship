// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"

void AMyHUD::DrawHUD()
{
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	UShipGameInstance*ShipGameInstance = Cast<UShipGameInstance>(GameInstance);

	DrawText("You Score: " + FString::FromInt(Score), FColor::Blue, 10, 10, HudFont, 2.f);

	Score = ShipGameInstance->GIScore;
}


