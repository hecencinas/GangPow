// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "GangPowPlayerController.generated.h"

UENUM(BlueprintType)
enum class EPlayingState : uint8
{
	None			UMETA(DisplayName = "None"),
	Selecting		UMETA(DisplayName = "Selecting"),
	Shooting		UMETA(DisplayName = "Shooting"),
	Walking			UMETA(DisplayName = "Walking"),
	Waiting			UMETA(DisplayName = "Waiting"),
	EnemyPlaying	UMETA(DisplayName = "EnemyPlaying")
};


/**
 * 
 */
UCLASS()
class GANGPOW3_API AGangPowPlayerController : public APlayerController
{
	GENERATED_BODY()

protected:
	void SetupInputComponent() override;

	void RequestSelect();
	void RequestStopSelect();

	bool CanProcessRequest();

	UPROPERTY(VisibleAnywhere, /*ReplicatedUsing = OnRep_GameState,*/ Category = "States")
	EPlayingState PlayingState = EPlayingState::None;

	//UPROPERTY()
	//class AGameStateBase* GameState;
	
public:
	UFUNCTION(BlueprintPure)
	EPlayingState GetCurrentPlayingState() const { return PlayingState; }
	
	
};
