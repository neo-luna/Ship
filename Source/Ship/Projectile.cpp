// Fill out your copyright notice in the Description page of Project Settings.


#include "Projectile.h"

// Sets default values
AProjectile::AProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<UCapsuleComponent>(TEXT("Sphere"));
	Sphere->SetHiddenInGame(false);
	RootComponent = Sphere;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Sphere);

}

// Called when the game starts or when spawned
void AProjectile::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(ScaleHandle, this, &AProjectile::ScaleFunction, ScaleTime, true);

	GetWorldTimerManager().SetTimer(DestroyHandle, this, &AProjectile::DestroyFunction, DestroyTime, true);
}

// Called every frame
void AProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	SetActorLocation(GetActorLocation()+GetActorForwardVector()*3);
}

void AProjectile::ScaleFunction()
{
	ScaleVal -= 0.01;

	SetActorScale3D(FVector(ScaleVal, ScaleVal, ScaleVal));
}

void AProjectile::DestroyFunction()
{
	Destroy();
}

