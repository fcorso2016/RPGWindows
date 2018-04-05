// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "WindowBase.generated.h"

/**
* The struct that gets all the images used for each windowskin.
*/
USTRUCT(BlueprintType)
struct FWindowskin : public FTableRowBase {
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
 * The superclass from which all other windows are generated.
 */
UCLASS(Blueprintable)
class RPGWINDOWS_API UWindowBase : public UUserWidget {
	GENERATED_BODY()
	
public:
	// Constructor
	UWindowBase(const FObjectInitializer& ObjectInitializer);

	// Constructs the Widget
	virtual void NativeConstruct() override;

	/**
	* Generates the visual representation of the window.
	*/
	void DrawWindowBackground();

	/** 
	* Change the windowskin and redraw the windowskin components 
	* @param NewWindowskin - The name of the new target windowskin
	*/
	UFUNCTION(BlueprintCallable, Category = Windows)
		void ChangeWindowskin(FName NewWindowskin);
	
private:
	/** The Data Table from which the windowskin are drawn from */
	UPROPERTY(EditAnywhere, Category = Windows)
		UDataTable* Windowskins;

	/** The row name of the current windowskin */
	UPROPERTY(EditAnywhere, Category = Windows)
		FName WindowskinName;

};
