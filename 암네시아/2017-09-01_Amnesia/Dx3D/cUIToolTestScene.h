#pragma once

#include "cScene.h"

class cUITool;

class cUIToolTestScene : public cScene
{
private:
	cUITool*		m_pUITool;
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cUIToolTestScene();
	~cUIToolTestScene();

	void Setup();
	void Update();
	void Render();
};

