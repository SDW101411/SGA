#include "stdafx.h"
#include "cMultiBtn.h"
#include "cUIImageView.h"

enum
{
	E_XBUTTON,
	E_SAVEBTN,
};

cMultiBtn::cMultiBtn()
	: m_pUIRoot(NULL)
	, m_pSprite(NULL)
{ 
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetScaling(0.1f, 0.1f);
	m_pUIRoot = pImageView;

	cUIButton* pButton = new cUIButton;
	pButton->SetTexture("UI/close_btn2.png",
		"UI/close_glow_btn2.png",
		"UI/close_btn2.png");
	pButton->SetPosition(20, 70);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_XBUTTON);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/saveRe.png",
		"UI/saveGlow.png",
		"UI/saveRe.png");
	pButton->SetPosition(45, 200);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_SAVEBTN);
	m_pUIRoot->AddChild(pButton);
}

cMultiBtn::~cMultiBtn()
{
	SAFE_RELEASE(m_pUIRoot);
	SAFE_RELEASE(m_pSprite);
}

void cMultiBtn::Update()
{
	SAFE_UPDATE(m_pUIRoot);
}

void cMultiBtn::Render()
{
	if (m_pUIRoot) m_pUIRoot->Render(m_pSprite);
}

void cMultiBtn::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void cMultiBtn::OnMouse(cUIButton * pSender)
{
}

void cMultiBtn::OnClick(cUIButton * pSender)
{
	if (pSender->GetTag() == E_XBUTTON)
	{
		// 처음 화면으로
		g_pSceneManager->SceneChange("cMainMenuScene");
	}
	else if (pSender->GetTag() == E_SAVEBTN)
	{
		// 저장용
	}
}

void cMultiBtn::OnRightClick(cUIButton * pSender)
{
}
