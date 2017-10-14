#pragma once

#include "cUIButton.h"

class cUI : public iButtonDelegate
{
private:
	

public:
	cUI();
	virtual ~cUI();

public:
	virtual void Update();
	virtual void Render();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void OnMouse(cUIButton* pSender);
	virtual void OnClick(cUIButton* pSender);
};

