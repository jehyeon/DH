// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DHCharacter.h"
#include "MeleeMinion.generated.h"

/**
 * 
 */
UCLASS()
class DH_API AMeleeMinion : public ADHCharacter
{
	GENERATED_BODY()

protected:
	virtual void PostInitializeComponents() override;
	virtual void AttackCheck() override;
};
