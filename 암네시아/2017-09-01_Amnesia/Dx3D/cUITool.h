#pragma once

class cUITool
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cUITool();
	~cUITool();

	void InventoryBorder();
	void HealthBorder();
	void SanityBorder();
	void ExplanationBorder();
	void TinderBoxBorder();
	void OilBorder();
	void JournalBorder();
	void Update();
	void Render();
};
