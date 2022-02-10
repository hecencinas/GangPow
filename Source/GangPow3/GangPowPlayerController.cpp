// Fill out your copyright notice in the Description page of Project Settings.


#include "GangPowPlayerController.h"

void AGangPowPlayerController::BeginPlay()
{
	//GameState = GetWorld()->GetGameState<class AGameStateBase>();
}

void AGangPowPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	if (InputComponent)
	{
		InputComponent->BindAction(TEXT("Select"), EInputEvent::IE_Pressed, this, &AGangPowPlayerController::RequestSelect);
		InputComponent->BindAction(TEXT("Select"), EInputEvent::IE_Released, this, &AGangPowPlayerController::RequestStopSelect);
	}
}

void AGangPowPlayerController::RequestSelect()
{
	UE_LOG(LogTemp, Warning, TEXT("process"));
	if (!CanProcessRequest())
	{
		return;
	}

	switch(PlayingState)
	{
	case EPlayingState::Selecting:
		
		break;
	case EPlayingState::Shooting:
		break;
	case EPlayingState::Walking:
		
		break;
	}
}

void AGangPowPlayerController::RequestStopSelect()
{
	UE_LOG(LogTemp, Warning, TEXT("process"));
	if (!CanProcessRequest())
	{
		return;
	}

	switch(PlayingState)
	{
	case EPlayingState::Selecting:
		
		break;
	case EPlayingState::Shooting:
		break;
	case EPlayingState::Walking:
		
		break;
	}
}

bool AGangPowPlayerController::CanProcessRequest()
{
	return (PlayingState != EPlayingState::None && PlayingState != EPlayingState::EnemyPlaying);
}