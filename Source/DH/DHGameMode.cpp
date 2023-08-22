// Copyright Epic Games, Inc. All Rights Reserved.

#include "DHGameMode.h"
#include "DHCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADHGameMode::ADHGameMode()
{
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("Blueprint'/Game/Characters/Terra/BP_Terra.BP_Terra_C'"));
	
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
