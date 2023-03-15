// Copyright 2023 Whiskey Cat Softworks


#include "SCEnemyShip.h"

// Sets default values
ASCEnemyShip::ASCEnemyShip()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	ShipMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ship Mesh"));
	SetRootComponent(ShipMesh);
	//ShipMesh->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);

	MovementComponent = CreateDefaultSubobject<USCMovementComponent>(TEXT("Movement Component"));
	AddOwnedComponent(MovementComponent);
}

// Called when the game starts or when spawned
void ASCEnemyShip::BeginPlay()
{
	Super::BeginPlay();
	MoveForward();
	ShipMesh->OnComponentHit.AddDynamic(this, &ASCEnemyShip::OnHit);
	
}

void ASCEnemyShip::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	Destroy();
}

void ASCEnemyShip::MoveForward()
{
	MovementComponent->SetInputForward_Implementation(1.0);
}

// Called every frame
void ASCEnemyShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

