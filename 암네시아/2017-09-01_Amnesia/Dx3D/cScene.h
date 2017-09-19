#pragma once

class cPlayer;

class cScene
{
private:
	SYNTHESIZE(Scene_oBject_List, oBject_List, OBJECTLIST);
	SYNTHESIZE(bool, UI_On);
	cPlayer*			m_pPlayer;

public:
	cScene();
	virtual ~cScene();
	virtual void Update();
	virtual void Render();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

