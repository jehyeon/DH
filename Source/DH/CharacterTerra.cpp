// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterTerra.h"
#include "DrawDebugHelpers.h"
#include "StatComponent.h"

void ACharacterTerra::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	Stat->SetName(FName(TEXT("Terra")));
}

void ACharacterTerra::AttackCheck()
{
	FHitResult HitResult;
	FCollisionQueryParams Params(NAME_None, false, this);

	// TEMP
	float AttackRange = 100.f;
	float AttackRadius = 50.f;
	bool DebugMode = true;

	bool bResult = GetWorld()->SweepSingleByChannel(
		OUT HitResult,
		GetActorLocation(),
		GetActorLocation() + GetActorForwardVector() * AttackRange,
		FQuat::Identity,
		ECollisionChannel::ECC_GameTraceChannel2,
		FCollisionShape::MakeSphere(AttackRadius),
		Params);

	if (DebugMode)
	{
		FVector Vec = GetActorForwardVector() * AttackRange;
		FVector Center = GetActorLocation() + Vec * 0.5f;
		float HalfHeight = AttackRange * 0.5f + AttackRadius;
		FQuat Rotation = FRotationMatrix::MakeFromZ(Vec).ToQuat();
		FColor DrawColor;

		if (bResult)
		{
			DrawColor = FColor::Green;
		}
		else
		{
			DrawColor = FColor::Red;
		}

		DrawDebugCapsule(GetWorld(), Center, HalfHeight, AttackRadius, Rotation, DrawColor, false, 2.f);
	}

	if (bResult && HitResult.Actor.IsValid())
	{
		UE_LOG(LogTemp, Log, TEXT("Hit Actor : %s, %d"), *HitResult.Actor->GetName(), Stat->GetAttack());
	}
}
