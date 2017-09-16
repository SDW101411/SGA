#pragma once

#include "cUIButton.h"

class IUI : public iButtonDelegate
{
private:
	

public:
	IUI();
	virtual ~IUI();

public:
	virtual void Update();
	virtual void Render();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	virtual void OnMouse(cUIButton* pSender);
	virtual void OnClick(cUIButton* pSender);
};

