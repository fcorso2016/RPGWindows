// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "MenuBase.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"

//------------------------------------------------------------------
// * Rebuild the Widget
//------------------------------------------------------------------
TSharedRef<SWidget> UMenuBase::RebuildWidget() {
	// Get the original widget
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	TArray <UWidget*> WidgetList;
	WidgetTree->GetAllWidgets(WidgetList);
	for (UWidget* Widget : WidgetList) {
		if (Widget->IsA(UWindowBase::StaticClass())) {
			UWindowBase* Window = Cast<UWindowBase>(Widget);
			Windows.Add(Window);
			Window->SetController(Controller);
		}
	}

	return Widget;
}

//------------------------------------------------------------------
// * Get the Controller Object
//------------------------------------------------------------------
APlayerController* UMenuBase::GetController() const {
	return Controller;
}

//------------------------------------------------------------------
// * Set the Controller Object
//------------------------------------------------------------------
void UMenuBase::SetController(APlayerController* NewController) {
	Controller = NewController;
}