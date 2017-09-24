#pragma once

class cMapWall
{
private:
	vector<D3DXVECTOR3> m_wallSurface;

	D3DXMATRIX		m_matWorld;
	D3DMATERIAL9	m_material;

private:
	SYNTHESIZE(int, m_startRow, StartRow);
	SYNTHESIZE(int, m_startCol, StartCol);
	SYNTHESIZE(int, m_endRow, EndRow);
	SYNTHESIZE(int, m_endCol, EndCol);
public:
	void SetPosition(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos, int floor);
	void SetRowCol(int startRow, int startCol, int endRow, int endCol);
	void Render();

	bool IsSame(int startRow, int startCol, int endRow, int endCol);

	vector<D3DXVECTOR3> GetSurface();
};