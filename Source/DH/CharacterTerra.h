// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "DHCharacter.h"
#include "CharacterTerra.generated.h"

/**
 * 
 */
UCLASS()
class DH_API ACharacterTerra : public ADHCharacter
{
	GENERATED_BODY()

protected:
	virtual void AttackCheck() override;
};
