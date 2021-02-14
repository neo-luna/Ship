// Fill out your copyright notice in the Description page of Project Settings.


#include "Bot.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Obstacle.h"
// Sets default values
ABot::ABot()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	Sphere->InitSphereRadius(150);
	Sphere->SetHiddenInGame(false);
	RootComponent = Sphere;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Sphere);	

	bMoveFactor = true;
}

// Called when the game starts or when spawned
void ABot::BeginPlay()
{
	Super::BeginPlay();

	//GetWorld()->GetTimerManager().SetTimer(HandleFire, this, &ABot::Fire, TimeFire, true, TimeDelay);
}

// Called every frame
void ABot::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	GEngine->AddOnScreenDebugMessage(1, 0, FColor::Red, FString::SanitizeFloat(FLAR.Yaw));

	ValRotation += 5;

	FVector ActorLocation = GetActorLocation();

	FHitResult Hit;
	FVector Start = ActorLocation;
	FVector ForwardVector = GetActorForwardVector();
	FVector End = ((ForwardVector * 400.f) + Start);

	DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 1, 0, 5);

	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility))
	{
		AObstacle*Obstacle = Cast<AObstacle>(Hit.Actor);

		if (Obstacle)
		{
			bMoveFactor = false;

			//AddActorWorldRotation(FRotator(0, 0, ValRotation));
			//GEngine->AddOnScreenDebugMessage(0, 1, FColor::Red, TEXT("Obstacle"));
		}
		if (!Obstacle)
		{
			bMoveFactor = true;
		}
		
	}

	/* Находим игрока*/
	TSubclassOf<APlayerShip> ClassToFind;
	ClassToFind = APlayerShip::StaticClass();
	TArray<AActor*> FoundEnemies;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundEnemies);
	/* Итерируем и находим локацию*/
	for (AActor* Actor : FoundEnemies)
	{
		PlayerLocation = Actor->GetActorLocation();

		ToPlayer = Actor->GetActorLocation() - GetActorLocation();

		DistanceToPlayer = ToPlayer.Size();
	}
	/* Поворачиваем Бота*/
	FVector BotLocation = GetActorLocation();

	FLAR = UKismetMathLibrary::FindLookAtRotation(BotLocation, PlayerLocation);

	BotRotation = UKismetMathLibrary::MakeRotator(0, 0, FLAR.Yaw);

	SetActorRelativeRotation(BotRotation);

	/* Если расстояние до игрока меньше-равно диаметра сферы, двигаемся на Игрока*/
	if (DistanceToPlayer >= Sphere->GetScaledSphereRadius())
	{
		if (bMoveFactor)
		{
			Move();
		}
		
	}
}

/* Движение*/
void ABot::Move()
{
	SetActorLocation(GetActorLocation() + GetActorForwardVector());
}

/* Огонь*/
void ABot::Fire()
{
	FVector ForwardVector = GetActorForwardVector();

	FVector Start = GetActorLocation();

	Start += ForwardVector * 100;
	/* Спаун прожектайла*/
	Projectile = GetWorld()->SpawnActor<AProjectile>(
		BP_Projectile, Start, RootComponent->GetComponentRotation());

	/* Заполняем массив Projectiles*/
	Projectiles.Add(Projectile);

	//GEngine->AddOnScreenDebugMessage(0, 1, FColor::Red, FString::FromInt(Projectiles.Num()));
}



