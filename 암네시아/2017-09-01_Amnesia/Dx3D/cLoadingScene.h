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
	bool					m_bClear;

	static void ThFunc1(LPVOID pParam);

public:
	cLoadingScene();
	~cLoadingScene();

	void Setup();
	void Release();
	void Update();
	void Render();
};

