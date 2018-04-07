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

}

//------------------------------------------------------------------
// * The total elements in the window
//------------------------------------------------------------------
int USelectionWindow::ElementCount() {
	return 0;
}