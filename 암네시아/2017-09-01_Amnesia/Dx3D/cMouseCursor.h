#pragma once

class cMouseCursor
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;

public:
	cMouseCursor();
	~cMouseCursor();

	void Update();
	void Render();
};

