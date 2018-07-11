// Copyrights ppi

#include "Grabber.h"
#include"Engine/World.h"
#include"Runtime/Engine/Public/DrawDebugHelpers.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint( OUT PlayerViewPointLocation,OUT PlayerViewpointRotation);
	UE_LOG(LogTemp, Error, TEXT("Location %s Rotation %s"), *PlayerViewPointLocation.ToString(),* PlayerViewpointRotation.ToString());
	DrawDebugViewVector();
	//ray cast out to reach distance
	//see what we hit
}

void UGrabber::DrawDebugViewVector()
{
	auto ViewVectorEnd = PlayerViewPointLocation + reach * PlayerViewpointRotation.Vector();
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, ViewVectorEnd, FColor(255, 0, 0), false, 0.f, 0.f, 2.f);
}

