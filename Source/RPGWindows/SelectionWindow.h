// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

#pragma once

#include "CoreMinimal.h"
#include "WindowBase.h"
#include "Runtime/UMG/Public/Components/PanelWidget.h"
#include "Runtime/UMG/Public/Components/UniformGridPanel.h"
#include "SelectionWindow.generated.h"

/** Delegate for when the user presses confirm */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FProcessConfirm);

/** Delegate for when the user presses cancel */
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FProcessCancel);

/**
* Struct that stores the input handlers for the window
*/
USTRUCT(BlueprintType)
struct FInputActions {
	GENERATED_BODY()

public:

	/** The Up Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		FName UpInput;

	/** The Down Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		FName DownInput;

	/** The Left Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		FName LeftInput;

	/** The Right Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		FName RightInput;

	/** The Confirm Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		FName ConfirmInput;

	/** The Cancel Input */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		FName CancelInput;
};

/**
 * Superclass used for creating menus where the player can selection options from.
 */
UCLASS()
class RPGWINDOWS_API USelectionWindow : public UWindowBase {
	GENERATED_BODY()

	// Information about the cursor in the window
	static const float CURSOR_X_OFFSET;
	static const float CURSOR_Y_OFFSET;
	static const float CURSOR_WIDTH;
	static const float CURSOR_HEIGHT;

public:
	// Tile objects
	UPROPERTY(BlueprintReadOnly, Category = Components)
		UImage* WindowCursor;

	// Contains the elements of the window
	UPROPERTY(BlueprintReadOnly, Category = Components, meta = (BindWidget))
		UUniformGridPanel* ContentsField;

	// Construct
	USelectionWindow(const FObjectInitializer& ObjectInitializer);

protected:

	// Draws any contents to the window
	virtual void DrawWindowContents() override;

	// Automatically adjusts the size of the window
	virtual void ResizeWindow() override;

public:

	/**
	* Add Element to the Contents Field
	* @param Index - The index of the element being drawn
	*/
	void AddElement(int Index);

	/**
	* Draw the element in the contents field
	* @param Index - The index of the element being drawn
	*/
	virtual void DrawItem(int Index);

	/**
	* Place a widget into the contents field
	* @param Index - The index of the element being drawn
	*/
	void SlotWidget(UWidget* Widget, int Index);

	/**
	* Set the location of the cursor in the window
	*/
	void SetCursorPosition();

	/**
	* Sets the index of the window and sets that information visually
	* @param NewIndex - the new index of the window
	*/
	UFUNCTION(BlueprintCallable, Category = Window)
		virtual void SetIndex(int NewIndex);

	/**
	* Get if the widget is active
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		bool GetActive();

	/**
	* Set the widget as active or not
	* @param Active - The active status of the window
	*/
	UFUNCTION(BlueprintCallable, Category = Window)
		void SetActive(bool Active);

	/**
	* The number of selectable elements in the window
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual int ElementCount();

	/**
	* Get the number of columns in the window
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual int ColumnCount();

	/**
	* Get the number of rows in the window
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		int RowCount();

	/**
	* Can the cursor loop around the edges of the window?
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual bool CursorLoop();

	/**
	* Dictates if the player can confirm an option or not
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual bool CanConfirm();

	/**
	* Dictates if the player can cancel an option or not
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual bool CanCancel();

	/**
	* The width of any given entry in the window
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual float ElementWidth();

	/**
	* The width of any given entry in the window
	*/
	UFUNCTION(BlueprintPure, Category = Window)
		virtual float ElementHeight();

	/**
	* Determines if the key that is currently pressed is mapped to the given action mapping
	* @param Key - The key being pressed
	* @param Action - the action binding
	*/
	UFUNCTION(BlueprintPure, Category = Input)
		bool ValidInput(FKey Key, FName Action);

	// Called on a  key being pressed
	virtual FReply NativeOnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;

	/**
	* Parses cursor movement
	* @param Key - The key that is being depressed
	* @param Handled - Was the even handled
	*/
	void ProcessCursorInput(const FKey& Key, bool& Handled);

	/**
	* Process the input when the player confirms an options
	*/
	virtual void ProcessConfirm();

	/** The delegate bound to confirm */
	UPROPERTY(BlueprintAssignable, Category = "Selection|Confirm")
		FProcessConfirm OnConfirm;

	/** The delegate bound to cancel */
	UPROPERTY(BlueprintAssignable, Category = "Selection|Cancel")
		FProcessCancel OnCancel;

protected:

	/** Get the currently selected index of the window */
	UPROPERTY(BlueprintReadOnly, Category = Window)
		int Index;

	/** Get the window's active status */
	bool IsActive;

	/** The width of any one element when resized automatically (some subclasses override this value) */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		float AutoElementWidth;

	/** The width of any one element when resized automatically (some subclasses override this value) */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		float AutoElementHeight;

	/** Automatically adjust the width of the window? */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		bool AutoAdjustWidth;

	/** Automatically adjust the height of the window? */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		bool AutoAdjustHeight;

	/** The horizontal alignment of the elements in the window */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		TEnumAsByte<EHorizontalAlignment> HorizontalAlignment;

	/** The vertical alignment of the elements in the window */
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = Window)
		TEnumAsByte<EVerticalAlignment> VerticalAlignment;

	/** List of all input mappings */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input)
		FInputActions BaseInputs;

	/** The scale of the cursor in the window */
	UPROPERTY(EditAnywhere, Category = Window, meta = (UIMin = 1, ClampMin = 1))
		int CursorScale;
	
};
