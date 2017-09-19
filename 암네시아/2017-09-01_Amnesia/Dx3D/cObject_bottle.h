#pragma once
#include "cObject_Game.h"
class cObject_bottle :public cObject_Game
{
public:
	cObject_bottle();
	~cObject_bottle();
public:
	void Update();
	void Render();
};

