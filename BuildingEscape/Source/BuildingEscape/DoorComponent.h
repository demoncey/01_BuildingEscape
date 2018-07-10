// Copyrights ppi

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/TriggerVolume.h"
#include "DoorComponent.generated.h"



UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UDoorComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UDoorComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = -90.f;
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;
	//UPROPERTY(EditAnywhere)
	AActor* ActorThatOpen;//remember pawn inherits from actor
	UPROPERTY(EditAnywhere)
	float DoorCloseDelay=1.f;
	float LastDoorOpenTime;
	AActor *owner;
};
