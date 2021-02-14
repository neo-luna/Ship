// Fill out your copyright notice in the Description page of Project Settings.


#include "ShipGameInstance.h"

UShipGameInstance::UShipGameInstance(const FObjectInitializer & ObjectInitializer)
{
	GIScore = 0;
}

void UShipGameInstance::Init()
{
	
	GEngine->AddOnScreenDebugMessage(0, 1, FColor::Blue, FString::FromInt(GIScore));

	if (GIScore == 2)
	{
		
		UGameplayStatics::OpenLevel(this, "LevelTwo", true);
	}
	if (GIScore == 3)
	{
		UGameplayStatics::OpenLevel(this, "LevelThree", true);
	}
	if (GIScore == 4)
	{
		UGameplayStatics::OpenLevel(this, "LevelFour", true);
	}
	if (GIScore == 5)
	{
		WinFunction();
		MyFunction();
	}
}

//Вызывается в BP, если GIScore равен N
void UShipGameInstance::WinFunction_Implementation() 
{
	//GEngine->AddOnScreenDebugMessage(0, 1, FColor::Green, TEXT("YOU WIN"));
	
}

/*void UShipGameInstance::TestFunction()
{

}*/







