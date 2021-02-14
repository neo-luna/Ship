// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerShip.h"
#include "Bot.h"

// Sets default values
APlayerShip::APlayerShip()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sphere = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	RootComponent = Sphere;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Sphere);

	OnActorBeginOverlap.AddDynamic(this, &APlayerShip::EnemyOverlap);

	bFireOnOff = false;
}

// Called when the game starts or when spawned
void APlayerShip::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(FireTrueHandle, this, &APlayerShip::FireTrue, FireTimeTrue, true);

}

// Called every frame
void APlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	//скорость игрока
	if (!CurrentVelocity.IsZero())
	{
		FVector NewLocation = GetActorLocation() + (CurrentVelocity*DeltaTime);
		SetActorLocation(NewLocation);
	}
}

// Called to bind functionality to input
void APlayerShip::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("Strafe", this, &APlayerShip::Strafe);

	PlayerInputComponent->BindAxis("Forward", this, &APlayerShip::Forward);

	PlayerInputComponent->BindAction("Fire", IE_Pressed, this, &APlayerShip::Fire);

	PlayerInputComponent->BindAction("LevelTwo", IE_Pressed, this, &APlayerShip::LevelNew);

}

void APlayerShip::Strafe(float AxisValue)
{
	CurrentVelocity.Y = FMath::Clamp(AxisValue, -1.f, 1.f) * 600;
}

void APlayerShip::Forward(float AxisValue)
{
	CurrentVelocity.X = FMath::Clamp(AxisValue, -1.f, 1.f) * 600;
}

void APlayerShip::Fire()
{
	FVector fwd = GetActorForwardVector();
	FVector Start = Mesh->GetComponentLocation();
	Start += fwd * 30;

	if (bFireOnOff)
	{	
		bFireOnOff = false;
		AProjectile*projectile = GetWorld()->SpawnActor<AProjectile>(BP_Projectile, Start, RootComponent->GetComponentRotation());
	}
	
}

void APlayerShip::EnemyOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (Cast<AEnemyShip>(OtherActor) || Cast<AChildProjectile>(OtherActor) != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(0, 1, FColor::Purple, TEXT("Child Overlap"));
		Destroy();
	}
}

void APlayerShip::EndPlay(EEndPlayReason::Type EndPlayReason)
{
	APlayerController* PController = GetWorld()->GetFirstPlayerController();

	if (PController)
	{
		AMyHUD* hud = Cast<AMyHUD>(PController->GetHUD());

		hud->GameOver = true;
	}
}

void APlayerShip::LevelNew()
{
	
	for (TObjectIterator<AEnemyShip> It; It; ++It)
	{
		EnemyShip = *It;

		EnemyShip->Fire();
	}
	
	
}

/* Устанавливает вкл. Fire*/
void APlayerShip::FireTrue()
{
	bFireOnOff = true;
}








