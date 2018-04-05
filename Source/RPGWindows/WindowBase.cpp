// Fill out your copyright notice in the Description page of Project Settings.

#include "WindowBase.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"

//------------------------------------------------------------------
// * Object Initilization
//------------------------------------------------------------------
UWindowBase::UWindowBase(const FObjectInitializer& ObjectInitializer) : UUserWidget(ObjectInitializer) {
	// Initialize Windowskin Information
	ConstructorHelpers::FObjectFinder<UDataTable> WindowskinsTable(TEXT("/Game/Graphics/Windows/Windowskins.Windowskins"));
	if (WindowskinsTable.Succeeded()) {
		Windowskins = WindowskinsTable.Object;
	}
	WindowskinName = "Default";
	
}

//------------------------------------------------------------------
// * Visual Construction
//------------------------------------------------------------------
void UWindowBase::NativeConstruct() {
	Super::NativeConstruct();

	DrawWindowBackground();
}


//------------------------------------------------------------------
// * Generate the Contents of the Window
//------------------------------------------------------------------
void UWindowBase::DrawWindowBackground() {
	if (Windowskins != nullptr) {

	
	}
}

//------------------------------------------------------------------
// * Change the Windowskin
//------------------------------------------------------------------
void UWindowBase::ChangeWindowskin(FName NewWindowskin) {
	WindowskinName = NewWindowskin;
}