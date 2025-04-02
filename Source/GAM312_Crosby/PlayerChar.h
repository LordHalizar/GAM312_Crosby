// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Camera/CameraComponent.h"
#include "Resource_M.h"
#include <Kismet/GameplayStatics.h>
#include "BuildingPart.h"
#include "PlayerWidget.h"
#include "ObjectiveWidget.h"
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
		// Variable for camera component
		UCameraComponent* PlayerCamComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		// Variable setup for player health default value
		float Health = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		// Variable setup for player default hunger
		float Hunger = 100.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Stats")
		// Variable setup for player default stamina
		float Stamina = 100.0f;

	UPROPERTY(EditAnywhere, Category = "Resources")
		// Integer variable setup for wood resource
		int Wood;

	UPROPERTY(EditAnywhere, Category = "Resources")
		// Integer variable setup for stone resource
		int Stone;

	UPROPERTY(EditAnywhere, Category = "Resources")
		// Integer variable setup for berry resource
		int Berry;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Resources")
		// Array variable setup for assigned resource integer values
		TArray<int> ResourcesArray;

	UPROPERTY(EditAnywhere, Category = "Resources")
		// Array variable setup for resource names
		TArray<FString> ResourcesNameArray;

	UPROPERTY(EditAnywhere, Category = "HitMarker")
		UMaterialInterface* hitDecal;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building Supplies")
		// Array for storing information on the number of building parts available to the player
		TArray<int> BuildingArray;

	UPROPERTY()
		// Boolean variable for use in determining whether player is currently in building mode or not
		bool isBuilding;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
		// Class variable for the selection and creation of different building parts
		TSubclassOf<ABuildingPart> BuildingPartClass;

	UPROPERTY()
		// Variable meant to represent chosen building part to be spawned
		ABuildingPart* spawnedPart;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UPlayerWidget* playerUI;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UObjectiveWidget* objWidget;

	UPROPERTY()
		float objectsBuilt;

	UPROPERTY()
		float matsCollected;

	UFUNCTION(BlueprintCallable)
		// Setup for Health function
		void SetHealth(float amount);

	UFUNCTION(BlueprintCallable)
		// Setup for Hunger function
		void SetHunger(float amount);

	UFUNCTION(BlueprintCallable)
		// Setup for Stamina function
		void SetStamina(float amount);

	UFUNCTION()
		// Setup for DecreaseStats function
		void DecreaseStats();

	UFUNCTION()
		// Setup for GiveResource function
		void GiveResource(float amount, FString resourceType);

	UFUNCTION(BlueprintCallable)
		// Updates resources based on resource amounts needed to build selected building part
		void UpdateResources(float woodAmount, float stoneAmount, FString buildingObject);

	UFUNCTION(BlueprintCallable)
		// Function that spawns the selected building part
		void SpawnBuilding(int buildingID, bool& isSuccess);

	UFUNCTION()
		// Function that allows for the rotation of built building parts
		void RotateBuilding();
};
