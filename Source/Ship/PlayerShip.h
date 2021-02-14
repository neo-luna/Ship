// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Projectile.h"
#include "EnemyShip.h"
#include "EnemyProjectile.h"
#include "ChildProjectile.h"
#include "ShipGameInstance.h"
#include "GameFramework/Pawn.h"
#include "PlayerShip.generated.h"

UCLASS()
class SHIP_API APlayerShip : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerShip();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerShip")
		USphereComponent*Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerShip")
		UStaticMeshComponent*Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerShip")
		UClass* BP_Projectile;

	FVector CurrentVelocity;

	// Movement
	void Strafe(float AxisValue);
	void Forward(float AxisValue);

	// Fire
	void Fire();

	// EnemyShip set damage
	UFUNCTION()
		void EnemyOverlap(AActor* OverlappedActor, AActor* OtherActor);

	virtual void EndPlay(EEndPlayReason::Type EndPlayReason) override;

	class AEnemyShip*EnemyShip;

	void LevelNew();

	class AChildProjectile*ChildProjectile;

	bool bFireOnOff;

	void FireTrue();

	FTimerHandle FireTrueHandle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="TimerSettings")
		float FireTimeTrue;


};
