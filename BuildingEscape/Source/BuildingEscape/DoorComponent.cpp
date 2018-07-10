// Copyrights ppi

#include "DoorComponent.h"
#include "GameFramework/Actor.h"
#include"Engine/World.h"

// Sets default values for this component's properties
UDoorComponent::UDoorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//preasurePlate = nullptr;
	
	// ...
}


// Called when the game starts
void UDoorComponent::BeginPlay()
{
	Super::BeginPlay();
	ActorThatOpen=GetWorld()->GetFirstPlayerController()->GetPawn();
	owner = GetOwner();
	
}

void UDoorComponent::OpenDoor()
{
	//AActor *owner = GetOwner();
	FRotator newRotation = FRotator(0.0f, -90.0f, 0.0f);
	owner->SetActorRotation(newRotation);
}


void UDoorComponent::CloseDoor()
{
	
	FRotator newRotation = FRotator(0.0f, 90.0f, 0.0f);
	owner->SetActorRotation(newRotation);
}


// Called every frame
void UDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// poll a trigger valume every frame
	if (PressurePlate->IsOverlappingActor(ActorThatOpen)) {
		//if the ActorThatOpen
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime >= DoorCloseDelay) {
			CloseDoor();
	}
}

