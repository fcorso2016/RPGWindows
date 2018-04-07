// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "WindowBase.h"
#include "SelectionWindow.generated.h"

/**
 * Superclass used for creating menus where the player can selection options from.
 */
UCLASS()
class RPGWINDOWS_API USelectionWindow : public UWindowBase {
	GENERATED_BODY()

public:
	// Construct
	USelectionWindow(const FObjectInitializer& ObjectInitializer);

	// Rebuilt the Widget
	virtual TSharedRef<SWidget> RebuildWidget() override;

	/** Get the currently selected index of the window */
	UPROPERTY(BlueprintReadOnly, Category = Window)
		int Index;

	/**
	* Sets the index of the window and sets that information visually
	* @param NewIndex - the new index of the window
	*/
	UFUNCTION(BlueprintCallable, Category = Window)
		virtual void SetIndex(int NewIndex);

	/**
	* The number of selectable elements in the window
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual int ElementCount();

	/**
	* Dictates if the player can confirm an option or not
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual bool CanConfirm();

	/**
	* Dictates if the player can cancel an option or not
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual bool CanCancel();
	
};
