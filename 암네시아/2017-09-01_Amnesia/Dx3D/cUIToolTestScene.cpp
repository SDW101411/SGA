#include "stdafx.h"
#include "cUIToolTestScene.h"
#include "cUITool.h"
#include "cUIImageView.h"

cUIToolTestScene::cUIToolTestScene()
	//: m_pUITool(NULL)
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
}

cUIToolTestScene::~cUIToolTestScene()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
	//SAFE_DELETE(m_pUITool);
}

void cUIToolTestScene::Setup()
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	//m_pUITool = new cUITool;
	//m_pUITool->Setup();

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI.png");
	m_pUIRoot = pImageView;
}

void cUIToolTestScene::Update()
{
	if (m_pUIRoot) m_pUIRoot->Update();
}

void cUIToolTestScene::Render()
{
	//SAFE_RENDER(m_pUITool);

	//if (KEYMANAGER->isOnceKeyDown(VK_TAB))
	if (KEYMANAGER->isStayKeyDown('Q'))
	{
		m_pUIRoot->Render(m_pSprite);
	}
	/*if (KEYMANAGER->isOnceKeyUp(VK_TAB))
	{

	}*/
}
