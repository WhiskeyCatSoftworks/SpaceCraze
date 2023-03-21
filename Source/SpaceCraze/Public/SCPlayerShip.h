// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Async/ParallelFor.h"
#include "Misc/AES.h"
#include "SCProjectile.h"
#include "SCMovementComponent.h"
#include "SCPlayerShip.generated.h"

class UStaticMeshComponent;

UCLASS()
class SPACECRAZE_API ASCPlayerShip : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASCPlayerShip();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectiles")
		TSubclassOf<ASCProjectile> PrimaryProjectile;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Ship Properties")
		class UStaticMeshComponent* ShipMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Ship Properties")
		class USCMovementComponent* MovementComponent;

	void SetupPlayerInput(class UInputComponent* InputComp);
	void MoveForward(const float Value);
	void MoveRight(const float Value);
	void PrimaryFire();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
