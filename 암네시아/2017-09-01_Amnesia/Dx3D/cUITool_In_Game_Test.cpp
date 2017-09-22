#include "stdafx.h"
#include "cUITool_In_Game_Test.h"
#include "cUI_In_Game.h"
#include "IUI.h"
#include "cXButton.h"

cUITool_In_Game_Test::cUITool_In_Game_Test()
{
	m_pUI = new cUI_In_Game;
	m_pIUI = new cXButton;
}

cUITool_In_Game_Test::~cUITool_In_Game_Test()
{
	SAFE_DELETE(m_pUI);
	SAFE_DELETE(m_pIUI);
}

void cUITool_In_Game_Test::Setup()
{
	
}

void cUITool_In_Game_Test::Release()
{
}

void cUITool_In_Game_Test::Update()
{
	SAFE_UPDATE(m_pUI);
	SAFE_UPDATE(m_pIUI);
}

void cUITool_In_Game_Test::Render()
{
	SAFE_RENDER(m_pUI);
	SAFE_RENDER(m_pIUI);
}
