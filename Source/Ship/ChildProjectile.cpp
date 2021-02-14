// Fill out your copyright notice in the Description page of Project Settings.


#include "ChildProjectile.h"

AChildProjectile::AChildProjectile()
{
	OnActorBeginOverlap.AddDynamic(this, &AChildProjectile::OnOverlap);
}

void AChildProjectile::OnOverlap(AActor * OtherActor, AActor * OverlappedActor)
{
	if (Cast<APlayerShip>(PlayerShip) != nullptr)
	{
		Destroy();
	}
}
