// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "CommandWindow.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/UMG/Public/Components/TextBlock.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"
#include "Runtime/Engine/Classes/Engine/Font.h"

//------------------------------------------------------------------
// * Object Initilization
//------------------------------------------------------------------
UCommandWindow::UCommandWindow(const FObjectInitializer& ObjectInitializer) : USelectionWindow(ObjectInitializer) {
	// Initialize the font of the window
	ConstructorHelpers::FObjectFinder<UFont> DefaultFont(TEXT("/Engine/EngineFonts/Roboto.Roboto"));
	if (DefaultFont.Succeeded()) {
		Font.FontObject = DefaultFont.Object;
	}
	Font.TypefaceFontName = "Bold";
	Font.Size = 24;
}

//------------------------------------------------------------------
// * Slot an Element into the Contents Field
//------------------------------------------------------------------
void UCommandWindow::DrawItem(int Index) {
	Super::DrawItem(Index);

	if (ContentsFieldIsValid()) {
		UTextBlock* TextBlock = WidgetTree->ConstructWidget<UTextBlock>(UTextBlock::StaticClass());
		TextBlock->SetText(CommandList[Index].Name);
		TextBlock->SetFont(Font);
		SlotWidget(TextBlock, Index);
	}
}

//------------------------------------------------------------------
// * The total number of elements in the window
//------------------------------------------------------------------
int UCommandWindow::ElementCount() {
	return CommandList.Num();
}