#include "stdafx.h"
#include "cMainMenuScene.h"
#include "cUIImageView.h"
#include "cUITextView.h"

enum
{
	E_GAME_BACKGROUND = 100,
	E_GAME_START = 101,
	E_GAME_OPTION = 102,
	E_GAME_CLOSE = 103,
	E_BTN_SDW = 104,
	E_BTN_NGYB = 105,
	E_TEXT_VIEW,
};

cMainMenuScene::cMainMenuScene()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI_bg2.png");
	pImageView->SetScaling(6.48f, 5.1f);
	pImageView->SetTag(E_GAME_BACKGROUND);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/menu_logo.tga");
	pImageView->SetPosition(150.0f, 100.0f);
	pImageView->SetScaling(1.4f, 1.4f);
	m_pUIRoot->AddChild(pImageView);

	cUIButton* pButton = new cUIButton;
	pButton->SetTexture("UI/처음부터시작.png",
		"UI/처음부터시작Mouse.png",
		"UI/처음부터시작.png");
	pButton->SetPosition(990, 200);
	pButton->SetScaling(0.8f, 0.8f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_GAME_START);
	m_pUIRoot->AddChild(pButton);

	BtnFunc(pButton, "설정", "설정Mouse", 1090, 270, 0.8f, 0.8f, E_GAME_OPTION);
	BtnFunc(pButton, "종료", "종료Mouse", 1091, 340, 0.8f, 0.8f, E_GAME_CLOSE);
	BtnFunc(pButton, "우기", "우기Mouse", 1080, 410, 0.5f, 0.5f, E_BTN_SDW);
	BtnFunc(pButton, "꿍이", "꿍이Mouse", 1080, 480, 0.5f, 0.5f, E_BTN_NGYB);

	cUITextView* pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(566, 494);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);

	TextViewFunc(pTextView, "다신 보지 말자 조", 1100, 674, E_TEXT_VIEW);
	TextViewFunc(pTextView, "0.1 Beta", 1228, 674, E_TEXT_VIEW);
}

cMainMenuScene::~cMainMenuScene()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cMainMenuScene::Setup()
{
	SOUNDMANAGER->play("game_menu");
}

void cMainMenuScene::Release()
{
	SOUNDMANAGER->pause("game_menu");
}

void cMainMenuScene::Update()
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	if (pTextView) pTextView->SetText("");

	SAFE_UPDATE(m_pUIRoot);
}

void cMainMenuScene::Render()
{
	
}

void cMainMenuScene::RenderUI()
{
	if (m_pUIRoot) m_pUIRoot->Render(m_pSprite);
}

void cMainMenuScene::BtnFunc(cUIButton * pButton, char * szStr, char * szStrGlow, float x, float y, float width, float height, int tag)
{
	char str[30], strGlow[40];
	sprintf(str, "UI/%s.png", szStr);
	sprintf(strGlow, "UI/%s.png", szStrGlow);
	pButton = new cUIButton;
	pButton->SetTexture(str,
		strGlow,
		str);
	pButton->SetPosition(x, y);
	pButton->SetScaling(width, height);
	pButton->SetDelegate(this);
	pButton->SetTag(tag);
	m_pUIRoot->AddChild(pButton);
}

void cMainMenuScene::TextViewFunc(cUITextView* pTextView, string szStr, float x, float y, int tag)
{
	pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText(szStr);
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(x, y);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(tag);
	m_pUIRoot->AddChild(pTextView);
}

void cMainMenuScene::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void cMainMenuScene::OnMouse(cUIButton* pSender)
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	if (pTextView == NULL) return;

	if (pSender->GetTag() == E_GAME_OPTION)
	{
		pTextView->SetText("게임 옵션");
	}
}

void cMainMenuScene::OnClick(cUIButton* pSender)
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	if (pTextView == NULL) return;

	if (pSender->GetTag() == E_GAME_START)
	{
		//	pTextView->SetText("게임 시작");
		g_pSceneManager->SceneChange("cUITool_In_Game_Test");
	}
	/*else if (pSender->GetTag() == E_GAME_OPTION)
	{
	pTextView->SetText("게임 옵션");
	}*/
	else if (pSender->GetTag() == E_GAME_CLOSE)
	{
		//pTextView->SetText("게임 종료");
		PostQuitMessage(0);
	}
	else if (pSender->GetTag() == E_BTN_SDW)
	{
		//g_pSceneManager->SceneChange("cScene_Shader_Scene_Test");
		g_pSceneManager->SceneChange("cLoadingScene");
	}
	else if (pSender->GetTag() == E_BTN_NGYB)
	{
		g_pSceneManager->SceneChange("cAStarScene");
	}
}

void cMainMenuScene::OnRightClick(cUIButton* pSender)
{
}
