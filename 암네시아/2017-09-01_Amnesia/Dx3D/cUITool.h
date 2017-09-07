#pragma once

class cUIGrid;

class cUITool
{
private:
	cUIGrid*						m_pUIGrid;

public:
	cUITool();
	~cUITool();

	void Setup();
	void Update();
	void Render();
};

