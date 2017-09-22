#pragma once

#include "IUI.h"

class cXButton : public IUI
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cXButton();
	~cXButton();

public:
	virtual void Update();
	virtual void Render();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void OnMouse(cUIButton* pSender);
	virtual void OnClick(cUIButton* pSender);
};

