#include "stdafx.h"
#include "cUIToolTestScene.h"
#include "cUITool.h"

cUIToolTestScene::cUIToolTestScene()
	: m_pUITool(NULL)
{
<<<<<<< HEAD
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	//m_pUITool = new cUITool;
	//m_pUITool->Setup();

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI.png");
	pImageView->SetScaling(0.595f, 0.5f);
 	m_pUIRoot = pImageView;
=======
>>>>>>> feff05f73f58a371e9e2c70f41684c9609ea2af4
}

cUIToolTestScene::~cUIToolTestScene()
{
<<<<<<< HEAD
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
	//SAFE_DELETE(m_pUITool);
=======
	SAFE_DELETE(m_pUITool);
}

void cUIToolTestScene::Setup()
{
	m_pUITool = new cUITool;
	m_pUITool->Setup();
>>>>>>> feff05f73f58a371e9e2c70f41684c9609ea2af4
}

void cUIToolTestScene::Update()
{
}

void cUIToolTestScene::Render()
{
	SAFE_RENDER(m_pUITool);
}
