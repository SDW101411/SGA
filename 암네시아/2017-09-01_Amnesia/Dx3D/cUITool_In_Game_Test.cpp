#include "stdafx.h"
#include "cUITool_In_Game_Test.h"
#include "cUI_In_Game.h"
#include "IUI.h"
#include "cMultiBtn.h"

cUITool_In_Game_Test::cUITool_In_Game_Test()
{
	m_pUI = new cUI_In_Game;
	m_pIUI = new cMultiBtn;
}

cUITool_In_Game_Test::~cUITool_In_Game_Test()
{
	SAFE_DELETE(m_pUI);
	SAFE_DELETE(m_pIUI);
}

void cUITool_In_Game_Test::Setup()
{
	//SOUNDMANAGER->addSound("15_event_elevator", "15_event_elevator.ogg", true, true);
	//SOUNDMANAGER->addSound("ui_use_oil", "ui_use_oil.ogg", false, false);
	//SOUNDMANAGER->addSound("ui_use_health", "ui_use_health.ogg", false, false);
	//SOUNDMANAGER->addSound("journal_open", "journal_open.ogg", false, false);
	//SOUNDMANAGER->addSound("journal_close", "journal_close.ogg", false, false);

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
}

void cUITool_In_Game_Test::Render()
{
	SAFE_RENDER(m_pUI);
	SAFE_RENDER(m_pIUI);
}
