#pragma once

#include "cScene.h"
#include "cUIButton.h"

class cUITool;

class cUIToolTestScene : public cScene, iButtonDelegate
{
private:
	cUITool* m_pUITool;
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cUIToolTestScene();
	~cUIToolTestScene();

	void Update();
	void Render();

	//�޼��� ���ν��� �½�Ʈ
//	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
//	POINT	m_ptMouse;
//	POINT	m_ptPrevMouse;
//	bool	m_isRButtonDown;

	virtual void OnClick(cUIButton* pSender) override;
};

