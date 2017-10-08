#pragma once
//2017-09-04
class cScene;
class cMouseCursor;

class cMain_admin
{
private:
	cMouseCursor* m_pMouseCursor;

public:
	cMain_admin();
	~cMain_admin();

	void Update();
	void Render();
	void Render_UI_Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};