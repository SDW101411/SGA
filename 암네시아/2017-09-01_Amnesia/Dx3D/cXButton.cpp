#include "stdafx.h"
#include "cXButton.h"
#include "cUIImageView.h"

enum
{
	E_XBUTTON = 211,
};

cXButton::cXButton()
	: m_pUIRoot(NULL)
	, m_pSprite(NULL)
{ 
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetScaling(0.75f, 0.65f);
	m_pUIRoot = pImageView;

	cUIButton* pButton = new cUIButton;
	pButton->SetTexture("UI/close_btn.png",
		"UI/close_btn.png",
		"UI/close_btn.png");
	pButton->SetPosition(244, 100);
	pButton->SetScaling(1.1f, 1.1f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_XBUTTON);
	m_pUIRoot->AddChild(pButton);
}

cXButton::~cXButton()
{
	SAFE_RELEASE(m_pUIRoot);
	SAFE_RELEASE(m_pSprite);
}

void cXButton::Update()
{
	SAFE_UPDATE(m_pUIRoot);
}

void cXButton::Render()
{
	if (m_pUIRoot) m_pUIRoot->Render(m_pSprite);
}

void cXButton::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void cXButton::OnMouse(cUIButton * pSender)
{
}

void cXButton::OnClick(cUIButton * pSender)
{
	if (pSender->GetTag() == E_XBUTTON)
	{
		//	pTextView->SetText("게임 시작");
		g_pSceneManager->SceneChange("cMainMenuScene");
	}
}
