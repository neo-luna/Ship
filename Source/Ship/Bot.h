// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PlayerShip.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"
#include "GameFramework/Actor.h"
#include "Bot.generated.h"

UCLASS()
class SHIP_API ABot : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABot();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bot")
		class USphereComponent*Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bot")
		class UStaticMeshComponent*Mesh;

	UPROPERTY(EditAnywhere, Category = "Projectile")
		UClass*BP_Projectile;

	FRotator FLAR;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timer")
		FRotator BotRotation;

	FTimerHandle HandleFire;

	/* Интервал стрельбы*/
	UPROPERTY(EditAnywhere, Category = "Timer")
		float TimeFire;

	/* Задержка начала стрельбы*/
	UPROPERTY(EditAnywhere, Category = "Timer")
		float TimeDelay;

	FVector PlayerLocation;

	FVector ToPlayer;

	float DistanceToPlayer;

	void Move();

	void Fire();

	float ValRotation;

	/* Массив Projectiles*/
	class AProjectile* Projectile;

	TArray<AProjectile*> Projectiles;

	bool bMoveFactor;

};
