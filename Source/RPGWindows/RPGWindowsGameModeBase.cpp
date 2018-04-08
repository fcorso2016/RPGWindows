// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#include "RPGWindowsGameModeBase.h"
#include "RPGPlayerController.h"

//------------------------------------------------------------------
// * Object Initilization
//------------------------------------------------------------------
ARPGWindowsGameModeBase::ARPGWindowsGameModeBase() {
	PlayerControllerClass = ARPGPlayerController::StaticClass();
}