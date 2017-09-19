#pragma once

#include "cScene.h"

class IUI;

class cUITool_In_Game_Test : public cScene
{
private:
	IUI* m_pUI;

public:
	cUITool_In_Game_Test();
	~cUITool_In_Game_Test();

	void Update();
	void Render();
};

