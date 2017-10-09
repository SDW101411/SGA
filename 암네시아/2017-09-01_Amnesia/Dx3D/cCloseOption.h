#pragma once

#include "cScene.h"
#include "IUI.h"

class cCloseOption : public cScene, IUI
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cCloseOption();
	~cCloseOption();

	virtual void Update();
	virtual void RenderUI();

	virtual void OnMouse(cUIButton* pSender);
	virtual void OnClick(cUIButton* pSender);
	virtual void OnRightClick(cUIButton* pSender);
};

