// Copyright 2023 Whiskey Cat Softworks

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SCShipInterface.h"
#include "SCMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SPACECRAZE_API USCMovementComponent : public UActorComponent, public ISCShipInterface
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USCMovementComponent();

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float MaxSpeed = 1200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float RightMaxSpeed = 1200.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float AccelInterpSpeed = 8.0f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		bool ClampToArea = false;
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D ClampXMinMax = FVector2D(-1200.0f, 600.0f);
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		FVector2D ClampYMinMax = FVector2D(-1600.0f, 1600.0f);

	FVector CurrVelocity;

	//Interface Functions
	void SetInputForward_Implementation(float Input);
	void SetInputRight_Implementation(float Input);

private:
	void MoveOwner(float DeltaTime);
	void RotateOwner(const FVector Velocity);
	FVector Acceleration(FVector InputAxis, float InterpSpeed);

	float RightCurrSpeed;
	float InputForward;
	float InputRight;
	UWorld* World;


protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

		
};
