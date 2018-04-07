// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

using UnrealBuildTool;
using System.Collections.Generic;

public class RPGWindowsEditorTarget : TargetRules
{
	public RPGWindowsEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "RPGWindows" } );
	}
}
