// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "PlayerPawn.generated.h"

UCLASS()
class SPACECRAZE_API APlayerPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values
	APlayerPawn();

	//Properties
	UPROPERTY(EditAnywhere, Category = "Player Pawn Properties")
		float CameraPitch = -65.0f;
	UPROPERTY(EditAnywhere, Category = "Player Pawn Properties")
		float CameraFOV = 45.0f;
	UPROPERTY(EditAnywhere, Category = "Player Pawn Properties")
		float BoomLength = 4000.0f;

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* CameraBoom;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* Camera;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
