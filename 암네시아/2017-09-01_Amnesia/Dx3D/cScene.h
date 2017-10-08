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
	virtual void RenderUI();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

};

