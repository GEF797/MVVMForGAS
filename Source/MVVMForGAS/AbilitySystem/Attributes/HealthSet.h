// Copyright G.E.FC 2023

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "HealthSet.generated.h"



#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

/**
 * 
 */
UCLASS()
class  UHealthSet : public UAttributeSet
{
	GENERATED_BODY()
	

public:

	UHealthSet();

	ATTRIBUTE_ACCESSORS(UHealthSet, Health);
	ATTRIBUTE_ACCESSORS(UHealthSet, MaxHealth);

	ATTRIBUTE_ACCESSORS(UHealthSet, Mana);
	ATTRIBUTE_ACCESSORS(UHealthSet, MaxMana);

	ATTRIBUTE_ACCESSORS(UHealthSet, EP);
	ATTRIBUTE_ACCESSORS(UHealthSet, MaxEP);

	ATTRIBUTE_ACCESSORS(UHealthSet, Exp);
	ATTRIBUTE_ACCESSORS(UHealthSet, UpgradeExp);


protected:

	UFUNCTION()
		void OnRep_Health(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MaxHealth(const FGameplayAttributeData& OldValue);


	UFUNCTION()
		void OnRep_Mana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MaxMana(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_EP(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_MaxEP(const FGameplayAttributeData& OldValue);


	UFUNCTION()
		void OnRep_Exp(const FGameplayAttributeData& OldValue);

	UFUNCTION()
		void OnRep_UpgradeExp(const FGameplayAttributeData& OldValue);

	//virtual bool PreGameplayEffectExecute(FGameplayEffectModCallbackData& Data) override;
	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data) override;

	virtual void PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const override;
	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue) override;
	virtual void PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue) override;

	void ClampAttribute(const FGameplayAttribute& Attribute, float& NewValue) const;

private:

	// The current health attribute.  The health will be capped by the max health attribute.  Health is hidden from modifiers so only executions can modify it.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Health, Category = "|Health", Meta = (/*HideFromModifiers,*/ AllowPrivateAccess = true))
		FGameplayAttributeData Health;

	// The current max health attribute.  Max health is an attribute since gameplay effects can modify it.
	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxHealth, Category = "|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData MaxHealth;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Mana, Category = "|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Mana;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxMana, Category = "|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData MaxMana;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_EP, Category = "|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData EP;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxEP, Category = "|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData MaxEP;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_Exp, Category = "|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData Exp;


	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_UpgradeExp, Category = "|Health", Meta = (AllowPrivateAccess = true))
		FGameplayAttributeData UpgradeExp;

	// Used to track when the health reaches 0.
	bool bOutOfHealth;

	bool bOutOfMana;

	bool bOutOfEP;

	bool bOutOfExp;

	// -------------------------------------------------------------------
	//	Meta Attribute (please keep attributes that aren't 'stateful' below 
	// -------------------------------------------------------------------


};
