// Fill out your copyright notice in the Description page of Project Settings.


#include "SpeedUp.h"
#include "SnakeBase.h"
#include "Snake_IIGameModeBase.h"
#include "Kismet/GameplayStatics.h"


// Sets default values
ASpeedUp::ASpeedUp()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//int ElementNumb = 3;

}

// Called when the game starts or when spawned
void ASpeedUp::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASpeedUp::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASpeedUp::Interact(AActor* Interactor, bool bIsHead)//!
{
	if (bIsHead)
	{
		auto Snake = Cast<ASnakeBase>(Interactor);
		if (IsValid(Snake))
		{
			ASnake_IIGameModeBase* game_mode = Cast<ASnake_IIGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
			if (game_mode)
			{
				Snake->MovementSpeed *= game_mode->GetSpeedUpRate();
				Snake->SetActorTickInterval(Snake->MovementSpeed);
			}
			this->Destroy();
		}
	}
}
