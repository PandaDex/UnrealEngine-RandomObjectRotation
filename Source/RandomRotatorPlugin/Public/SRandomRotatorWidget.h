//
// Created by PandaDex on 10/06/2025.
//

#pragma once

#include "Widgets/SCompoundWidget.h"
#include "Widgets/Input/SSpinBox.h"

class SRandomRotatorWidget : public SCompoundWidget
{
public:
    SLATE_BEGIN_ARGS(SRandomRotatorWidget) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
    void ApplyRandomRotation(bool bX, bool bY, bool bZ);
    TSharedRef<SWidget> CreateLabeledSpinBox(const FString& Label, float& BoundValue);

private:
    float MinXVal = 0.f;
    float MaxXVal = 180.f;
    float MinYVal = 0.f;
    float MaxYVal = 180.f;
    float MinZVal = 0.f;
    float MaxZVal = 180.f;
};
