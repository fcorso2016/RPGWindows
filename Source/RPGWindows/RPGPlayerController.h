// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"
#include "MenuBase.h"
#include "RPGPlayerController.generated.h"

/**
 * Player controller exteneded to allow for menus to be opened and
 * input to be passed to them.
 */
UCLASS(meta=(DisplayName = "RPG Player Controller"))
class RPGWINDOWS_API ARPGPlayerController : public APlayerController {
	GENERATED_BODY()

public:

	/**
	* Opens a menu and adds it the stack
	* @param MenuClass - The class of the menu to add to the stack
	*/
	UFUNCTION(BlueprintCallable, Category = Menus)
		UMenuBase* AddMenu(TSubclassOf<UMenuBase> MenuClass);

	/**
	* Removes the top menu from the stack
	*/
	UFUNCTION(BlueprintCallable, Category = Menus)
		void PopMenu();

	/**
	* Clears the menu stack
	*/
	UFUNCTION(BlueprintCallable, Category = Menus)
		void ClearMenuStack();

	/**
	* Gets the menu at the top of the stack
	*/
	UFUNCTION(BlueprintPure, Category = Menus)
		UMenuBase* GetTopMenu() const;

	/**
	* Get the keys that correspond to a specific action binding
	*/
	UFUNCTION(BlueprintPure, Category = Menu)
		void GetActionKeyBinding(FName Action, TArray<FInputActionKeyMapping>& Bindings);
	
private:

	// Contains the full number of menus
	UPROPERTY()
		TArray<UMenuBase*> MenuStack;
	
	
};
