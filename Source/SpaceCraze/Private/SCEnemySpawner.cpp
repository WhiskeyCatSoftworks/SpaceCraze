// Copyright 2023 Whiskey Cat Softworks


#include "SCEnemySpawner.h"

// Sets default values
ASCEnemySpawner::ASCEnemySpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASCEnemySpawner::BeginPlay()
{
	Super::BeginPlay();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &ASCEnemySpawner::SpawnEnemy, SpawnDelay, true, 0.0f);
	
}

// Called every frame
void ASCEnemySpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASCEnemySpawner::SpawnEnemy()
{
	if (EnemyShipTypes.Num())
	{
		int32 Index = FMath::RandRange(0, EnemyShipTypes.Num() - 1);
		SCUtility::SimpleSpawn<ASCEnemyShip>(EnemyShipTypes[0], GetActorTransform(), this);
	}

}

