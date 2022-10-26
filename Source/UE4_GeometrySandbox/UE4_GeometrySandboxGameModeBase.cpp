// Copyright Epic Games, Inc. All Rights Reserved.


#include "UE4_GeometrySandboxGameModeBase.h"
#include "SandboxPawn.h"

AUE4_GeometrySandboxGameModeBase::AUE4_GeometrySandboxGameModeBase()
{
	DefaultPawnClass = ASandboxPawn::StaticClass();
}