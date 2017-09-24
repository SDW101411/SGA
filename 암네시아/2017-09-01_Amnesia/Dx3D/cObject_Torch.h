#pragma once


#pragma once
#include "cObject_Game.h"
class cObject_Torch :public cObject_Game
{
public:
	cObject_Torch();
	~cObject_Torch();
public:
	void Update();
	void Render();
};

