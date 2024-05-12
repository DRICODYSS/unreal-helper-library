// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BTD_Base.h"
#include "BehaviorTree/BTCompositeNode.h"
#include "BehaviorTree/BTDecorator.h"
#include "BTD_InRange.generated.h"

struct FBTInRangeMemory
{
	float CurrentDistance = 0.0f;
};

/**
 * 
 */
UCLASS()
class UNREALHELPERLIBRARY_API UBTD_InRange : public UBTD_Base
{
	GENERATED_BODY()

public:
	UBTD_InRange(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(Category=Decorator, EditAnywhere, meta=(EditCondition="", EditConditionHides))
	FBlackboardKeySelector Target;
	UPROPERTY(Category=Decorator, EditAnywhere, meta=(EditCondition="", EditConditionHides))
	float Min = 0.0f;
	UPROPERTY(Category=Decorator, EditAnywhere, meta=(EditCondition="", EditConditionHides))
	float Max = 500.0f;
	// Should we exclude Self character capsule radius from distance
	// mostly for big enemies
	// compliant with "MoveTo"
	/** if set, radius of AI's capsule will be added to threshold between AI and goal location in destination reach test  */
	UPROPERTY(Category=Decorator, EditAnywhere)
	bool bIncludeSelfCapsuleRadius = false;
	// Should we exclude Target character capsule radius from distance
	/** if set, radius of Target's capsule will be added to threshold between AI and goal location  */
	UPROPERTY(Category=Decorator, EditAnywhere)
	bool bIncludeTargetCapsuleRadius = false;

	virtual bool CalculateRawConditionValue(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory) const override;

	virtual void InitializeMemory(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTMemoryInit::Type InitType) const override;
	virtual uint16 GetInstanceMemorySize() const override;
	
	virtual FString GetStaticDescription() const override;
	virtual void DescribeRuntimeValues(const UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, EBTDescriptionVerbosity::Type Verbosity, TArray<FString>& Values) const override;
	virtual FName GetNodeIconName() const override;

	float GetCurrentDistance(const UBehaviorTreeComponent& OwnerComp) const;

	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;
};