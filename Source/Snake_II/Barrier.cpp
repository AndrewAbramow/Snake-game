// Fill out your copyright notice in the Description page of Project Settings.


#include "Barrier.h"
#include "Snake_IIGameModeBase.h"
#include "Kismet/GameplayStatics.h"
#include "SnakeBase.h"

// Sets default values
ABarrier::ABarrier()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABarrier::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ABarrier::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABarrier::Interact(AActor* Interactor, bool bIsHead)//!
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			Snake->Destroy();

			ASnake_IIGameModeBase* game_mode = Cast<ASnake_IIGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
			if (game_mode)
			{
				game_mode->EndGame = true;
			}

		}
	}
}

