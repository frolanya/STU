// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ShootThemUp : ModuleRules
{
	public ShootThemUp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "Niagara", "PhysicsCore", "AIModule", "GameplayTasks", "NavigationSystem" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });

		PublicIncludePaths.AddRange(new string[] 
		{
          "ShootThemUp/Public",
          "ShootThemUp/Public/AI",
          "ShootThemUp/Public/Animations",
          "ShootThemUp/Public/Components",
          "ShootThemUp/Public/Pickups",
          "ShootThemUp/Public/Player",
          "ShootThemUp/Public/UI",
          "ShootThemUp/Public/Weapon",
          "ShootThemUp/Public/Weapon/Components",
          "ShootThemUp/Public/AI/Tasks",
          "ShootThemUp/Public/AI/Services",
          "ShootThemUp/Public/AI/EQS",
          "ShootThemUp/Public/AI/Decorators"
        });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
