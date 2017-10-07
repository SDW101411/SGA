#pragma once
class IUI;
class cPlayer;
class cScene
{
private:
	SYNTHESIZE(Scene_oBject_List, oBject_List, OBJECTLIST);
	cPlayer *m_pPlayer;
	SYNTHESIZE(bool, UI_On);
	IUI*	m_pIUI;
public:
	cScene();
	virtual ~cScene();

	virtual void Setup();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void Render_UI_Render();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
public:
	D3DXVECTOR3 Get_cPlayer_Pos();
};

