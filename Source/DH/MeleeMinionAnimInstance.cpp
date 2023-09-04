// Fill out your copyright notice in the Description page of Project Settings.


#include "MeleeMinionAnimInstance.h"

UMeleeMinionAnimInstance::UMeleeMinionAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Characters/Minions/AttackMontage.AttackMontage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UMeleeMinionAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (temp > 3.f)
	{
		temp = 0.f;
		PlayAttackMontage();
	}

	temp += DeltaSeconds;
}

void UMeleeMinionAnimInstance::PlayAttackMontage()
{
	Super::PlayAttackMontage();

	Montage_Play(AttackMontage, 1.0f);
}
