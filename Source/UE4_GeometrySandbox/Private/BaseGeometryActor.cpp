// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseGeometryActor.h"
#include "Engine/Engine.h"

DEFINE_LOG_CATEGORY_STATIC(LogBaseGeometry, All, All);

// Sets default values
ABaseGeometryActor::ABaseGeometryActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>("BaseMesh");
	SetRootComponent(BaseMesh);
}

// Called when the game starts or when spawned
void ABaseGeometryActor::BeginPlay()
{
	Super::BeginPlay();

	InitialLocation = GetActorLocation();

	//printTransform();

	//printTypes();

	//printStringTypes();

}

// Called every frame
void ABaseGeometryActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	float time = GetWorld()->GetTimeSeconds();
	CurrentLocation.Z = InitialLocation.Z + Amplitude * FMath::Sin(Frequency * time);
	SetActorLocation(CurrentLocation);

}

void ABaseGeometryActor::printTypes()
{
	UE_LOG(LogTemp, Display, TEXT("Actor name: %s"), *GetName());
	UE_LOG(LogTemp, Display, TEXT("Weapons Num: %d, kills num: %i"), WeaponsNum, KillsNum);
	UE_LOG(LogTemp, Display, TEXT("Health: %f"), Health);
	UE_LOG(LogTemp, Display, TEXT("Is Dead: %d"), IsDead);
	UE_LOG(LogTemp, Display, TEXT("Has Weapon: %d"), static_cast<int>(HasWeapon));
}

void ABaseGeometryActor::printStringTypes()
{
	FString Name = "John Connor";

	FString WeaponsNumStr = "Weapons Num = " + FString::FromInt(WeaponsNum);
	FString HealthStr = "Health = " + FString::SanitizeFloat(Health);
	FString IsDeadStr = "Is Dead = " + FString(IsDead ? "true" : "false");

	FString stat = FString::Printf(TEXT("\n == All Stat == \n %s \n %s \n %s"), *WeaponsNumStr, *HealthStr, *IsDeadStr);


	UE_LOG(LogBaseGeometry, Warning, TEXT("%s"), *stat);

	GEngine->AddOnScreenDebugMessage(-1, 3, FColor::Red, Name);
	GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Green, stat, true, FVector2D(1.5f, 1.5f));
}

void ABaseGeometryActor::printTransform()
{
	FTransform Transform = GetActorTransform();
	FVector Location = Transform.GetLocation();
	FRotator Rotation = Transform.Rotator();
	FVector Scale = Transform.GetScale3D();


	UE_LOG(LogTemp, Display, TEXT("Actor name: %s"), *GetName());
	UE_LOG(LogTemp, Display, TEXT("Transform: %s"), *Transform.ToString());
	UE_LOG(LogTemp, Display, TEXT("Location: %s"), *Location.ToString());
	UE_LOG(LogTemp, Display, TEXT("Rotation: %s"), *Rotation.ToString());

	UE_LOG(LogTemp, Error, TEXT("Human Transform: %s"), *Transform.ToHumanReadableString());
}

