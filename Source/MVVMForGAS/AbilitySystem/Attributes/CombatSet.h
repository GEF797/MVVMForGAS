// Copyright G.E.FC 2023

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "CombatSet.generated.h"

class UAbilitySystemComponent;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class  UCombatSet : public UAttributeSet
{
	GENERATED_BODY()
public:

	UCombatSet();

	ATTRIBUTE_ACCESSORS(UCombatSet, Attack);
	ATTRIBUTE_ACCESSORS(UCombatSet, Defense);
	ATTRIBUTE_ACCESSORS(UCombatSet, Speed);
	ATTRIBUTE_ACCESSORS(UCombatSet, MagicAttack);
	ATTRIBUTE_ACCESSORS(UCombatSet, MagicDefense);
	ATTRIBUTE_ACCESSORS(UCombatSet, Critical);
	ATTRIBUTE_ACCESSORS(UCombatSet, CriticalRate);
	ATTRIBUTE_ACCESSORS(UCombatSet, Penetrated);
	ATTRIBUTE_ACCESSORS(UCombatSet, MagicPenetrated);




protected:

	UFUNCTION()
		void OnRep_Attack(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_Defense(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MagicAttack(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MagicDefense(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_Speed(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_Critical(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_CriticalRate(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_Penetrated(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MagicPenetrated(const FGameplayAttributeData& OldValue);



private:



	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Attack, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Attack;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Defense, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Defense;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicAttack, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData MagicAttack;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicDefense, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData MagicDefense;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Speed, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Speed;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Critical, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Critical;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_CriticalRate, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData CriticalRate;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Penetrated, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Penetrated;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MagicPenetrated, Category = "Lyra|RPG", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData MagicPenetrated;

};
