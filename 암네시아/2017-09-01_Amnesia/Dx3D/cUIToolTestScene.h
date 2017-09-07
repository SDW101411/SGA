#pragma once

class cUITool;

class cUIToolTestScene
{
private:
	cUITool* m_pUITool;

public:
	cUIToolTestScene();
	~cUIToolTestScene();

	void Setup();
	void Update();
	void Render();
};

