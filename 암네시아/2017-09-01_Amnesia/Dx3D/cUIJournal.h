#pragma once

#include "IUI.h"

class cUIJournal : public IUI
{
private:
	cUIObject*						m_pUIRoot;
	LPD3DXSPRITE					m_pSprite;

public:
	cUIJournal();
	~cUIJournal();

public:
	void Update();
	void Render();
	void BtnFunc(cUIButton* pButton, char* szStr, char* szStrGlow, float x, float y, int tag);

	void OnMouse(cUIButton* pSender);
	void OnClick(cUIButton* pSender);
};

