// Fill out your copyright notice in the Description page of Project Settings.


#include "RoundBot.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ARoundBot::ARoundBot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(150);
	Sphere->SetHiddenInGame(false);
	Sphere->SetupAttachment(RootComponent);

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Sphere);
	Mesh->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void ARoundBot::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ARoundBot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


