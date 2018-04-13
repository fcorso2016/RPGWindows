// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "RPGPlayerController.h"

//------------------------------------------------------------------
// * The total elements in the window
//------------------------------------------------------------------
UMenuBase* ARPGPlayerController::AddMenu(TSubclassOf<UMenuBase> MenuClass) {
	UMenuBase* NewMenu = CreateWidget<UMenuBase>(this, MenuClass);
	NewMenu->SetController(this);
	NewMenu->AddToViewport(9999); // Z-order, this just makes it render on the very top.
	MenuStack.Add(NewMenu);
	SetInputMode(FInputModeUIOnly());
	return NewMenu;
}


//------------------------------------------------------------------
// * The total elements in the window
//------------------------------------------------------------------
void ARPGPlayerController::PopMenu() {
	UMenuBase* MenuToRemove = GetTopMenu();
	MenuToRemove->RemoveFromViewport();
	MenuStack.Pop();
	if (MenuStack.Num() == 0) {
		SetInputMode(FInputModeGameOnly());
	}
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
// * Get Action Key Bindings
//------------------------------------------------------------------
void ARPGPlayerController::GetActionKeyBinding(FName Action, TArray<FInputActionKeyMapping>& Bindings) {
	Bindings = PlayerInput->GetKeysForAction(Action);
}