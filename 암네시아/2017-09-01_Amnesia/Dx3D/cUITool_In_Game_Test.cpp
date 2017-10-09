#include "stdafx.h"
#include "cUITool_In_Game_Test.h"
#include "cUI_In_Game.h"
#include "IUI.h"
#include "cMultiBtn.h"
#include "cCloseOption.h"

cUITool_In_Game_Test::cUITool_In_Game_Test()
{
	m_pUI = new cUI_In_Game;
	m_pIUI = new cMultiBtn;
	m_pClose = new cCloseOption;
}

cUITool_In_Game_Test::~cUITool_In_Game_Test()
{
	SAFE_DELETE(m_pUI);
	SAFE_DELETE(m_pIUI);
	SAFE_DELETE(m_pClose);
}

void cUITool_In_Game_Test::Setup()
{
	SOUNDMANAGER->play("15_event_elevator");
}

void cUITool_In_Game_Test::Release()
{
	SOUNDMANAGER->pause("15_event_elevator");
}

void cUITool_In_Game_Test::Update()
{
	SAFE_UPDATE(m_pUI);
	SAFE_UPDATE(m_pIUI);
	SAFE_UPDATE(m_pClose);
}

void cUITool_In_Game_Test::Render()
{
}

void cUITool_In_Game_Test::RenderUI()
{
	SAFE_RENDER(m_pUI);
	SAFE_RENDER(m_pIUI);
	SAFE_RENDER(m_pClose);
}
