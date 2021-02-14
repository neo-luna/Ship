// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/CapsuleComponent.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/Actor.h"
#include "Projectile.generated.h"

UCLASS()
class SHIP_API AProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjectile();

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

	/* Scale logic*/
	FTimerHandle ScaleHandle;

	float ScaleVal = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerSettings")
		float ScaleTime;

	/* Scale function*/
	void ScaleFunction();

	/* Destroy logic*/
	FTimerHandle DestroyHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimerSettings")
		float DestroyTime;

	/* Destroy after time*/
	void DestroyFunction();
};
