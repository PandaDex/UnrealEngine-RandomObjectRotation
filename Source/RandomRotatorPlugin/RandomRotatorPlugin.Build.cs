using UnrealBuildTool;

public class RandomRotatorPlugin : ModuleRules
{
    public RandomRotatorPlugin(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        PrivateDependencyModuleNames.AddRange(new string[] {
    "Core",
    "CoreUObject",
    "Engine",
    "Slate",
    "SlateCore",
    "EditorStyle",
    "LevelEditor",
    "UnrealEd",
    "InputCore",
    "EditorFramework"
});

        PublicIncludePaths.AddRange(new string[] {
            "RandomRotatorPlugin/Public"
        });
    }
}
