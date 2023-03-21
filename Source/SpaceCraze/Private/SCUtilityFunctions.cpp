// Copyright 2023 Whiskey Cat Softworks


#include "SCUtilityFunctions.h"

void SCUtility::TestThread()
{
	//not for the actual game, just messing around
	float StartTime;
	float EndTime;
	const char Content[] = "bbbbbbbbbbbbbbb";
	const ANSICHAR bob[] = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	int32 iterations = 1000000000;
	TArray <bool> TasksDone;
	TasksDone.SetNum(iterations);

	StartTime = FPlatformTime::Seconds();

	ParallelFor(iterations, [&](int32 iteration)
	{
		FAES::EncryptData((uint8*)Content, sizeof(Content), bob);
		TasksDone[iteration] = true;

	});
	EndTime = FPlatformTime::Seconds();

	PrintToScreen(FString::FromInt(sizeof(Content)));
	PrintToScreen(FString::SanitizeFloat(StartTime));
	PrintToScreen(FString::SanitizeFloat(EndTime));

	PrintToScreen(FString::FromInt(TasksDone[TasksDone.Num() - 1]));

}

void SCUtility::PrintToScreen(FString Message)
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Yellow, (TEXT("%s"), Message));
}