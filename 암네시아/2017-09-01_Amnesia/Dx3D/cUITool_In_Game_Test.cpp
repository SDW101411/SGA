#include "stdafx.h"
#include "cUITool_In_Game_Test.h"
#include "cUI_In_Game.h"
#include "IUI.h"


cUITool_In_Game_Test::cUITool_In_Game_Test()
{
	m_pUI = new cUI_In_Game;
}

cUITool_In_Game_Test::~cUITool_In_Game_Test()
{
	SAFE_DELETE(m_pUI);
}

void cUITool_In_Game_Test::Update()
{
	SAFE_UPDATE(m_pUI);
}

void cUITool_In_Game_Test::Render()
{
	SAFE_RENDER(m_pUI);
}
