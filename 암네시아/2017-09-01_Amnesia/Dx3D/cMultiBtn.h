#pragma once

#include "cUI.h"

class cMultiBtn : public cUI
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cMultiBtn();
	~cMultiBtn();

public:
	virtual void Update();
	virtual void Render();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void OnMouse(cUIButton* pSender);
	virtual void OnClick(cUIButton* pSender);
	virtual void OnRightClick(cUIButton* pSender);
};

