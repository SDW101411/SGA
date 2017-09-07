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
}

void cUIToolTestScene::Update()
{
}

void cUIToolTestScene::Render()
{
}
