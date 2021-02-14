// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyProjectile.h"

// Sets default values
AEnemyProjectile::AEnemyProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Sphere"));
	Sphere->SetHiddenInGame(false);
	RootComponent = Sphere;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	//Mesh->SetSimulatePhysics(true);
	//Mesh->SetEnableGravity(false);
	Mesh->SetupAttachment(Sphere);
	
	
}

// Called when the game starts or when spawned
void AEnemyProjectile::BeginPlay()
{
	Super::BeginPlay();

	GetWorldTimerManager().SetTimer(Handle, this, &AEnemyProjectile::DestroyProjectile, Time, true);
}

// Called every frame
void AEnemyProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	for (TObjectIterator<AEnemyShip> It; It; ++It)
	{
		EnemyShip = *It;
	}

	// Set direction and speed
	SetActorLocation(GetActorLocation() + (GetActorForwardVector()*ProjectileSpeed));

}

void AEnemyProjectile::DestroyProjectile()
{
	Destroy();
}

