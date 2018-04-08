// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "SelectionWindow.h"
#include "RPGPlayerController.h"
#include "Runtime/Engine/Classes/GameFramework/PlayerInput.h"

//------------------------------------------------------------------
// * Object Initilization
//------------------------------------------------------------------
USelectionWindow::USelectionWindow(const FObjectInitializer& ObjectInitializer) : UWindowBase(ObjectInitializer) {
	// Set the index of the window to 0
	SetIndex(0);

	// Set the default input mappings
	BaseInputs.UpInput = "MenuUp";
	BaseInputs.DownInput = "MenuDown";
	BaseInputs.LeftInput = "MenuLeft";
	BaseInputs.RightInput = "MenuRight";
	BaseInputs.ConfirmInput = "MenuConfirm";
	BaseInputs.ConfirmInput = "MenuCancel";
}

//------------------------------------------------------------------
// * Rebuild the Widget
//------------------------------------------------------------------
TSharedRef<SWidget> USelectionWindow::RebuildWidget() {
	// Get the original widget
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	return Widget;
}

//------------------------------------------------------------------
// * Set Index
//------------------------------------------------------------------
void USelectionWindow::SetIndex(int NewIndex) {
	// Set the new index correcting out of range values
	Index = FMath::Clamp(0, NewIndex, ElementCount());

	// Additional selection functionality is done in sub classes
}

//------------------------------------------------------------------
// * The total number of elements in the window
//------------------------------------------------------------------
int USelectionWindow::ElementCount() {
	return 0;
}

//------------------------------------------------------------------
// * The number of columns in the window
//------------------------------------------------------------------
int USelectionWindow::ColumnCount() {
	return 1;
}

//------------------------------------------------------------------
// * The number of rows in the window
//------------------------------------------------------------------
int USelectionWindow::RowCount() {
	return FMath::Clamp(1, (ElementCount() + ColumnCount() - 1) / ColumnCount(), ElementCount());
}

//------------------------------------------------------------------
// * Cursor Loop
//------------------------------------------------------------------
bool USelectionWindow::CursorLoop() {
	return false;
}

//------------------------------------------------------------------
// * Can you confirm your selection?
//------------------------------------------------------------------
bool USelectionWindow::CanConfirm() {
	return false;
}

//------------------------------------------------------------------
// * Can you cancel out of the window
//------------------------------------------------------------------
bool USelectionWindow::CanCancel() {
	return true;
}

//------------------------------------------------------------------
// * Valid Action Input
//------------------------------------------------------------------
bool USelectionWindow::ValidInput(FKey Key, FName Action) {
	if (Controller->IsA(ARPGPlayerController::StaticClass())) {
		ARPGPlayerController* RPGController = Cast<ARPGPlayerController>(Controller);
		TArray<FInputActionKeyMapping> ActionBindings;
		RPGController->GetActionKeyBinding(Action, ActionBindings);
		for (FInputActionKeyMapping Mapping : ActionBindings) {
			if (Mapping.Key == Key) {
				return true;
			}
		}
	}
	return false;
}

//------------------------------------------------------------------
// * Handles what happens when a key is pressed
//------------------------------------------------------------------
FReply USelectionWindow::NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) {
	// Grab original handling result in the event nothing happens
	FReply OldHandling = Super::NativeOnKeyDown(MyGeometry, InKeyEvent);

	// Boolean that notifies the window if a new input has been handled
	bool Handled = false;

	// Parse Possible Inputs
	FKey Key = InKeyEvent.GetKey();
	ProcessCursorInput(Key, Handled);
	

	if (Handled) {
		return FReply::Handled();
	} else {
		// Return the original handling as nothing additional has been handled
		return OldHandling;
	}
	
}

//------------------------------------------------------------------
// * Process Movement from the Cursor
//------------------------------------------------------------------
void USelectionWindow::ProcessCursorInput(const FKey& Key, bool& Handled) {
	// There is no reason to process the cursor if there are no elements
	if (ElementCount() > 0) {
		if (ValidInput(Key, BaseInputs.UpInput)) {
			if (Index >= ColumnCount()) {
				SetIndex(Index - ColumnCount());
				Handled = true;
			} else if (CursorLoop()) {
				SetIndex(ElementCount() + (Index - ColumnCount()));
				Handled = true;
			}
		}

		if (ValidInput(Key, BaseInputs.DownInput)) {
			if (Index <= ElementCount() - ColumnCount()) {
				SetIndex(Index + ColumnCount());
				Handled = true;
			} else if (CursorLoop()) {
				SetIndex(Index + ColumnCount() - ElementCount());
				Handled = true;
			}
		}

		if (ValidInput(Key, BaseInputs.LeftInput)) {
			if (Index > 0) {
				SetIndex(Index - 1);
				Handled = true;
			} else if (CursorLoop()) {
				SetIndex(ElementCount() - 1);
				Handled = true;
			}
		}

		if (ValidInput(Key, BaseInputs.RightInput)) {
			if (Index < ElementCount() - 1) {
				SetIndex(Index + 1);
				Handled = true;
			} else if (CursorLoop()) {
				SetIndex(0);
				Handled = true;
			}
		}
	}
}