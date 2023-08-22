// Fill out your copyright notice in the Description page of Project Settings.


#include "TerraAnimInstance.h"

UTerraAnimInstance::UTerraAnimInstance()
{
	static ConstructorHelpers::FObjectFinder<UAnimMontage> AM(TEXT("AnimMontage'/Game/Characters/Terra/AttackMontage.AttackMontage'"));
	if (AM.Succeeded())
	{
		AttackMontage = AM.Object;
	}
}

void UTerraAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);
}

void UTerraAnimInstance::PlayAttackMontage()
{
	Super::PlayAttackMontage();

	Montage_Play(AttackMontage, 1.0f);
}

