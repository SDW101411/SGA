#pragma once
#include "cScene.h"

class cObject_Game;
class cObject_Map;

class cScene_Shader_Scene_Test : public cScene
{
private:
	vector<cObject_Game*> cObject_Vec;
	vector<cObject_Map*> cObject_Map_Vec;
public:
	cScene_Shader_Scene_Test();
	~cScene_Shader_Scene_Test();
	
	void Setup();
	void Release();
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

