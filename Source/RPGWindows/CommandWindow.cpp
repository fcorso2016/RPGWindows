// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "CommandWindow.h"

//------------------------------------------------------------------
// * Slot an Element into the Contents Field
//------------------------------------------------------------------
void UCommandWindow::DrawItem(int X, int Y) {
	Super::DrawItem(X, Y);

	if (MainBody != nullptr && ContentsField != nullptr) {

	}
}

//------------------------------------------------------------------
// * The total number of elements in the window
//------------------------------------------------------------------
int UCommandWindow::ElementCount() {
	return CommandList.Num();
}