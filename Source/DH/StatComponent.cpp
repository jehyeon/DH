// Fill out your copyright notice in the Description page of Project Settings.


#include "StatComponent.h"

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

void UStatComponent::OnAttacked(float DamageAmount)
{
	int32 NewHp = Hp - DamageAmount;
	SetHp(NewHp);
}

void UStatComponent::SetLevel(int32 NewLevel)
{
	Level = NewLevel;
}

void UStatComponent::SetHp(int32 NewHp)
{
	Hp = NewHp;
	if (Hp < 0)
	{
		Hp = 0;
	}
}

