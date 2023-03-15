// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SCProjectile.h"
#include "SCMovementComponent.h"
#include "SCEnemyShip.generated.h"

class UStaticMeshComponent;

UCLASS()
class SPACECRAZE_API ASCEnemyShip : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASCEnemyShip();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectiles")
		TSubclassOf<ASCProjectile> PrimaryProjectile;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Ship Properties")
		class UStaticMeshComponent* ShipMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Ship Properties")
		class USCMovementComponent* MovementComponent;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
