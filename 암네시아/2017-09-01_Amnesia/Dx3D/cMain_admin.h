#pragma once
//2017-09-04
//cScene 매니져 에 넣을 부분들 체크중ㄴ
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

