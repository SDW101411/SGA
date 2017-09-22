#include "stdafx.h"
#include "cMainMenuScene.h"
#include "cUIImageView.h"
#include "cUITextView.h"

enum
{
	E_GAME_BACKGROUND	= 100,
	E_GAME_START		= 101,
	E_GAME_OPTION		= 102,
	E_GAME_CLOSE		= 103,
	E_BTN_SDW			= 104,
	E_TEXT_VIEW,
};

cMainMenuScene::cMainMenuScene()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/menu_gamma.tga");
	pImageView->SetScaling(6.48f, 5.1f);
	pImageView->SetTag(E_GAME_BACKGROUND);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/menu_logo.tga");
	pImageView->SetPosition(150.0f, 100.0f);
	pImageView->SetScaling(1.4f, 1.4f);
	m_pUIRoot->AddChild(pImageView);

	cUIButton* pButton = new cUIButton;
	pButton->SetTexture("UI/ó�����ͽ���.png",
		"UI/ó�����ͽ���Mouse.png",
		"UI/ó�����ͽ���.png");
	pButton->SetPosition(990, 200);
	pButton->SetScaling(0.8f, 0.8f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_GAME_START);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/����.png",
		"UI/����Mouse.png",
		"UI/����.png");
	pButton->SetPosition(1090, 270);
	pButton->SetScaling(0.8f, 0.8f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_GAME_OPTION);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/����.png",
		"UI/����Mouse.png",
		"UI/����.png");
	pButton->SetPosition(1091, 340);
	pButton->SetScaling(0.8f, 0.8f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_GAME_CLOSE);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/���.png",
		"UI/���Mouse.png",
		"UI/���.png");
	pButton->SetPosition(1080, 410);
	pButton->SetScaling(0.5f, 0.5f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_BTN_SDW);
	m_pUIRoot->AddChild(pButton);

	cUITextView* pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(566, 494);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);

	pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("�ٽ� ���� ���� ��");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(1100, 674);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);

	pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("0.1 Beta");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(1228, 674);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);
}

cMainMenuScene::~cMainMenuScene()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cMainMenuScene::Update()
{
	SAFE_UPDATE(m_pUIRoot);
}

void cMainMenuScene::Render()
{
	if(m_pUIRoot) m_pUIRoot->Render(m_pSprite);
}

void cMainMenuScene::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void cMainMenuScene::OnMouse(cUIButton* pSender)
{
}

void cMainMenuScene::OnClick(cUIButton* pSender)
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	if (pTextView == NULL) return;

	if (pSender->GetTag() == E_GAME_START)
	{
	//	pTextView->SetText("���� ����");
		g_pSceneManager->SceneChange("2");
	}
	else if (pSender->GetTag() == E_GAME_OPTION)
	{
		pTextView->SetText("���� �ɼ�");
	}
	else if (pSender->GetTag() == E_GAME_CLOSE)
	{
		pTextView->SetText("���� ����");
	}
	else if (pSender->GetTag() == E_BTN_SDW)
	{
		g_pSceneManager->SceneChange("cScene_Shader_Scene_Test");
	}
}
