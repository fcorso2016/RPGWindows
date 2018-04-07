// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "RPGPlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"

//------------------------------------------------------------------
// * The total elements in the window
//------------------------------------------------------------------
UMenuBase* ARPGPlayerController::AddMenu(TSubclassOf<UMenuBase> MenuClass) {
	UMenuBase* NewMenu = CreateWidget<UMenuBase>(this, MenuClass);
	NewMenu->SetController(this);
	NewMenu->AddToViewport(9999); // Z-order, this just makes it render on the very top.
	MenuStack.Add(NewMenu);
	return NewMenu;
}


//------------------------------------------------------------------
// * The total elements in the window
//------------------------------------------------------------------
void ARPGPlayerController::PopMenu() {
	UMenuBase* MenuToRemove = GetTopMenu();
	MenuToRemove->RemoveFromViewport();
	MenuStack.Pop();
}

//------------------------------------------------------------------
// * The total elements in the window
//------------------------------------------------------------------
void ARPGPlayerController::ClearMenuStack() {
	for (UMenuBase* MenuToRemove : MenuStack) {
		MenuToRemove->RemoveFromViewport();
	}
	MenuStack.Empty();
}

//------------------------------------------------------------------
// * Retreives the menu from the top of the stack
//------------------------------------------------------------------
UMenuBase* ARPGPlayerController::GetTopMenu() const {
	return MenuStack[MenuStack.Num() - 1];
}

//------------------------------------------------------------------
// * Get Key Bindings
//------------------------------------------------------------------
TArray<FInputActionKeyMapping> ARPGPlayerController::GetKeyBinding(FName Binding) {
	return PlayerInput->GetKeysForAction(Binding);
}