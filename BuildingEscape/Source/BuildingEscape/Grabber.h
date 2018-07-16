// Copyrights ppi

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Runtime/Engine/Classes/PhysicsEngine/PhysicsHandleComponent.h"
#include "Runtime/Engine/Classes/Components/InputComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void AttachInputComponent();

	void AttachPhysicsHandle();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	const FHitResult GetFirstObjectHitOnViewLine();

	

	

private:
	bool debulDrawnLine =false;
//	FVector PlayerViewPointLocation;
//	FRotator PlayerViewPointRotation;
//	FVector ViewVectorEnd;
	const float reach = 100.f;
	//attached in runtime
	UPhysicsHandleComponent* PhysicsHandle=nullptr;
	UInputComponent* InputComponent = nullptr;
	void Grab();
	void Release();
	void DrawDebugViewVector();
	FVector GetReachLineEnd();
	FVector GetReachLineStart();
};
