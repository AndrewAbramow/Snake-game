// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Food.h"
#include "SpeedUp.h"
#include "Barrier.h"
#include "GameFramework/GameModeBase.h"
#include "Snake_IIGameModeBase.generated.h"

UCLASS()
class SNAKE_II_API ASnake_IIGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:

	ASnake_IIGameModeBase();
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
public:
	virtual ~ASnake_IIGameModeBase() = default;

	UPROPERTY(EditDefaultsOnly)//!
		TSubclassOf <AFood> FoodActorClass;//!

	void CreateFoodActor();//!

	UPROPERTY(EditDefaultsOnly)//!
		TSubclassOf <ASpeedUp> SpeedUpActorClass;//!

	void CreateSpeedUpActor();//!

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpeedUpRand")//!!!
		int SpeedUpRandom = 50;//!!!

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpeedUpRate")//!!!
		float SpeedUpRate = 0.125;//!!!

	float GetSpeedUpRate();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SnakeLength")//!!!
		int SnakeLength = 1;//!!!

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EndGame")//!!!
		bool EndGame = false;//!!!

	int GetSnakeLength();

	//UPROPERTY(EditDefaultsOnly)//!!!
	//	TSubclassOf<ABarrier> BarrierActorClass;//!!!

	//UPROPERTY()//!!!
	//	TArray<ABarrier*> BarrierElements;//!!!

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BarriersAmount")//!!!
	//	int BarriersAmount = 3;//!!!

	//void CreateBarrierActor();//!

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Hidden")//!!!
		bool Hidden = false;//!!!

	//bool GetHiddenActor();

};
