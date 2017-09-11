#include "stdafx.h"
#include "cUIToolTestScene.h"
#include "cUITool.h"
#include "cUIImageView.h"

cUIToolTestScene::cUIToolTestScene()
	//: m_pUITool(NULL)
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	//m_pUITool = new cUITool;
	//m_pUITool->Setup();

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI.png");
	pImageView->SetScaling(0.595f, 0.5f);
 	m_pUIRoot = pImageView;
}

cUIToolTestScene::~cUIToolTestScene()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
	//SAFE_DELETE(m_pUITool);
}

void cUIToolTestScene::Update()
{
	if (m_pUIRoot) m_pUIRoot->Update();
}

void cUIToolTestScene::Render()
{
	//SAFE_RENDER(m_pUITool);

	if(KEYMANAGER->isToggleKey(VK_TAB))
	{
		m_pUIRoot->Render(m_pSprite);
	}
}
