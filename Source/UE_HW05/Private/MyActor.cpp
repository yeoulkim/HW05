// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Start = FVector(0, 0, 0);

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	Move();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

int32 AMyActor::Step()
{
	return FMath::RandRange(0, 1);
}

void AMyActor::Move()
{
	UE_LOG(LogTemp, Warning, TEXT("Start Position: (%.0f, %.0f, %.0f)"), Start.X, Start.Y, Start.Z);

	for (int32 i = 0; i < 10; ++i)
	{
		int32 XStep = Step();
		int32 YStep = Step();

		Start.X += XStep;
		Start.Y += YStep;

		UE_LOG(LogTemp, Warning, TEXT("Step %d: Position = (%.0f, %.0f, %.0f)"), i + 1, Start.X, Start.Y, Start.Z);
	}	
}
