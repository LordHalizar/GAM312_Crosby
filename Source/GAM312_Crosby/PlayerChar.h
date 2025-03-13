// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include <Kismet/GameplayStatics.h>
#include "PlayerChar.generated.h"

UCLASS()
class GAM312_CROSBY_API APlayerChar : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerChar();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		// Movement fucntion for forward and backward movement based on positive (w) or negative (s) integer input
		void MoveForward(float axisValue);

	UFUNCTION()
		// Movement function for left and right movement based on positive (d) or negative (a) integer input
		void MoveRight(float axisValue);

	UFUNCTION()
		// Movement function for the initiation of jumping event movement
		void StartJump();

	UFUNCTION()
		// Movement function for the ending of jumping event movement
		void StopJump();

	UFUNCTION()
		void FindObject();

	UPROPERTY(VisibleAnywhere)
		UCameraComponent* PlayerCamComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		// Defined variable for player health
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		// Defined variable for player hunger
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		// Defined variable for player stamina
		float Stamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Stone;

	UPROPERTY(EditAnywhere, Category = "Resources")
		int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
		TArray<FString> ResourcesNameArray;

	UPROPERTY(EditAnywhere, Category = "HitMarker")
		UMaterialInterface* hitDecal;

	UFUNCTION(BlueprintCallable)
		void SetHealth(float amount);

	UFUNCTION()
		void SetHunger(float amount);

	UFUNCTION()
		void SetStamina(float amount);

	UFUNCTION()
		void DecreaseStats();

	UFUNCTION()
		void GiveResource(float amount, FString resourceType);
};
