// Copyrights ppi

#include "DoorComponent.h"
#include "GameFramework/Actor.h"
#include"Engine/World.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

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
	//ActorThatOpen=GetWorld()->GetFirstPlayerController()->GetPawn();
	owner = GetOwner();
	
}

void UDoorComponent::OpenDoor()
{
	//owner->SetActorRotation(FRotator(0.0f, OpenAngle, 0.0f));
	OnOpenRequest.Broadcast();
}


void UDoorComponent::CloseDoor()
{
	//owner->SetActorRotation(FRotator(0.0f,90.0f, 0.0f));
	OnCloseRequest.Broadcast();
	
}


// Called every frame
void UDoorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// poll a trigger valume every frame
	if (GetTotalMassOfActors()>10.f) {
		//if the ActorThatOpen
		OpenDoor();
		LastDoorOpenTime = GetWorld()->GetTimeSeconds();
	}
	if (GetWorld()->GetTimeSeconds() - LastDoorOpenTime >= DoorCloseDelay) {
			CloseDoor();
	}
}


float UDoorComponent::GetTotalMassOfActors() {
	float TotalMass = 0.f;
	TArray<AActor*> actors;
	PressurePlate->GetOverlappingActors(actors, nullptr);
	for (const auto& actor : actors) {
		
		TotalMass+= actor->FindComponentByClass<UPrimitiveComponent>()->GetMass();
		UE_LOG(LogTemp, Warning, TEXT("Actor on plate %s %f"), *actor->GetName(), TotalMass);
	}
	return TotalMass;
}