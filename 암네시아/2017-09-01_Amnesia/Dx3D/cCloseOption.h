#pragma once

#include "IUI.h"

class cCloseOption : public IUI
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;
	bool			m_bOn;

public:
	cCloseOption();
	~cCloseOption();

	virtual void Update();
	virtual void Render();

	virtual void OnMouse(cUIButton* pSender);
	virtual void OnClick(cUIButton* pSender);
	virtual void OnRightClick(cUIButton* pSender);
};