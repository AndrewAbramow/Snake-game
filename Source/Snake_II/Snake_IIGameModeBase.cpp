// Fill out your copyright notice in the Description page of Project Settings.


#include "Snake_IIGameModeBase.h"

ASnake_IIGameModeBase::ASnake_IIGameModeBase() {}

void ASnake_IIGameModeBase::BeginPlay() {
	CreateFoodActor();
	CreateSpeedUpActor();
	//CreateBarrierActor();
}

void ASnake_IIGameModeBase::CreateFoodActor()
{
	float InTransX = FMath::FRandRange(-200.0f, 200.0f);// random initial place
	float InTransY = FMath::FRandRange(-200.0f, 200.0f);
	FVector InTranslation(InTransX, InTransY, -70);// 
	AFood* NewFood = GetWorld()->SpawnActor<AFood>(FoodActorClass, FTransform(InTranslation));//!
}

void ASnake_IIGameModeBase::CreateSpeedUpActor()
{
	int rand = FMath::FRandRange(0, 100);
	if (rand > SpeedUpRandom) {
		float InTransX = FMath::FRandRange(-200.0f, 200.0f);// random initial place
		float InTransY = FMath::FRandRange(-200.0f, 200.0f);
		FVector InTranslation(InTransX, InTransY, -70);// 
		ASpeedUp* NewSpeedUp = GetWorld()->SpawnActor<ASpeedUp>(SpeedUpActorClass, FTransform(InTranslation));//!
	}
}

float ASnake_IIGameModeBase::GetSpeedUpRate() {
	return SpeedUpRate;
}
int ASnake_IIGameModeBase::GetSnakeLength() {
	return SnakeLength;
}

//bool ASnake_IIGameModeBase::GetHiddenActor() {
//	return Hidden;
//}

//void ASnake_IIGameModeBase::CreateBarrierActor()
//{
//	for (int i = 0; i < BarriersAmount; ++i) {
//		float InTransX = FMath::FRandRange(-200.0f, 200.0f);// random initial place
//		float InTransY = FMath::FRandRange(-200.0f, 200.0f);
//		FVector InTranslation(InTransX, InTransY, -70);// 
//		ABarrier* NewBarrier = GetWorld()->SpawnActor<ABarrier>(BarrierActorClass, FTransform(InTranslation));//!
//		BarrierElements.Add(NewBarrier);
//	}
//}

