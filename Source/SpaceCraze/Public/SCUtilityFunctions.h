// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Async/ParallelFor.h"
#include "Misc/AES.h"
namespace SCUtility
{
	void TestThread();
	void PrintToScreen(FString Message);
	AActor* SimpleSpawn(TSubclassOf<AActor> SpawnClass, FTransform SpawnTransform, AActor* Owner);
}
