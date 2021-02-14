// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerShip.h"
#include "Projectile.h"
#include "ChildProjectile.generated.h"

/* ��������� ����������� PlayerShip ��� Enemy*/
UCLASS()
class SHIP_API AChildProjectile : public AProjectile
{
	GENERATED_BODY()

public:
	AChildProjectile();

	class APlayerShip*PlayerShip;

	UFUNCTION()
		void OnOverlap(AActor* OtherActor, AActor* OverlappedActor);
};
