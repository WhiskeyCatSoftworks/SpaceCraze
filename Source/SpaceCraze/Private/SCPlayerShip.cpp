// Copyright 2023 Whiskey Cat Softworks


#include "SCPlayerShip.h"

// Sets default values
ASCPlayerShip::ASCPlayerShip()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship Mesh"));
	ShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MovementComponent = CreateDefaultSubobject<USCMovementComponent>(TEXT("Movement Component"));
	AddOwnedComponent(MovementComponent);
}

void ASCPlayerShip::SetupPlayerInput(UInputComponent* InputComp)
{
	// set up gameplay key bindings
	check(InputComponent);
	
	InputComponent->BindAxis("MoveForward", this, &ASCPlayerShip::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &ASCPlayerShip::MoveRight);
	InputComponent->BindAction("PrimaryAction", IE_Pressed, this, &ASCPlayerShip::PrimaryFire);
}

void ASCPlayerShip::MoveForward(const float Value)
{
	MovementComponent->SetInputForward_Implementation(Value);
}

void ASCPlayerShip::MoveRight(const float Value)
{
	MovementComponent->SetInputRight_Implementation(Value);
}

void ASCPlayerShip::PrimaryFire()
{
	FVector ProjectileLocation = GetActorLocation() + (GetActorForwardVector() * 110);
	FTransform SpawnTransform = FTransform(GetActorRotation(), ProjectileLocation, FVector(1.0f, 1.0f, 1.0f));
	
	ASCProjectile* ProjectileSpawned = SCUtility::SimpleSpawn <ASCProjectile>(PrimaryProjectile, SpawnTransform, this);
	ProjectileSpawned->AddToForwardVelocity(MovementComponent->CurrVelocity.X);
}

// Called when the game starts or when spawned
void ASCPlayerShip::BeginPlay()
{
	Super::BeginPlay();
	SetupPlayerInput(InputComponent);
}

// Called every frame
void ASCPlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

