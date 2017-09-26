#pragma once

class cMapSurface
{
private:
	vector<D3DXVECTOR3>	m_surface;

	D3DXMATRIX			m_matWorld;
	D3DMATERIAL9		m_material;

public:
	cMapSurface();
	~cMapSurface();

	void SetWall(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos, int floor);
	void SetGround(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos);
	void RenderSurface();

	vector<D3DXVECTOR3> GetSurface();
};