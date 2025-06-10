//
// Created by PandaDex on 10/06/2025.
//

#include "SRandomRotatorWidget.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Input/SSpinBox.h"
#include "Editor.h"
#include "Engine/Selection.h"
#include "GameFramework/Actor.h"
#include "Math/UnrealMathUtility.h"

void SRandomRotatorWidget::Construct(const FArguments& InArgs)
{
    ChildSlot
        [
            SNew(SVerticalBox)
                + SVerticalBox::Slot().AutoHeight().Padding(2)
                [
                    CreateLabeledSpinBox("Min X", MinXVal)
                ]
            + SVerticalBox::Slot().AutoHeight().Padding(2)
                [
                    CreateLabeledSpinBox("Max X", MaxXVal)
                ]
            + SVerticalBox::Slot().AutoHeight().Padding(2)
                [
                    CreateLabeledSpinBox("Min Y", MinYVal)
                ]
            + SVerticalBox::Slot().AutoHeight().Padding(2)
                [
                    CreateLabeledSpinBox("Max Y", MaxYVal)
                ]
            + SVerticalBox::Slot().AutoHeight().Padding(2)
                [
                    CreateLabeledSpinBox("Min Z", MinZVal)
                ]
            + SVerticalBox::Slot().AutoHeight().Padding(2)
                [
                    CreateLabeledSpinBox("Max Z", MaxZVal)
                ]

            + SVerticalBox::Slot().AutoHeight().Padding(5)
                [
                    SNew(SVerticalBox)
                        + SVerticalBox::Slot().AutoHeight().Padding(5)
                        [
                            SNew(SButton).Text(FText::FromString("Random Rot (ALL)"))
                                .OnClicked_Lambda([this]() { ApplyRandomRotation(true, true, true); return FReply::Handled(); })
                        ]
                        + SVerticalBox::Slot().AutoHeight().Padding(5)
                        [
                            SNew(SButton).Text(FText::FromString("Random Rot (X)"))
                                .OnClicked_Lambda([this]() { ApplyRandomRotation(true, false, false); return FReply::Handled(); })
                        ]
                        + SVerticalBox::Slot().AutoHeight().Padding(5)
                        [
                            SNew(SButton).Text(FText::FromString("Random Rot (Y)"))
                                .OnClicked_Lambda([this]() { ApplyRandomRotation(false, true, false); return FReply::Handled(); })
                        ]
                        + SVerticalBox::Slot().AutoHeight().Padding(5)
                        [
                            SNew(SButton).Text(FText::FromString("Random Rot (Z)"))
                                .OnClicked_Lambda([this]() { ApplyRandomRotation(false, false, true); return FReply::Handled(); })
                        ]
                ]
        ];
}

TSharedRef<SWidget> SRandomRotatorWidget::CreateLabeledSpinBox(const FString& Label, float& BoundValue)
{
    return SNew(SHorizontalBox)
        + SHorizontalBox::Slot().AutoWidth().VAlign(VAlign_Center).Padding(0, 0, 5, 0)
        [
            SNew(STextBlock).Text(FText::FromString(Label))
        ]
        + SHorizontalBox::Slot().FillWidth(1)
        [
            SNew(SSpinBox<float>)
                .MinValue(-360.f)
                .MaxValue(360.f)
                .Value(BoundValue)
                .OnValueChanged_Lambda([&BoundValue](float NewValue) { BoundValue = NewValue; })
        ];
}

void SRandomRotatorWidget::ApplyRandomRotation(bool bX, bool bY, bool bZ)
{
    USelection* SelectedActors = GEditor->GetSelectedActors();
    if (!SelectedActors) return;

    for (FSelectionIterator It(*SelectedActors); It; ++It)
    {
        AActor* Actor = Cast<AActor>(*It);
        if (Actor)
        {
            FRotator NewRot = Actor->GetActorRotation();

            if (bX)
                NewRot.Roll = FMath::FRandRange(MinXVal, MaxXVal);
            if (bY)
                NewRot.Pitch = FMath::FRandRange(MinYVal, MaxYVal);
            if (bZ)
                NewRot.Yaw = FMath::FRandRange(MinZVal, MaxZVal);

            Actor->Modify();
            Actor->SetActorRotation(NewRot);
        }
    }
}
