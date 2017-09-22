#pragma once
class cPlayer;
class cScene
{
private:
	SYNTHESIZE(Scene_oBject_List, oBject_List, OBJECTLIST);
	cPlayer *m_pPlayer;
	SYNTHESIZE(bool, UI_On);
public:
	cScene();
	virtual ~cScene();

	virtual void Setup();
	virtual void Release();
	virtual void Update();
	virtual void Render();
	virtual void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

