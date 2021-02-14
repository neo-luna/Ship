// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnemyShip.h"
#include "Engine/GameInstance.h"
#include "ShipGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SHIP_API UShipGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	UShipGameInstance(const FObjectInitializer & ObjectInitializer);

	virtual void Init() override;

	UPROPERTY(BlueprintReadWrite)
		int GIScore;

	UFUNCTION(BlueprintNativeEvent)
		void WinFunction();

	UFUNCTION(BlueprintImplementableEvent)
		//TArray<FString> GetListWeapon();
		void MyFunction();
	

	
};
