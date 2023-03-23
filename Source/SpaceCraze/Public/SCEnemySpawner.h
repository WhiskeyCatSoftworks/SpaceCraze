// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SCEnemyShip.h"
#include "SCUtilityFunctions.h"
#include "SCEnemySpawner.generated.h"

UCLASS()
class SPACECRAZE_API ASCEnemySpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawn Properties")
	TArray<TSubclassOf<ASCEnemyShip>> EnemyShipTypes;
	
	//default constructor
	ASCEnemySpawner();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	float SpawnDelay = 1.0f;
	void SpawnEnemy();
	FTimerHandle SpawnTimerHandle;

};
