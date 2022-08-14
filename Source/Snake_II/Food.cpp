// Fill out your copyright notice in the Description page of Project Settings.

#include "Food.h"
#include "GameFramework/Actor.h"
#include "SnakeBase.h"
#include "PlayerPawnBase.h"
#include "Snake_IIGameModeBase.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
AFood::AFood()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


}
// Called when the game starts or when spawned
void AFood::BeginPlay()
{
}


// Called every frame
void AFood::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFood::Interact(AActor* Interactor, bool bIsHead)
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			ASnake_IIGameModeBase* game_mode = Cast<ASnake_IIGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
			if (game_mode)
			{
				game_mode->CreateFoodActor();
				game_mode->CreateSpeedUpActor();
				++game_mode->SnakeLength;
			}
			Snake->AddSnakeElement();
			this->Destroy();//!!!
		}
	}
}

