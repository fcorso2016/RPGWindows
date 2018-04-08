// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/PlayerController.h"
#include "WindowBase.h"
#include "MenuBase.generated.h"

/**
 * Base class used for all menu widgets in the game
 */
UCLASS()
class RPGWINDOWS_API UMenuBase : public UUserWidget {
	GENERATED_BODY()

public:

	// Rebuilt the Widget
	virtual TSharedRef<SWidget> RebuildWidget() override;

	/**
	* Gets the controller for the menu
	*/
	UFUNCTION(BlueprintPure, Category = Input)
		APlayerController* GetController() const;

	/**
	* Sets the controller for the menu
	* @param NewController - the new controller object to be used
	*/
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetController(APlayerController* NewController);

private:
	// The controller object used by the menu
	UPROPERTY()
		APlayerController* Controller;

public:
	/** Array of all the menus window */
	UPROPERTY(BlueprintReadOnly, Category = Windows)
		TArray<UWindowBase*> Windows;

	
};
