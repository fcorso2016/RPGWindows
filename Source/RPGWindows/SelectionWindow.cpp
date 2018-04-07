// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "SelectionWindow.h"

//------------------------------------------------------------------
// * Object Initilization
//------------------------------------------------------------------
USelectionWindow::USelectionWindow(const FObjectInitializer& ObjectInitializer) : UWindowBase(ObjectInitializer) {

}

//------------------------------------------------------------------
// * Rebuild the Widget
//------------------------------------------------------------------
TSharedRef<SWidget> UWindowBase::RebuildWidget() {
	// Get the original widget
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	return Widget;
}