#pragma once

#include "cScene.h"
#include "cUIButton.h"

class cMainMenuScene : public cScene, iButtonDelegate
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cMainMenuScene();
	~cMainMenuScene();

public:
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void OnMouse(cUIButton* pSender);
	void OnClick(cUIButton* pSender);
};

