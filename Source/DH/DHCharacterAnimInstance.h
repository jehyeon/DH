// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "DHCharacterAnimInstance.generated.h"

UCLASS()
class DH_API UDHCharacterAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	//UFUNCTION(BlueprintCallable)
	//bool IsAccelerating()
	//{
	//	return CurrentAcceleration.Size() > 0.0f;
	//}

public:
	virtual void PlayAttackMontage();

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	float Speed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsFalling;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	bool IsAccelerating;

	UPROPERTY()
	FVector PreviousVelocity = FVector::ZeroVector;

	UPROPERTY()
	FVector CurrentAcceleration = FVector::ZeroVector;
};
