// Copyrights ppi

#include "Grabber.h"
#include"Engine/World.h"

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
	//https://api.unrealengine.com/INT/API/Runtime/Engine/DrawDebugLine/index.html
	//ray cast out to reach distance
	//see what we hit
}

