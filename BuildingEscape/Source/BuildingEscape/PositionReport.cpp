// Fill out your copyright notice in the Description page of Project Settings.

#include "PositionReport.h"
#include "GameFramework/Actor.h"


// Sets default values for this component's properties
UPositionReport::UPositionReport()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	
}


// Called when the game starts
void UPositionReport::BeginPlay()
{
	Super::BeginPlay();
	const FString objectName = GetOwner()->GetName();
	FString objectPosition = GetOwner()->GetActorLocation().ToString();
	FString objectTransform = GetOwner()->GetTransform().GetLocation().ToString();
	UE_LOG(LogTemp, Error, TEXT("%s is at %s transform: %s"), *objectName, *objectPosition,*objectTransform);
	
}
 

// Called every frame
void UPositionReport::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	//UE_LOG(LogTemp, Warning, TEXT("PPI it is a tick message on Table"));
}

