// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "SelectionWindow.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "CommandWindow.generated.h"

/** Delegate for when the user selects a command in the command window */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FProcessCommand, FName, CommandName);

/**
* The information for a command in the game.
*/
USTRUCT(BlueprintType)
struct FWindowCommand {
	GENERATED_BODY()

public:

	/** The name of the command */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Commands)
		FText Name;

	/** The access code used for binding */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Commands)
		FName InternalName;

	/** Is the command selectabled? */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Commands)
		bool Selectable = true;

};

/**
 * Window display a list of commands to be selected from
 */
UCLASS(HideCategories = "Selection|Confirm")
class RPGWINDOWS_API UCommandWindow : public USelectionWindow {
	GENERATED_BODY()
	
public:
	// Constructor
	UCommandWindow(const FObjectInitializer& ObjectInitializer);

	// The main body of the window
	UPROPERTY(BlueprintReadOnly, Category = Components)
		TArray<UTextBlock*> CommandWidgets;

	// Draw the element in the contents field
	virtual void DrawItem(int Index) override;

	//The number of selectable elements in the window
	virtual int ElementCount();

	// Process the input when the player confirms an options
	virtual void ProcessConfirm();

	/** An array of command deleagates */
	UPROPERTY(BlueprintAssignable, Category = "Selection|Commands")
		FProcessCommand OnCommand;

private:

	/** The list of commands of the window */
	UPROPERTY(EditAnywhere, Category = Commands)
		TArray<FWindowCommand> CommandList;

	/** The font sized used by the window */
	UPROPERTY(EditAnywhere, Category = Commands)
		FSlateFontInfo Font;
	
};
