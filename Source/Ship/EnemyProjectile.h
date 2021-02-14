// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "EnemyShip.h"
#include "GameFramework/Actor.h"
#include "EnemyProjectile.generated.h"

UCLASS()
class SHIP_API AEnemyProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyProjectile();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		UCapsuleComponent*Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		UStaticMeshComponent*Mesh;

	// Projectile speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ProjectileSettings")
		float ProjectileSpeed;

	class AEnemyShip*EnemyShip;

	//FVector ActorLocation;

	/*Самоликвидация по истечении времени*/
	void DestroyProjectile();

	FTimerHandle Handle;

	UPROPERTY(EditAnywhere, Category = "Timer")
		float Time;

};
