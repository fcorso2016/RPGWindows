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

	// The main body of the window
	UPROPERTY(BlueprintReadOnly, Category = Components, meta = (BindWidget))
		UCanvasPanel* MainBody;

	// Rebuilt the Widget
	virtual TSharedRef<SWidget> RebuildWidget() override;
	
};
