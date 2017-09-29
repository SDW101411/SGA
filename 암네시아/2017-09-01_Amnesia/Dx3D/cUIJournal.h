#pragma once

#include "IUI.h"

class cUIJournal : public IUI
{
private:
	cUIObject*						m_pUIRoot;
	LPD3DXSPRITE					m_pSprite;
	int*							m_pState;

public:
	cUIJournal(int* state);
	~cUIJournal();

public:
	void Update();
	void Render();
	void BtnFunc(cUIButton* pButton, char* szStr, char* szStrGlow, float x, float y, int tag);

	void OnMouse(cUIButton* pSender);
	void OnClick(cUIButton* pSender);
	void OnRightClick(cUIButton* pSender);
};

