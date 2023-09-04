// Fill out your copyright notice in the Description page of Project Settings.


#include "StatComponent.h"
#include "DHGameInstance.h"
#include "Kismet/GameplayStatics.h"

UStatComponent::UStatComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
	bWantsInitializeComponent = true;
}


// Called when the game starts
void UStatComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UStatComponent::InitializeComponent()
{
	Super::InitializeComponent();

}

void UStatComponent::SetName(FName NewName)
{
	Name = NewName;

	// TEMP Level 1
	SetLevel(1);
}

void UStatComponent::OnAttacked(float DamageAmount)
{
	int32 NewHp = Hp - DamageAmount;
	SetHp(NewHp);
}

void UStatComponent::SetLevel(int32 NewLevel)
{
	Level = NewLevel;

	auto GameInstance = Cast<UDHGameInstance>(UGameplayStatics::GetGameInstance(GetWorld()));
	if (GameInstance)
	{
		// TEMP
		auto StatData = GameInstance->GetStatData(NewLevel);
		if (StatData)
		{
			Level = StatData->Level;
			SetHp(StatData->MaxHp);
			MaxHp = StatData->MaxHp;
			Attack = StatData->Attack;
		}
	}
}

void UStatComponent::SetHp(int32 NewHp)
{
	Hp = NewHp;
	if (Hp < 0)
	{
		Hp = 0;
	}
}

