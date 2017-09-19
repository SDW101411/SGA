#pragma once

#include "cScene.h"
#include "cUIButton.h"

class cUITool;

class cUIToolTestScene : public cScene, iButtonDelegate
{
private:
	cUITool*		m_pUITool;
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;
	int				m_nPlayerHeartType;
	int				m_nHeartHP;
	int				m_nBrainHP;
	int				m_nTinderNum;
	float			m_fOilValue;
	char			m_szTinderNum[20];
	char			m_szHeartState[64];
	char			m_szHeartGlowState[128];
	char			m_szBrainState[64];
	char			m_szBrainGlowState[64];
	//string			m_szTinderNum;

public:
	cUIToolTestScene();
	~cUIToolTestScene();

	void Update();
	void Render();

	virtual void OnMouse(cUIButton* pSender) override;
	virtual void OnClick(cUIButton* pSender) override;
};

