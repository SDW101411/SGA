#pragma once

#include "IUI.h"

class cUITool;

enum PLAYERSTATE
{
	PLAYER_HEART_100,
	PLAYER_HEART_75,
	PLAYER_HEART_50,
	PLAYER_HEART_25,
	PLAYER_BRAIN_100,
	PLAYER_BRAIN_75,
	PLAYER_BRAIN_50,
	PLAYER_BRAIN_25,
	PLAYER_DEATH,
};

class cUI_In_Game : public IUI
{
private:
	cUIObject*						m_pUIRoot;
	cUIObject*						m_curClickItem;
	LPD3DXSPRITE					m_pSprite;
	int								m_nHeartHP;
	int								m_nBrainHP;
	int								m_nRow, m_nCol;
	int								m_curItemRow, m_curItemCol;
	float							m_fOilValue;
	char							m_szTinderNum[20];
	char							m_szHeartState[64];
	char							m_szHeartGlowState[64];
	char							m_szBrainState[64];
	char							m_szBrainGlowState[64];

	cUITool*						m_pBorder;
	map<int, map<int, cUIObject*>>	m_itemList;
	PLAYERSTATE						HeartSate;
	PLAYERSTATE						BrainSate;

	RECT							m_InventoryRc;
	RECT							m_OilRc;

	cUIButton*						m_pItemOil;

public:
	cUI_In_Game();
	~cUI_In_Game();

public:
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void OnMouse(cUIButton* pSender);
	void OnClick(cUIButton* pSender);

	void CreateItem(int tag);

	void HeartState(int heart);
	void BrainState(int brain);
	void ValueCtr();

	void FindPostion(IN int row, IN int col, OUT int& x, OUT int& y);
	bool FindRowCol(OUT int& row, OUT int& col);
};

