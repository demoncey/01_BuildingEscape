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
	//UE_LOG(LogTemp, Error, TEXT("Location %s Rotation %s"), *PlayerViewPointLocation.ToString(),* PlayerViewpointRotation.ToString());
	//same values like above
	//UE_LOG(LogTemp, Error, TEXT("Actor Location %s Rotation %s"), *GetOwner()->GetActorLocation().ToString(), *GetOwner()->GetActorRotation().ToString());
	
	DrawDebugViewVector();
	FHitResult Hit=CheckObjectHitOnViewLine();
	//see what we hit
}

FHitResult UGrabber::CheckObjectHitOnViewLine()
{
	///trace of specified object on view line first hit
	FHitResult Hit;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(OUT Hit, PlayerViewPointLocation, ViewVectorEnd, FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParameters);
	AActor* ActorHit = Hit.GetActor();
	if (ActorHit) {
		UE_LOG(LogTemp, Error, TEXT("Line Trace Actor Hit %s"), *ActorHit->GetName());
	}
	return Hit;
}

void UGrabber::DrawDebugViewVector()
{
	ViewVectorEnd = PlayerViewPointLocation + reach * PlayerViewpointRotation.Vector();
	DrawDebugLine(GetWorld(), PlayerViewPointLocation, ViewVectorEnd, FColor(255, 0, 0), false, 0.f, 0.f, 2.f);
}

