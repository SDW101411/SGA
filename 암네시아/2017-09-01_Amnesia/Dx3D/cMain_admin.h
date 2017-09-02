#pragma once
class cMain_admin
{
public:
	cMain_admin();
	~cMain_admin();

	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

