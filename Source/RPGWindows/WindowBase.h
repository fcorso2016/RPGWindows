// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "WindowBase.generated.h"

/**
* 
*/
USTRUCT(BlueprintType)
struct FWindowSkin : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* TopLeftTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* TopMiddleTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* TopRightTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* MiddleLeftTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* CenterTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* MiddleRightTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* BottomLeftTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* BottomMiddleTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* BottomRightTile;

};

/**
 * 
 */
UCLASS()
class RPGWINDOWS_API UWindowBase : public UUserWidget {
	GENERATED_BODY()
	
	
	
	
};
