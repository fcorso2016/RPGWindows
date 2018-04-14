// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "SelectionWindow.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "CommandWindow.generated.h"

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
UCLASS()
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

private:

	/** The list of commands of the window */
	UPROPERTY(EditAnywhere, Category = Commands)
		TArray<FWindowCommand> CommandList;

	/** The font sized used by the window */
	UPROPERTY(EditAnywhere, Category = Commands)
		FSlateFontInfo Font;
	
};
