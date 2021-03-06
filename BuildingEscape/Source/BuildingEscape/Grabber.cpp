// Copyrights ppi

#include "Grabber.h"
#include"Engine/World.h"
#include"Runtime/Engine/Public/DrawDebugHelpers.h"
#include "Runtime/Engine/Classes/Components/PrimitiveComponent.h"

#define OUT

// Sets default values for this component's properties
UGrabber::UGrabber()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//debugflag init
	debulDrawnLine = false;

	// ...
}


// Called when the game starts
void UGrabber::BeginPlay()
{
	Super::BeginPlay();
	AttachPhysicsHandle();
	AttachInputComponent();
}

void UGrabber::AttachInputComponent()
{
	InputComponent = GetOwner()->FindComponentByClass<UInputComponent>();
	if (InputComponent) {
		InputComponent->BindAction("Grab", IE_Pressed, this, &UGrabber::Grab);
		InputComponent->BindAction("Grab", IE_Released, this, &UGrabber::Release);
	}
	else {
		UE_LOG(LogTemp, Error, TEXT("InputComponent not found"));
	}
}

void UGrabber::AttachPhysicsHandle()
{
	PhysicsHandle = GetOwner()->FindComponentByClass<UPhysicsHandleComponent>();
	if (PhysicsHandle == nullptr) {
		UE_LOG(LogTemp, Error, TEXT("PhysicsHandle not found"));
	}
}


// Called every frame
void UGrabber::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	//UE_LOG(LogTemp, Error, TEXT("Actor Location %s Rotation %s"), *GetOwner()->GetActorLocation().ToString(), *GetOwner()->GetActorRotation().ToString());
	if (debulDrawnLine) {
		DrawDebugViewVector();
	}
	if (PhysicsHandle && PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->SetTargetLocation(GetReachLineEnd());
	}
	
}

const FHitResult UGrabber::GetFirstObjectHitOnViewLine()
{
	///trace of specified object on view line first hit
	FHitResult Hit;
	FCollisionQueryParams TraceParameters(FName(TEXT("")), false, GetOwner());
	GetWorld()->LineTraceSingleByObjectType(OUT Hit, GetReachLineStart(), GetReachLineEnd(), FCollisionObjectQueryParams(ECollisionChannel::ECC_PhysicsBody), TraceParameters);
	return Hit;
}

void UGrabber::DrawDebugViewVector()
{
	DrawDebugLine(GetWorld(), GetReachLineStart(), GetReachLineEnd(), FColor(255, 0, 0), false, 0.f, 0.f, 2.f);
}
FVector UGrabber::GetReachLineEnd()
{
	FVector PlayerLocation;
	FRotator PlayerRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation, OUT PlayerRotation);
	auto viewVectorEnd = PlayerLocation + reach * PlayerRotation.Vector();
	return viewVectorEnd;
}

FVector UGrabber::GetReachLineStart()
{
	FVector PlayerLocation;
	FRotator PlayerRotation;
	GetWorld()->GetFirstPlayerController()->GetPlayerViewPoint(OUT PlayerLocation, OUT PlayerRotation);
	return PlayerLocation;
}

void UGrabber::Grab() {

	UE_LOG(LogTemp, Warning, TEXT("Grab executed"));
	if (PhysicsHandle) {
		auto Hit = GetFirstObjectHitOnViewLine();
		auto ComponentToGrab = Hit.GetComponent();
		auto ActorHit = Hit.GetActor();
		if (ActorHit != nullptr) {
			UE_LOG(LogTemp, Warning, TEXT("Actor %s Hit  by player pawn"), *ActorHit->GetName());
			PhysicsHandle->GrabComponent(ComponentToGrab, NAME_None, ComponentToGrab->GetOwner()->GetActorLocation(), true);
		}
	}
}
void UGrabber::Release() {
	UE_LOG(LogTemp, Warning, TEXT("release executed"));
	if (PhysicsHandle && PhysicsHandle->GrabbedComponent) {
		PhysicsHandle->ReleaseComponent();
	}
}