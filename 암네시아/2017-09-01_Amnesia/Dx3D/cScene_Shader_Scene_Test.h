#pragma once
#include "cScene.h"

class cObject_Game;
class cObject_Map;
class cObject_Light;
class cObject_Item;
class cDamegeImpact;
class cUI_In_Game;

//class cScene_Shader_Scene_Test : public cScene
//{
//public:
//	vector<cObject_Game*>		cObject_Vec;
//	vector<cObject_Map*>		cObject_Map_Vec;
//	vector<cObject_Light*>		cObject_Light_vec;
//	vector<cObject_Item*>		cObject_Item_vec;

class cScene_Shader_Scene_Test : public cScene
{
public:
	vector<cObject_Game*>	cObject_Vec;
	vector<cObject_Map*>	cObject_Map_Vec;
	vector<cObject_Light*>	cObject_Light_vec;
	vector<cObject_Item*>		cObject_Item_vec;
	cDamegeImpact*			m_pDamegeImpact;
	cUI_In_Game*			m_pUI_In_Game;

public:
	cScene_Shader_Scene_Test();
	~cScene_Shader_Scene_Test();
	
	void Setup();
	void Release();
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

