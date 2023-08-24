// Fill out your copyright notice in the Description page of Project Settings.


#include "DHCharacterAnimInstance.h"
#include "GameFramework/Character.h"
#include "GameFramework/PawnMovementComponent.h"
#include "DHCharacter.h"

void UDHCharacterAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto Pawn = TryGetPawnOwner();
	if (IsValid(Pawn))
	{
		auto Velocity = Pawn->GetVelocity();
		auto DeltaV = Velocity - PreviousVelocity;

		Speed = Velocity.Size();
		CurrentAcceleration = DeltaV / DeltaSeconds;

		IsAccelerating = CurrentAcceleration.Size() > 0.0f
			? true
			: false;

		auto Character = Cast<ADHCharacter>(Pawn);

		if (Character)
		{
			auto Movement = Character->GetMovementComponent();
			IsFalling = Movement->IsFalling();
		}

		PreviousVelocity = Velocity;
	}
}

void UDHCharacterAnimInstance::PlayAttackMontage()
{
	// 자식 클래스에서 override
}

void UDHCharacterAnimInstance::AnimNotify_AttackHit()
{
	OnAttackHit.Broadcast();
}
