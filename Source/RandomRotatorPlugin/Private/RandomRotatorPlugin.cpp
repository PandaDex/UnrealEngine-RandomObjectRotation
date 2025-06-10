//
// Created by PandaDex on 10/06/2025.
//

#include "RandomRotatorPlugin.h"
#include "SRandomRotatorWidget.h"
#include "LevelEditor.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "Widgets/Docking/SDockTab.h"
#include "Framework/MultiBox/MultiBoxBuilder.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SEditableTextBox.h"
#include "Editor.h"
#include "Engine/Selection.h"
#include "GameFramework/Actor.h"
#include "Misc/ScopedSlowTask.h"

static const FName RandomRotatorTabName("RandomRotator");

#define LOCTEXT_NAMESPACE "FRandomRotatorPluginModule"

void FRandomRotatorPluginModule::StartupModule()
{
    FGlobalTabmanager::Get()->RegisterNomadTabSpawner(RandomRotatorTabName, FOnSpawnTab::CreateRaw(this, &FRandomRotatorPluginModule::OnSpawnPluginTab)).SetDisplayName(LOCTEXT("RandomRotatorTabTitle", "Random Rotator")).SetMenuType(ETabSpawnerMenuType::Enabled);

    FLevelEditorModule &LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");

    LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MakeShareable(new FExtender()));
}

void FRandomRotatorPluginModule::ShutdownModule()
{
    FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(RandomRotatorTabName);
}

TSharedRef<SDockTab> FRandomRotatorPluginModule::OnSpawnPluginTab(const FSpawnTabArgs &SpawnTabArgs)
{
    return SNew(SDockTab)
        .TabRole(ETabRole::NomadTab)
            [SNew(SVerticalBox) + SVerticalBox::Slot().AutoHeight()
                                      [SNew(SBox)
                                           .Padding(10)
                                               [SNew(SRandomRotatorWidget)]]];
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FRandomRotatorPluginModule, RandomRotatorPlugin)
