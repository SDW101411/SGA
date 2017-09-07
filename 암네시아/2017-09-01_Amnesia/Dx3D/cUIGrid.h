#pragma once

class cUIGrid
{
private:
	vector<ST_PC_VERTEX>		m_vecVertex;

public:
	cUIGrid();
	~cUIGrid();

	void Setup(int nLine = 30, float fInterVal = 1.0f);
	void Render();
};

