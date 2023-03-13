// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "SCShipInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class USCShipInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class SPACECRAZE_API ISCShipInterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ship Interface")
		void SetInputForward(const float Input);

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Ship Interface")
		void SetInputRight(const float Input);
};
