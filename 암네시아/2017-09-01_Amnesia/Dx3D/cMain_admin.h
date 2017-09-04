#pragma once
//2017-09-04
class cScene;

class cMain_admin
{
private:
	SYNTHESIZE(cScene*, m_pNow_Scene, Now_cScene);
public:
	cMain_admin();
	~cMain_admin();

	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

