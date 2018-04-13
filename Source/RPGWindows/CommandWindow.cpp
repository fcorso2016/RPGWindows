// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "CommandWindow.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"

//------------------------------------------------------------------
// * Slot an Element into the Contents Field
//------------------------------------------------------------------
void UCommandWindow::DrawItem(int Index) {
	Super::DrawItem(Index);

	if (ContentsFieldIsValid()) {
		UTextBlock* TextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TextBlock->SetText(CommandList[Index].Name);
		SlotWidget(TextBlock, Index);
	}
}

//------------------------------------------------------------------
// * The total number of elements in the window
//------------------------------------------------------------------
int UCommandWindow::ElementCount() {
	return CommandList.Num();
}