// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "PaperSprite.h"
#include "WindowBase.generated.h"

/**
* The struct that gets all the images used for each windowskin.
*/
USTRUCT(BlueprintType)
struct FWindowskin : public FTableRowBase {
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* TopLeftTile;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* TopMiddleTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* TopRightTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* MiddleLeftTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* CenterTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* MiddleRightTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* BottomLeftTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* BottomMiddleTile;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UPaperSprite* BottomRightTile;

};

/**
 * The superclass from which all other windows are generated.
 */
UCLASS(Blueprintable)
class RPGWINDOWS_API UWindowBase : public UUserWidget {
	GENERATED_BODY()

	// Height and width values for the tiles
	static const float TILE_WIDTH;
	static const float TILE_HEIGHT;

	// Tile objects
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* TopLeftTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* TopMiddleTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* TopRightTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* MiddleLeftTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* CenterTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* MiddleRightTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* BottomLeftTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* BottomMiddleTile;
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		UImage* BottomRightTile;
	
public:
	// Constructor
	UWindowBase(const FObjectInitializer& ObjectInitializer);

	// Constructs the Widget
	virtual void NativeConstruct() override;

	// Rebuilt the Widget
	virtual TSharedRef<SWidget> RebuildWidget() override;

	/** 
	* Change the windowskin and redraw the windowskin components 
	* @param NewWindowskin - The name of the new target windowskin
	*/
	UFUNCTION(BlueprintCallable, Category = Windows)
		void ChangeWindowskin(FName NewWindowskin);

protected:

	/**
	* Generates the visual representation of the window.
	* @param Width - the width of the window
	* @param Height - the height of the window
	*/
	void DrawWindowBackground(float Width, float Height);

	/**
	* Sets the position and size of a window component
	* @param Tile - The tile being opperated on
	* @param Sprite - The sprite used to draw the tile on the screen
	* @param X - The x-coordinate of the the tile
	* @param Y - The y-coordinate of the the tile
	* @param Width - The width of the the tile
	* @param Height - The height of the the tile
	*/
	void PlaceTile(UImage* Tile, UPaperSprite* Sprite, float X, float Y, float Width, float Height);

	/** The width of the window */
	UPROPERTY(BlueprintReadOnly, Category = Windows)
		float Width;

	/** The height of the window */
	UPROPERTY(BlueprintReadOnly, Category = Windows)
		float Height;

public:
	
	// Called when setting the desired size

	
private:
	/** The Data Table from which the windowskin are drawn from */
	UPROPERTY(EditAnywhere, Category = Windows)
		UDataTable* Windowskins;

	/** The row name of the current windowskin */
	UPROPERTY(EditAnywhere, Category = Windows)
		FName WindowskinName;

};
