// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "StatComponent.generated.h"

USTRUCT()
struct FStatData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Level;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 Attack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxHp;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class DH_API UStatComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UStatComponent();

protected:
	virtual void BeginPlay() override;
	virtual void InitializeComponent() override;

public:
	void SetName(FName NewName);

	void OnAttacked(float DamageAmount);
	void SetLevel(int32 NewLevel);
	void SetHp(int32 NewHp);

	int32 GetHp() { return Hp; }
	int32 GetAttack() { return Attack; }

private:
	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	FName Name;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Level;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Hp;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 MaxHp;

	UPROPERTY(EditAnywhere, Category = Stat, Meta = (AllowPrivateAccess = true))
	int32 Attack;
};
