// Fill out your copyright notice in the Description page of Project Settings.


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

// Called when the game starts or when spawned
void ASCPlayerShip::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASCPlayerShip::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

