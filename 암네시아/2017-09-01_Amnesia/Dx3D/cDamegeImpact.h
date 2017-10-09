#pragma once

struct POS
{
	float x, y;
};

class cDamegeImpact
{
private:
	cUIObject*			m_pUIRoot;
	cUIObject*			m_pCurrentUI;
	LPD3DXSPRITE		m_pSprite;
	int					m_nTypeNum;
	int					m_nAlpha;
	POS					stPos;

public:
	cDamegeImpact();
	~cDamegeImpact();

	void Update();
	void Render();
	void BloodType(int num, int alpha);
	void BloodImpact();
};