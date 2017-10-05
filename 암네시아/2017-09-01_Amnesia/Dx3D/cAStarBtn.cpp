#include "stdafx.h"
#include "cAStarBtn.h"

enum
{
	E_XBUTTON,
	E_SAVEBTN,
};

void cAStarBtn::OnClick(cUIButton * pSender)
{
	if (pSender->GetTag() == E_XBUTTON)
	{
		g_pSceneManager->SceneChange("cMainMenuScene");
	}
	if (pSender->GetTag() == E_SAVEBTN)
	{
		g_pSceneManager->SceneChange("cMapToolScene");
	}
}
