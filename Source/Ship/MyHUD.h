// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ShipGameInstance.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/HUD.h"
#include "MyHUD.generated.h"

/**
 * 
 */
UCLASS()
class SHIP_API AMyHUD : public AHUD
{
	GENERATED_BODY()
	
public:
	virtual void DrawHUD() override;

	UPROPERTY(EditAnywhere, Category = "HUDFont")
		UFont* HudFont;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Score")
		int Score;

	bool GameOver = false;

};
