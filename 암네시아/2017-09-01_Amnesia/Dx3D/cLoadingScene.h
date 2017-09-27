#pragma once

#include "cScene.h"

class cObject_Game;
class cObject_Map;
class cObject_Light;

class cLoadingScene : public cScene
{
private:
	cUIObject*				m_pUIRoot;
	LPD3DXSPRITE			m_pSprite;

	vector<cObject_Game*>	cObject_Vec;
	vector<cObject_Map*>	cObject_Map_Vec;
	vector<cObject_Light*>	cObject_Light_vec;

	static void ThFunc1(LPVOID pParam);

public:
	cLoadingScene();
	~cLoadingScene();

	void Setup();
	void Release();
	void Update();
	void Render();
};

