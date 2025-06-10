//
// Created by PandaDex on 10/06/2025.
//

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FRandomRotatorPluginModule : public IModuleInterface
{
public:
    virtual void StartupModule() override;
    virtual void ShutdownModule() override;

private:
    void AddMenuExtension(FMenuBuilder& Builder);
    void PluginButtonClicked();

    TSharedRef<class SDockTab> OnSpawnPluginTab(const class FSpawnTabArgs& SpawnTabArgs);
};
