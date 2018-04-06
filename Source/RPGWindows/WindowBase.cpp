// Fill out your copyright notice in the Description page of Project Settings.

#include "WindowBase.h"
#include "Runtime/CoreUObject/Public/UObject/ConstructorHelpers.h"
#include "Runtime/UMG/Public/Components/CanvasPanelSlot.h"
#include "Runtime/UMG/Public/Components/HorizontalBoxSlot.h"
#include "Runtime/UMG/Public/Components/VerticalBoxSlot.h"
#include "Runtime/UMG/Public/Blueprint/WidgetTree.h"

//------------------------------------------------------------------
// * Constants
//------------------------------------------------------------------
const float UWindowBase::TILE_WIDTH = 64.f;
const float UWindowBase::TILE_HEIGHT = 64.f;
const float UWindowBase::FRAME_THICKNESS = 12.f;

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

	// The the size of the window
	Width = 1920;
	Height = 1080;
	
}

//------------------------------------------------------------------
// * Visual Construction
//------------------------------------------------------------------
void UWindowBase::NativeConstruct() {
	Super::NativeConstruct();

	// Bind delegates here
}

//------------------------------------------------------------------
// * Rebuild the Widget
//------------------------------------------------------------------
TSharedRef<SWidget> UWindowBase::RebuildWidget() {
	// Get the original widget
	TSharedRef<SWidget> Widget = Super::RebuildWidget();

	// Retrieve the Root Component of the widget
	UCanvasPanel* RootWidget = Cast<UCanvasPanel>(GetRootWidget());

	if (RootWidget != nullptr) {

		// Initialize the Window Components
		TopLeftTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		TopMiddleTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		TopRightTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		MiddleLeftTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		CenterTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		MiddleRightTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		BottomLeftTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		BottomMiddleTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());
		BottomRightTile = WidgetTree->ConstructWidget<UImage>(UImage::StaticClass());

		// Attach the window components to the root
		RootWidget->AddChild(TopLeftTile);
		RootWidget->AddChild(TopMiddleTile);
		RootWidget->AddChild(TopRightTile);
		RootWidget->AddChild(MiddleLeftTile);
		RootWidget->AddChild(CenterTile);
		RootWidget->AddChild(MiddleRightTile);
		RootWidget->AddChild(BottomLeftTile);
		RootWidget->AddChild(BottomMiddleTile);
		RootWidget->AddChild(BottomRightTile);

		// Get the size of the window if it is slotted
		SetSlottedSize();

		// Draw the Window Background
		DrawWindowBackground(Width, Height);

		// Create the contents of the window
		MainBody = WidgetTree->ConstructWidget<UCanvasPanel>(UImage::StaticClass(), TEXT("MainBody"));
		RootWidget->AddChild(MainBody);
		UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(MainBody->Slot);
		Slot->SetAnchors(FAnchors(0.f, 0.f, 0.f, 0.f));
		Slot->SetPosition(FVector2D(FRAME_THICKNESS, FRAME_THICKNESS));
		Slot->SetSize(FVector2D(FRAME_THICKNESS, FRAME_THICKNESS));
	}

	return Widget;
}

//------------------------------------------------------------------
// * Change the Windowskin
//------------------------------------------------------------------
void UWindowBase::ChangeWindowskin(FName NewWindowskin) {
	WindowskinName = NewWindowskin;
}

//------------------------------------------------------------------
// * Generate the Contents of the Window
//------------------------------------------------------------------
void UWindowBase::DrawWindowBackground(float Width, float Height) {
	// Setup a context string for drawing the windows
	static const FString ContextString(TEXT("WINDOWSKINS"));

	if (Windowskins != nullptr) {
		FWindowskin* Windowskin = Windowskins->FindRow<FWindowskin>(WindowskinName, ContextString);
		if (Windowskin != nullptr) {

			// Place the tiles
			PlaceTile(TopLeftTile, Windowskin->TopLeftTile, 0.f, 0.f, TILE_WIDTH, TILE_HEIGHT);
			PlaceTile(TopMiddleTile, Windowskin->TopMiddleTile, TILE_WIDTH, 0.f, Width - TILE_WIDTH * 2, TILE_HEIGHT);
			PlaceTile(TopRightTile, Windowskin->TopRightTile, Width - TILE_WIDTH, 0.f, TILE_WIDTH, TILE_HEIGHT);
			PlaceTile(MiddleLeftTile, Windowskin->MiddleLeftTile, 0.f, TILE_HEIGHT, TILE_WIDTH, Height - TILE_HEIGHT * 2);
			PlaceTile(CenterTile, Windowskin->CenterTile, TILE_WIDTH, TILE_HEIGHT, Width - TILE_WIDTH * 2, Height - TILE_HEIGHT * 2);
			PlaceTile(MiddleRightTile, Windowskin->MiddleRightTile, Width - TILE_WIDTH, TILE_HEIGHT, TILE_WIDTH, Height - TILE_HEIGHT * 2);
			PlaceTile(BottomLeftTile, Windowskin->BottomLeftTile, 0.f, Height - TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
			PlaceTile(BottomMiddleTile, Windowskin->BottomMiddleTile, TILE_WIDTH, Height - TILE_HEIGHT, Width - TILE_WIDTH * 2, TILE_HEIGHT);
			PlaceTile(BottomRightTile, Windowskin->BottomRightTile, Width - TILE_WIDTH, Height - TILE_HEIGHT, TILE_WIDTH, TILE_HEIGHT);
		}
	}
}

//------------------------------------------------------------------
// * Sets the size of the window when slotted in a UMG
//------------------------------------------------------------------
void UWindowBase::SetSlottedSize() {
	if (this->Slot != nullptr) {
		if (this->Slot->IsA(UCanvasPanelSlot::StaticClass())) {
			UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(this->Slot);
			Width = Slot->GetSize().X;
			Height = Slot->GetSize().Y;
		} else if (this->Slot->IsA(UHorizontalBoxSlot::StaticClass())) {
			UHorizontalBoxSlot* Slot = Cast<UHorizontalBoxSlot>(this->Slot);
			Width = Slot->Size.Value;
		} else if (this->Slot->IsA(UVerticalBoxSlot::StaticClass())) {
			UHorizontalBoxSlot* Slot = Cast<UHorizontalBoxSlot>(this->Slot);
			Height = Slot->Size.Value;
		}
	}
}

//------------------------------------------------------------------
// * Place the Tile into the viewport
//------------------------------------------------------------------
void UWindowBase::PlaceTile(UImage* Tile, UPaperSprite* Sprite, float X, float Y, float Width, float Height) {
	if (Tile != nullptr) {
		UCanvasPanelSlot* Slot = Cast<UCanvasPanelSlot>(Tile->Slot);
		Slot->SetPosition(FVector2D(X, Y));
		Slot->SetSize(FVector2D(Width, Height));
		Slot->SetZOrder(-100);
		Tile->Brush.SetResourceObject(Sprite);
	}
}

//------------------------------------------------------------------
// * Resize the widget while also resizing the window as well
//------------------------------------------------------------------
void UWindowBase::SetDesiredSizeOfWindow(FVector2D Size) {
	Width = Size.X;
	Height = Size.Y;
	SetDesiredSizeInViewport(Size);
}