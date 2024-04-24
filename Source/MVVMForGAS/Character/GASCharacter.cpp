// Copyright G.E.FC 2023

#include "GASCharacter.h"
#include "AbilitySystemComponent.h"
#include "../AbilitySystem/Attributes/HealthSet.h"
#include "../AbilitySystem/Attributes/CombatSet.h"


// Sets default values
AGASCharacter::AGASCharacter(const FObjectInitializer& ObjectInitializer)
:Super(ObjectInitializer)
{
	AbilitySystemComponent = ObjectInitializer.CreateDefaultSubobject<UAbilitySystemComponent>(this, TEXT("AbilitySystemComponent"));
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);

	// These attribute sets will be detected by AbilitySystemComponent::InitializeComponent. Keeping a reference so that the sets don't get garbage collected before that.
	HealthSet = CreateDefaultSubobject<UHealthSet>(TEXT("HealthSet"));
	CombatSet = CreateDefaultSubobject<UCombatSet>(TEXT("CombatSet"));

	// AbilitySystemComponent needs to be updated at a high frequency.
	NetUpdateFrequency = 100.0f;

}

void AGASCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	check(AbilitySystemComponent);
	AbilitySystemComponent->InitAbilityActorInfo(this, this);
}

UAbilitySystemComponent* AGASCharacter::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}



