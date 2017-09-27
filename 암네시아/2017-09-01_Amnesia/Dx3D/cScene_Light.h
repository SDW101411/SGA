#pragma once
#include "cScene.h"



class cObject_Map;
class cObject_Light;

class cScene_Light : public cScene
{
private:
	vector<cObject_Map*> cObject_Map_Vec;
	vector<cObject_Light*> cObject_Light_Vec;
public:
	cScene_Light();
	~cScene_Light();

	void Setup();
	void Release();
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

