#pragma once

enum CURSORSTATUS
{
	CUR_NORMAL,
	CUR_PICKUP,
	CUR_OPEN,
	CUR_IGNITE,
};

class cCursorStatus
{
private:
	cUIObject*		m_pUIRoot;
	LPD3DXSPRITE	m_pSprite;
	CURSORSTATUS	cursorStatus;
	//int				m_nStatus;

public:
	cCursorStatus();
	~cCursorStatus();

	void Update();
	void Render();
	void CursorStatus(int tag);
};

