// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "SelectionWindow.h"

//------------------------------------------------------------------
// * Object Initilization
//------------------------------------------------------------------
USelectionWindow::USelectionWindow(const FObjectInitializer& ObjectInitializer) : UWindowBase(ObjectInitializer) {
	// Set the index of the window to 0
	Index = 0;
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
// * The total elements in the window
//------------------------------------------------------------------
int USelectionWindow::ElementCount() {
	return 0;
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