// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
//#include "Components/StaticMeshComponent.h"
#include "SCMovementComponent.h"
#include "SCPlayerShip.generated.h"

class UStaticMeshComponent;
class USCMovementComponent;

UCLASS()
class SPACECRAZE_API ASCPlayerShip : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	ASCPlayerShip();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Projectiles")
		TSubclassOf<AActor> PrimaryProjectile;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Ship Properties")
		class UStaticMeshComponent* ShipMesh;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"), Category = "Ship Properties")
		class USCMovementComponent* MovementComponent;

	void SetupPlayerInput(class UInputComponent* InputComp);
	void MoveForward(float Value);
	void MoveRight(float Value);
	void PrimaryFire();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
