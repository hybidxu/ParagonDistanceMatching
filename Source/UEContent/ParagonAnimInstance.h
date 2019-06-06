// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "ParagonAnimInstance.generated.h"

/**
 *
 */
UCLASS()
class UECONTENT_API UParagonAnimInstance : public UAnimInstance
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, Category = Animation)
	bool IsAccelerating = false;

	UPROPERTY(BlueprintReadOnly, Category = Animation)
	float JogDistanceCurveStartTime = 0;

	UPROPERTY(BlueprintReadOnly, Category = Animation)
	float JogDistanceCurveStopTime = 0;

	UPROPERTY(BlueprintReadOnly, Category = Animation)
	FVector DistanceMachingLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	UAnimSequence* JogStartAnimSequence = nullptr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Animation)
	UAnimSequence* JogStopAnimSequence = nullptr;
public:
	virtual void NativeInitializeAnimation() override;
	virtual void NativeUpdateAnimation(float DeltaTimeX) override;
private:
	void UpdateDistanceMatching(float DeltaTimeX);
	void EvalDistanceMatching(float DeltaTimeX);
};
