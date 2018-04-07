// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "MenuBase.h"

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