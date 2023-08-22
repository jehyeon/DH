// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "DHGameInstance.generated.h"

class UDataTable;
struct FStatData;

UCLASS()
class DH_API UDHGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	UDHGameInstance();

	virtual void Init() override;

	FStatData* GetStatData(int32 Level);

private:
	UPROPERTY()
	UDataTable* TerraStat;
};
