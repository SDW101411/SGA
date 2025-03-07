#pragma once

#include "cUI.h"

class cUITool;
class cUITextView;
class cUIJournal;

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

enum UISTATE
{
	UI_MAIN,
	UI_JOURNAL,
};

class cUI_In_Game : public cUI
{
private:
	cUIObject*						m_pUIRoot;
	cUIObject*						m_curClickItem;
	LPD3DXSPRITE					m_pSprite;
	SYNTHESIZE(float, m_fOilValue, OilValue);
	//int								m_nHeartHP;
	//int								m_nBrainHP;
	int								m_nRow, m_nCol;
	int								m_curItemRow, m_curItemCol;
	int								m_nState;
	char							m_szTinderNum[20];
	char							m_szHeartState[64];
	char							m_szHeartGlowState[64];
	char							m_szBrainState[64];
	char							m_szBrainGlowState[64];

	cUITool*						m_pBorder;
	map<int, map<int, cUIObject*>>	m_itemList;
	PLAYERSTATE						HeartSate;
	PLAYERSTATE						BrainSate;
	UISTATE							UIState;

	RECT							m_InventoryRc;
	RECT							m_OilRc;

	cUIButton*						m_pItemOil;
	cUIJournal*						m_pJournal;

	//bool							m_bOn;

public:
	cUI_In_Game();
	~cUI_In_Game();

public:
	void Update();
	void Render();
	void RenderUI();
	void BtnFunc(cUIButton* pButton, char* szStr, char* szStrGlow, float x, float y, float width, float height, int tag);
	void TextViewFunc(cUITextView* pTextView, cFontManager::eFontType type, string szStr, float szWidth, float szHeight, float x, float y, DWORD var, int tag);
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void OnMouse(cUIButton* pSender);
	void OnClick(cUIButton* pSender);
	void OnRightClick(cUIButton* pSender);

	void CreateItem(int tag);

	void HeartState(float heart);
	void BrainState(float brain);

	void ValueCtr();

	void UpdateItemState();

	void FindPostion(IN int row, IN int col, OUT int& x, OUT int& y);
	bool FindRowCol(OUT int& row, OUT int& col);
	//bool GetTabUIOn(bool on) { return m_bOn = on; }
};

