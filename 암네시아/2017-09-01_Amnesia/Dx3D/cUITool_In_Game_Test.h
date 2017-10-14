#pragma once

#include "cScene.h"

class cUI;

class cUITool_In_Game_Test : public cScene
{
private:
	cUI* m_pUI;

public:
	cUITool_In_Game_Test();
	~cUITool_In_Game_Test();

	void Setup();
	void Release();
	void Update();
	void Render();
	void RenderUI();
};

