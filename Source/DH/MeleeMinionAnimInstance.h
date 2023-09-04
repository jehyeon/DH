// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DHCharacterAnimInstance.h"
#include "MeleeMinionAnimInstance.generated.h"

/**
 * 
 */
UCLASS()
class DH_API UMeleeMinionAnimInstance : public UDHCharacterAnimInstance
{
	GENERATED_BODY()
	
public:
	UMeleeMinionAnimInstance();

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;

	void PlayAttackMontage() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Pawn, Meta = (AllowPrivateAccess = true))
	UAnimMontage* AttackMontage;

	UPROPERTY()
	float temp = 3.f;
};
