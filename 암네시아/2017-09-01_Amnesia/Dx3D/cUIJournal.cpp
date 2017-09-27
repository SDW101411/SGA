#include "stdafx.h"
#include "cUIJournal.h"
#include "cUIImageView.h"
#include "cUITextView.h"
#include "cUI_In_Game.h"

enum
{
	E_BOOK,
	E_NOTE,
	E_DIARY,
	E_MEMORY,
	E_RETURN,
	E_TEXT,
};

cUIJournal::cUIJournal(int* state)
	: m_pUIRoot(NULL)
	, m_pSprite(NULL)
	, m_pState(state)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI_bg2.png");
	pImageView->SetScaling(0.75f, 0.65f);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;		// 이미지
	pImageView->SetTexture("UI/journal/bg_main.tga");
	pImageView->SetPosition(412, 10);
	pImageView->SetScaling(1.2f, 1.3f);
	pImageView->SetTag(E_BOOK);
	m_pUIRoot->AddChild(pImageView);

	cUITextView* pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(600, 100));
	pTextView->SetPosition(50, 280);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_TEXT);
	m_pUIRoot->AddChild(pTextView);

	cUIButton* pButton = new cUIButton;
	pButton->SetTexture("UI/journal/노트.png",
		"UI/journal/노트_glow.png",
		"UI/journal/노트.png");
	pButton->SetPosition(670, 160);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_NOTE);
	m_pUIRoot->AddChild(pButton);

	BtnFunc(pButton, "일기.png", "일기_glow.png", 670, 240, E_DIARY);
	BtnFunc(pButton, "기억.png", "기억_glow.png", 670, 320, E_MEMORY);
	BtnFunc(pButton, "돌아가기.png", "돌아가기_glow.png", 658, 560, E_RETURN);
}

cUIJournal::~cUIJournal()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cUIJournal::Update()
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT);
	if (pTextView) pTextView->SetText("");

	SAFE_UPDATE(m_pUIRoot);
}

void cUIJournal::Render()
{
	m_pUIRoot->Render(m_pSprite);
}

void cUIJournal::BtnFunc(cUIButton* pButton, char* szStr, char* szStrGlow, float x, float y, int tag)
{
	char str[30], strGlow[40];
	sprintf(str, "UI/journal/%s", szStr);
	sprintf(strGlow, "UI/journal/%s", szStrGlow);
	pButton = new cUIButton;
	pButton->SetTexture(str,
		strGlow,
		str);
	pButton->SetPosition(x, y);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(tag);
	m_pUIRoot->AddChild(pButton);
}

void cUIJournal::OnMouse(cUIButton* pSender)
{
}

void cUIJournal::OnClick(cUIButton* pSender)
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT);
	if (pTextView == NULL) return;

	if (pSender->GetTag() == E_NOTE)
	{
		pTextView->SetText("Note");
	}
	else if (pSender->GetTag() == E_DIARY)
	{
		pTextView->SetText("Diary");
	}
	else if (pSender->GetTag() == E_MEMORY)
	{
		pTextView->SetText("Memory");
	}
	else if (pSender->GetTag() == E_RETURN)
	{
		//g_pSceneManager->SceneChange("cUITool_In_Game_Test");
		*m_pState = UI_MAIN;
	}
}

void cUIJournal::OnRightClick(cUIButton * pSender)
{
}
