#include "stdafx.h"
#include "cMapSaveBtn.h"
#include "cMapTool.h"

enum
{
	E_XBUTTON,
	E_SAVEBTN,
};

void cMapSaveBtn::SetMapToolPointer(cMapTool * pMapTool)
{
	m_pMapTool = pMapTool;
}

void cMapSaveBtn::OnClick(cUIButton * pSender)
{
	if (pSender->GetTag() == E_XBUTTON)
	{
		g_pSceneManager->SceneChange("cAStarScene");
	}
	if (pSender->GetTag() == E_SAVEBTN)
	{
		m_pMapTool->SaveData();
	}
}
