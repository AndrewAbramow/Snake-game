// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Interactable.h"//!
#include "Barrier.generated.h"


UCLASS()
class SNAKE_II_API ABarrier : public AActor, public IInteractable
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABarrier();

	UPROPERTY(EditDefaultsOnly)//!!!
		TSubclassOf<ABarrier> BarrierElementClass;//!!!

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void Interact(AActor* Interactor, bool bIsHead) override;//!
};
