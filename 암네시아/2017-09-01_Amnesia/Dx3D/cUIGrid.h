#pragma once

class cUIGrid
{
private:
	vector<ST_PC_VERTEX>		m_vecVertex;
	D3DXMATRIX					m_matWorld;
	D3DXVECTOR3					m_vPosition;

public:
	cUIGrid();
	~cUIGrid();

	void Setup(int nLine = 30, float fInterVal = 1.0f);
	void Render();
};

