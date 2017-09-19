#pragma once

//class cUIGrid;

class cUITool
{
private:
	//cUIGrid*						m_pUIGrid;
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cUITool();
	~cUITool();

	void GenericBorder();
	void HealthBorder();
	void SanityBorder();
	void Update();
	void Render();
};

