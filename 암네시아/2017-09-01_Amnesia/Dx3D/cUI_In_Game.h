#pragma once

#include "IUI.h"
class cUITool;

class cUI_In_Game : public IUI
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;
	int				m_nHeartHP;
	int				m_nBrainHP;
	float			m_fOilValue;
	char			m_szTinderNum[20];
	char			m_szHeartState[64];
	char			m_szHeartGlowState[64];
	char			m_szBrainState[64];
	char			m_szBrainGlowState[64];

	cUITool*		m_pBorder;

public:
	cUI_In_Game();
	~cUI_In_Game();

public:
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void OnMouse(cUIButton* pSender);
	void OnClick(cUIButton* pSender);
};

