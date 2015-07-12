// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerCube.generated.h"

UCLASS()
class CUBEWARS_API APlayerCube : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerCube();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;

	// Return custom movement
	virtual UPawnMovementComponent* GetMovementComponent() const override;

protected:

	UFUNCTION(Server, WithValidation, unreliable)
	void MoveHorizontal(float value);

	void Turn(float value);

	void OnStartFire();

	void OnStopFire();

	FRotator InitinalRotation;

	UPROPERTY(EditAnywhere, Category = Stats)
	float TurnRate;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UBoxComponent* CubeCollisionComponent;

	UPROPERTY(VisibleAnywhere, Category = Components)
	UStaticMeshComponent* CubeVisual;

	UPROPERTY(VisibleAnywhere, Category = Components)
	class UPlayerCubeMovementComponent* CubeMovement;
	
};
