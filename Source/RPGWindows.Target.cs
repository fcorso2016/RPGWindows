// Created by Francesco Corso. Free for both comercial and non-comercial use under Creative Commons Licensing.

using UnrealBuildTool;
using System.Collections.Generic;

public class RPGWindowsTarget : TargetRules
{
	public RPGWindowsTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "RPGWindows" } );
	}
}
