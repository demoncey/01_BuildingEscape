// Copyrights ppi

#include "DoorComponent.h"
#include "GameFramework/Actor.h"

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
	AActor *owner = GetOwner();
	FRotator newRotation = FRotator(0.0f, 120.0f, 0.0f);
	owner->SetActorRotation(newRotation);
}


// Called every frame
void UDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

