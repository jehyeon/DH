// Fill out your copyright notice in the Description page of Project Settings.


#include "DHGameInstance.h"
#include "StatComponent.h"

UDHGameInstance::UDHGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> TERRA_STAT(TEXT("DataTable'/Game/Datas/TerraStat.TerraStat'"));
	TerraStat = TERRA_STAT.Object;

	static ConstructorHelpers::FObjectFinder<UDataTable> MELEE_MINION_STAT(TEXT("DataTable'/Game/Datas/MeleeMinionStat.MeleeMinionStat'"));
	MeleeMinionStat = MELEE_MINION_STAT.Object;
}

void UDHGameInstance::Init()
{
	Super::Init();
}

FStatData* UDHGameInstance::GetStatData(int32 Level)
{
	// TEMP
	return TerraStat->FindRow<FStatData>(*FString::FromInt(Level), TEXT(""));
}

FStatData* UDHGameInstance::GetTerraStat(int32 Level)
{
	return TerraStat->FindRow<FStatData>(*FString::FromInt(Level), TEXT(""));
}

FStatData* UDHGameInstance::GetMeleeMinionStat(int32 Level)
{
	return MeleeMinionStat->FindRow<FStatData>(*FString::FromInt(Level), TEXT(""));
}
