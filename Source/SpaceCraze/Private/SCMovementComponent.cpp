//For Handling Movement of Actor
#include "SCMovementComponent.h"

USCMovementComponent::USCMovementComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void USCMovementComponent::SetInputForward_Implementation(const float Input)
{
	InputForward = Input;
}

void USCMovementComponent::SetInputRight_Implementation(const float Input)
{
	InputRight = Input;
}

void USCMovementComponent::MoveOwner(float DeltaTime)
{
	AActor* Owner = GetOwner();
	FVector CurrentLocation = Owner->GetActorLocation();

	FVector InputVector = FVector(InputForward, InputRight, 0.0f);
	InputVector.Normalize();
	CurrVelocity = Acceleration(InputVector, AccelInterpSpeed);

	FVector MoveToLocation = CurrentLocation + (CurrVelocity * DeltaTime);
	if (ClampToArea)
	{
		float XClamped = FMath::Clamp(MoveToLocation.X, ClampXMinMax.X, ClampXMinMax.Y);
		float YClamped = FMath::Clamp(MoveToLocation.Y, ClampYMinMax.X, ClampYMinMax.Y);
		MoveToLocation = FVector(XClamped, YClamped, 0.0f);
	}

	Owner->SetActorLocation(FVector(MoveToLocation.X, MoveToLocation.Y, 0.0f));
}

void USCMovementComponent::RotateOwner(const FVector Velocity)
{
	float RotAmount = FMath::GetMappedRangeValueClamped(FVector2D(-MaxSpeed, MaxSpeed), FVector2D(-20.0, 20.0f), Velocity.Y);
	AActor* Owner = GetOwner();
	Owner->SetActorRotation(FRotator(0.0f, 0.0f, RotAmount));
}

FVector USCMovementComponent::Acceleration(FVector InputAxis, float InterpSpeed)
{
	FVector InterpedVelocity;
		if (World)
		{
			FVector TargetVelocity = InputAxis * MaxSpeed;
			InterpedVelocity = FMath::VInterpTo(CurrVelocity, TargetVelocity, World->GetDeltaSeconds(), InterpSpeed);
		}

	return InterpedVelocity;
}

// Called when the game starts
void USCMovementComponent::BeginPlay()
{
	Super::BeginPlay();
	World = GetWorld();
	// ...
	
}


// Called every frame
void USCMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	MoveOwner(DeltaTime);
	RotateOwner(CurrVelocity);

	// ...
}

