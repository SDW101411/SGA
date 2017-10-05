#pragma once

class cGridNode
{
private:
	ID3DXMesh*				m_pGrid;

	D3DXMATRIX				m_matWorld;
	D3DMATERIAL9			m_material;

	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);

	SYNTHESIZE(cGridNode*, m_pParent, Parent);

	SYNTHESIZE(float, m_g, G);
	SYNTHESIZE(float, m_h, H);
	SYNTHESIZE(float, m_f, F);
	float temp;

	SYNTHESIZE(int, m_row, Row);
	SYNTHESIZE(int, m_col, Col);

	SYNTHESIZE(bool, m_isClose, IsClose);
	SYNTHESIZE(bool, m_isOpen, IsOpen);
public:
	cGridNode();
	~cGridNode();

	void SetUp(D3DXVECTOR3 pos, int row, int col);
	void Render();

	void SetClean();

	void SetColorYellow()
	{
		m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(1, 1, 0, 1);
	}

	void SetColorDefault()
	{
		m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(0, 0, 1, 1);
	}
};