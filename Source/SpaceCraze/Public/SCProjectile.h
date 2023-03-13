// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "SCProjectile.generated.h"

UCLASS()
class SPACECRAZE_API ASCProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASCProjectile();

	UPROPERTY(VisibleDefaultsOnly, Category = Projectile)
		USphereComponent* CollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMoveComponent;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Properties")
		float ProjectileSpeed = 1400.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Projectile Properties")
		float TimeToSelfDestruct = 2.0f;

	void AddToForwardVelocity(const float SpeedToAdd);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	FTimerHandle TimerSelfDestruct;
	void SelfDestruct();

};
