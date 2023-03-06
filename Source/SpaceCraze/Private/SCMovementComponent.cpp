// Fill out your copyright notice in the Description page of Project Settings.


#include "SCMovementComponent.h"

// Sets default values for this component's properties
USCMovementComponent::USCMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


void USCMovementComponent::SetInputForward_Implementation(float Input)
{
	InputForward = Input;
}

void USCMovementComponent::SetInputRight_Implementation(float Input)
{
	InputRight = Input;
}

void USCMovementComponent::MoveOwner(float DeltaTime)
{
	AActor* Owner = GetOwner();
	FVector CurrentLocation = Owner->GetActorLocation();

	ForwardCurrSpeed = SmoothSpeed(InputForward, ForwardCurrSpeed, ForwardMaxSpeed, AccelInterpSpeed);
	RightCurrSpeed = SmoothSpeed(InputRight, RightCurrSpeed, RightMaxSpeed, AccelInterpSpeed);

	FVector ForwardMove = FVector(Owner->GetActorForwardVector() * (ForwardCurrSpeed * DeltaTime));
	FVector RightMove = FVector(Owner->GetActorRightVector() * (RightCurrSpeed * DeltaTime));

	FVector MoveToLocation = CurrentLocation + ForwardMove + RightMove;
	if (ShouldClampXY)
	{
		float XClamped = FMath::Clamp(MoveToLocation.X, ClampXMinMax.X, ClampXMinMax.Y);
		float YClamped = FMath::Clamp(MoveToLocation.Y, ClampYMinMax.X, ClampYMinMax.Y);
		MoveToLocation = FVector(XClamped, YClamped, 0.0f);
	}

	Owner->SetActorLocation(FVector(MoveToLocation.X, MoveToLocation.Y, 0.0f));
}

float USCMovementComponent::SmoothSpeed(float InputAxis, float CurrentSpeed, float TargetSpeed, float InterpSpeed)
{
	float SmoothedSpeed;
	UWorld* World = GetWorld();
		if (World)
		{
			TargetSpeed = TargetSpeed * InputAxis;
			SmoothedSpeed = FMath::FInterpTo(CurrentSpeed, TargetSpeed, World->GetDeltaSeconds(), InterpSpeed);
		}

	return SmoothedSpeed;
}

// Called when the game starts
void USCMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void USCMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveOwner(DeltaTime);

	// ...
}

