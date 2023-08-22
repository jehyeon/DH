// Fill out your copyright notice in the Description page of Project Settings.


#include "DHGameInstance.h"
#include "StatComponent.h"

UDHGameInstance::UDHGameInstance()
{
	static ConstructorHelpers::FObjectFinder<UDataTable> TERRA_STAT(TEXT("DataTable'/Game/Datas/TerraStat.TerraStat'"));

	TerraStat = TERRA_STAT.Object;
}

void UDHGameInstance::Init()
{
	Super::Init();

	UE_LOG(LogTemp, Warning, TEXT("MyGameInstance %d"), GetStatData(1)->Attack);
}

FStatData* UDHGameInstance::GetStatData(int32 Level)
{
	// TEMP
	return TerraStat->FindRow<FStatData>(*FString::FromInt(Level), TEXT(""));
}
