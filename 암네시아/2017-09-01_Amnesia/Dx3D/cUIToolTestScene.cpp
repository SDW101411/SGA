#include "stdafx.h"
#include "cUIToolTestScene.h"
#include "cUITool.h"

cUIToolTestScene::cUIToolTestScene()
	: m_pUITool(NULL)
{
}

cUIToolTestScene::~cUIToolTestScene()
{
	SAFE_DELETE(m_pUITool);
}

void cUIToolTestScene::Setup()
{
	m_pUITool = new cUITool;
	m_pUITool->Setup();
}

void cUIToolTestScene::Update()
{
}

void cUIToolTestScene::Render()
{
	SAFE_RENDER(m_pUITool);
}
