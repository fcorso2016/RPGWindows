// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Runtime/Engine/Classes/Engine/DataTable.h"
#include "Runtime/UMG/Public/Components/Image.h"
#include "Runtime/Engine/Classes/Engine/Texture.h"
#include "Runtime/UMG/Public/Components/CanvasPanel.h"
#include "GameFramework/PlayerController.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Windows)
		UTexture* Cursor;

};

/**
 * The superclass from which all other windows are generated.
 */
UCLASS(Blueprintable)
class RPGWINDOWS_API UWindowBase : public UUserWidget {
	GENERATED_BODY()

protected:

	// Height and width values for the tiles
	static const float TILE_WIDTH;
	static const float TILE_HEIGHT;

	// Defines the distance between the window edge and where content can be displayed
	static const float FRAME_THICKNESS;

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

	// The main body of the window
	UPROPERTY(BlueprintReadOnly, Category = Components, meta = (BindWidget))
		UCanvasPanel* MainBody;

	// Rebuilt the Widget
	virtual TSharedRef<SWidget> RebuildWidget() override;

	/**
	* Gets the controller for the window
	*/
	UFUNCTION(BlueprintPure, Category = Input)
		APlayerController* GetController() const;

	/**
	* Sets the controller for the window
	* @param NewController - the new controller object to be used
	*/
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetController(APlayerController* NewController);

	/** 
	* Change the windowskin and redraw the windowskin components 
	* @param NewWindowskin - The name of the new target windowskin
	*/
	UFUNCTION(BlueprintCallable, Category = Window)
		void ChangeWindowskin(FName NewWindowskin);

protected:

	/**
	* Generates the visual representation of the window.
	* @param Width - the width of the window
	* @param Height - the height of the window
	*/
	void DrawWindowBackground(float Width, float Height);

	/**
	* Draws any contents to the window
	*/
	virtual void DrawWindowContents();

	/**
	* Used to update the size of the window when redrawing (only works when slotted in another widget)
	*/
	void SetSlottedSize();

	/**
	* Returns the minimum size of the window in question
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual FVector2D MinimumSize();

	/**
	* Automatically adjusts the size of the window
	*/
	virtual void ResizeWindow();

	/**
	* Place tiles for a canvas based setup
	* @param Windowskin - the windowskin being rendered
	* @param Width - the width of the window
	* @param Height - the height of the window
	*/
	void PlaceTilesCanvas(FWindowskin* Windowskin);

	/**
	* Place tiles for a non-canvas based setup
	* @param Windowskin - the windowskin being rendered
	* @param Width - the width of the window
	* @param Height - the height of the window
	*/
	void PlaceTilesNonCanvas(FWindowskin* Windowskin, float Width, float Height);

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

public:
	
	/**
	* Special resizing function that also updates the window as well
	* @param Size - The new size of the widget
	*/
	UFUNCTION(BlueprintCallable, Category = "UserInterface|Viewport")
		void SetDesiredSizeOfWindow(FVector2D Size);
	
protected:
	/** The Data Table from which the windowskin are drawn from */
	UPROPERTY(EditAnywhere, Category = Window)
		UDataTable* Windowskins;

	/** The row name of the current windowskin */
	UPROPERTY(EditAnywhere, Category = Window)
		FName WindowskinName;

	/** The scale of the window skin */
	UPROPERTY(EditAnywhere, Category = Window, meta = (UIMin = 1, ClampMin = 1))
		int WindowScale;

	/** The scale of the window skin */
	UPROPERTY(EditAnywhere, Category = Window, meta = (UIMin = 1, ClampMin = 1))
		int FrameScale;

	/** The width of the window */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		float Width;

	/** The height of the window */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		float Height;

	/** Tells the window if it should be automatically resized or not */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		bool AutoResize;

	// The controller object used by the menu
	UPROPERTY()
		APlayerController* Controller;

};
