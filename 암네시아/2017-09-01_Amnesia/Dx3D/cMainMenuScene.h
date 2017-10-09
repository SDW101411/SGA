#pragma once

#include "cScene.h"
#include "cUIButton.h"

class cUITextView;
class cMenuCamera;
class cObject_Light;
class cObject_Map;

class cMainMenuScene : public cScene, iButtonDelegate
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;
	cMenuCamera*	m_pMenuCamera;
	vector<cObject_Light*>	m_objLights;
	vector<cObject_Map*>	m_objMaps;

public:
	cMainMenuScene();
	~cMainMenuScene();

public:
	void Setup();
	void Release();
	void Update();
	void Render();
	void RenderUI();
	void BtnFunc(cUIButton* pButton, char* szStr, char* szStrGlow, float x, float y, float width, float height, int tag);
	void TextViewFunc(cUITextView* pTextView, string szStr, float x, float y, int tag);

	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

	void OnMouse(cUIButton* pSender);
	void OnClick(cUIButton* pSender);
	void OnRightClick(cUIButton* pSender);
};

