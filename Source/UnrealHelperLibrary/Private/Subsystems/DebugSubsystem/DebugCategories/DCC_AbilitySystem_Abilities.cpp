// Fill out your copyright notice in the Description page of Project Settings.


#include "Subsystems/DebugSubsystem/DebugCategories/DCC_AbilitySystem_Abilities.h"

#include "Kismet/KismetSystemLibrary.h"

void UDCC_AbilitySystem_Abilities::Activate_Implementation(UObject* ContextObject)
{
    UKismetSystemLibrary::ExecuteConsoleCommand(ContextObject->GetWorld(), FString("showdebug abilitysystem"));
    UKismetSystemLibrary::ExecuteConsoleCommand(ContextObject->GetWorld(), FString("AbilitySystem.Debug.SetCategory Ability"));
    return Super::Activate_Implementation(ContextObject);
}

void UDCC_AbilitySystem_Abilities::Deactivate_Implementation(UObject* ContextObject)
{
    UKismetSystemLibrary::ExecuteConsoleCommand(ContextObject->GetWorld(), FString("showdebug reset"));
    Super::Deactivate_Implementation(ContextObject);
}