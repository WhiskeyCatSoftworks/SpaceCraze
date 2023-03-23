// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Async/ParallelFor.h"
#include "Misc/AES.h"
namespace SCUtility
{	//Helper Functions
	void PrintToScreen(FString Message);


	//Templates
	template <class T>
	T* SimpleSpawn(TSubclassOf<AActor> SpawnClass, FTransform SpawnTransform, AActor* Owner)
	{
		T* SpawnedActor = NULL;
		UWorld* World = Owner->GetWorld();
		if (World != NULL)
		{
			FActorSpawnParameters SpawnParameters;
			SpawnParameters.Owner = Owner;
			SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

			SpawnedActor = World->SpawnActor<T>(SpawnClass, FVector(SpawnTransform.GetLocation()), FRotator(SpawnTransform.GetRotation()), SpawnParameters);
		}
		
		return CastChecked<T>(SpawnedActor);
	}

	//Just for experimenting
	void TestParallelFor();

}
