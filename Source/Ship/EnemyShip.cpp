// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemyShip.h"
#include "Obstacle.h"
#include "Kismet/KismetSystemLibrary.h"

// Sets default values
AEnemyShip::AEnemyShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->SetHiddenInGame(false);
	RootComponent = Sphere;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Sphere);

	OnActorBeginOverlap.AddDynamic(this, &AEnemyShip::ProjectileOverlap);

	Quantity = 1;

	Track = false;

	ValRotation = 0;
}

// Called when the game starts or when spawned
void AEnemyShip::BeginPlay()
{
	Super::BeginPlay();

	for (TObjectIterator<APlayerShip> It; It; ++It)
	{
		PlayerShip = *It;
	}
}

// Called every frame
void AEnemyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	/**/
	ActorLocation = GetActorLocation();

	FVector DistanceToPlayer = PlayerShip->GetActorLocation() - GetActorLocation();

	DistanceToPlayer.Normalize();

	//float DistanceToPlayer = DistanceToPlayer.Size();

	FRotator ToPlayerRotation = DistanceToPlayer.Rotation();

	if (PlayerShip) 
	{
		ToPlayerRotation.Pitch = 0;
		Sphere->SetWorldRotation(ToPlayerRotation);
	}
	/* */
	FVector PSLoc = PlayerShip->GetActorLocation();

	/* Остановка, если....*/
	if ((ActorLocation.X - PSLoc.X) >= 500 || (ActorLocation.Y - PSLoc.Y) >= 500)
	{
		Move();
		
	}
	
	//Fire();
}

void AEnemyShip::ProjectileOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	UGameInstance* GameInstance = GetWorld()->GetGameInstance();
	UShipGameInstance*ShipGameInstance = Cast<UShipGameInstance>(GameInstance);

	if (ShipGameInstance != nullptr)
	{
		//ShipGameInstance->GIScore += Quantity;
		//ShipGameInstance->Init();

	}
	if (Cast<AProjectile>(OtherActor) != nullptr)
	{
		
		//Destroy();
	}
}

void AEnemyShip::EndPlay(EEndPlayReason::Type EndPlayReason)
{

}

void AEnemyShip::Fire()
{
	FVector fwd = GetActorForwardVector();
	FVector Start = Mesh->GetComponentLocation();
	Start += fwd * 35;

	AEnemyProjectile*enemyprojectile = GetWorld()->SpawnActor<AEnemyProjectile>(BP_EnemyProjectile, Start, RootComponent->GetComponentRotation());
}

void AEnemyShip::Move()
{
	SetActorLocation(GetActorLocation() + GetActorForwardVector());
}