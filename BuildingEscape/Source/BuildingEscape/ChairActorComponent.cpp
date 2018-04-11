// Copyrights ppi

#include "ChairActorComponent.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UChairActorComponent::UChairActorComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UChairActorComponent::BeginPlay()
{
	Super::BeginPlay();
	const FString objectName = GetOwner()->GetName();
	FString objectPosition = GetOwner()->GetActorLocation().ToString();
	FString objectTransform = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Error, TEXT("%s is at %s transform: %s"), *objectName, *objectPosition, *objectTransform);
	
}


// Called every frame
void UChairActorComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

