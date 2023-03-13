// Copyright 2023 Whiskey Cat Softworks


#include "SCProjectile.h"

// Sets default values
ASCProjectile::ASCProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

    if (!CollisionComponent)
    {
        CollisionComponent = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComponent"));
        CollisionComponent->InitSphereRadius(15.0f);
        RootComponent = CollisionComponent;
    }

    //Set projectile properties
    if (!ProjectileMoveComponent)
    {
        ProjectileMoveComponent = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovementComponent"));
        ProjectileMoveComponent->SetUpdatedComponent(CollisionComponent);
        ProjectileMoveComponent->InitialSpeed = ProjectileSpeed;
        ProjectileMoveComponent->bRotationFollowsVelocity = true;
        ProjectileMoveComponent->bShouldBounce = false;
        ProjectileMoveComponent->ProjectileGravityScale = 0.0f;
    }

}

void ASCProjectile::AddToForwardVelocity(const float SpeedToAdd)
{
    float Speed = FMath::Clamp(SpeedToAdd, 0.0f, (SpeedToAdd / 1.2f));
    ProjectileMoveComponent->Velocity = ProjectileMoveComponent->Velocity + (GetActorForwardVector() * Speed);
}

// Called when the game starts or when spawned
void ASCProjectile::BeginPlay()
{
	Super::BeginPlay();

    GetWorldTimerManager().SetTimer(TimerSelfDestruct, this, &ASCProjectile::SelfDestruct, TimeToSelfDestruct, false);
	
}

// Called every frame
void ASCProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASCProjectile::SelfDestruct()
{
    if (IsValid(this))
    {
        Destroy();
    }
}

