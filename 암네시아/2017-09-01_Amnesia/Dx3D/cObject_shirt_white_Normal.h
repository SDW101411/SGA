#pragma once
#include "cObject_Game.h"
class cMtlTex;
class cObject_shirt_white_Normal :public cObject_Game
{
private:
	vector<cMtlTex*> vecMtlTex;
	LPD3DXMATERIAL m_Material;
public:
	cObject_shirt_white_Normal();
	~cObject_shirt_white_Normal();

public:
	void Update();
	void Render();
};


