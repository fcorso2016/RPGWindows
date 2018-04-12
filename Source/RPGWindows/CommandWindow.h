// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "SelectionWindow.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "CommandWindow.generated.h"

/**
 * Window display a list of commands to be selected from
 */
UCLASS()
class RPGWINDOWS_API UCommandWindow : public USelectionWindow {
	GENERATED_BODY()
	
public:

	// Draw the element in the contents field
	virtual void DrawItem(int X, int Y) override;

	//The number of selectable elements in the window
	virtual int ElementCount();

	/** The array of text elements */
	UPROPERTY(VisibleDefaultsOnly, Category = Components)
		TArray<UTextBlock*> CommandBlocks;

private:
	/** The list of commands of the window */
	UPROPERTY(EditAnywhere, Category = Commands)
		TArray<FString> CommandList;
	
};
