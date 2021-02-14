// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.h"
#include "EnemyProjectile.h"
#include "MyHUD.h"
#include "PlayerShip.h"
#include "GameFramework/Actor.h"
#include "EnemyShip.generated.h"

UCLASS()
class SHIP_API AEnemyShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemyShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyShip")
		USphereComponent*Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyShip")
		UStaticMeshComponent*Mesh;

	UFUNCTION()
		// Bullet hit in EnemyShip
		void ProjectileOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyShip")
		UClass* BP_EnemyProjectile;

	// Quantity of Enemy
	int Quantity;

	class APlayerShip* PlayerShip;

	//FVector PlayerShipLocation;

	// Event after die EnemyShip
	virtual void EndPlay(EEndPlayReason::Type EndPlayReason ) override;

	FVector ActorLocation;

	void Fire();

	bool Track;

	void Move();

	//int32 NumPawns;

	/* Timer*/
	/*FTimerHandle Handle;

	float Time;

	float TimeToDisplay;*/

	class AProjectile*Projectile;

	FVector ProjLoc;

	float CurrentYawSpeed = 5;

	float TargetYawSpeed = 3;

	float ValRotation;
};
