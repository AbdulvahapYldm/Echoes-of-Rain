// Fill out your copyright notice in the Description page of Project Settings.


#include "Widgets/HUD/Inv_InfoMessageWidget.h"
#include "Components/TextBlock.h"

void UInv_InfoMessageWidget::NativeOnInitialized()
{
	Super::NativeOnInitialized();

	Text_Message->SetText(FText::GetEmpty());
	HideMessage();
}

void UInv_InfoMessageWidget::SetTextMessage(const FText& Message)
{
	Text_Message->SetText(Message);
	if (!bIsMessageActive)
	{
		ShowMessage();
	}
	bIsMessageActive = true;

	GetWorld()->GetTimerManager().SetTimer(MessageTimer,[this]() 
	{
		HideMessage();
		bIsMessageActive = false;
	},MessageLifeTime,false);


}

