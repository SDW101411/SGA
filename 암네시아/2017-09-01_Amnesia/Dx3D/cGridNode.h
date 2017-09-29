#pragma once

enum GRIDNODE_COLOR
{
	GRIDNODE_COLOR_DEFAULT,
	GRIDNODE_COLOR_PICK,
	GRIDNODE_COLOR_OBSTACLE,
};

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

	SYNTHESIZE(bool, m_isObstacle, IsObstacle);
public:
	cGridNode();
	~cGridNode();

	void SetUp(D3DXVECTOR3 pos);
	void Render();

	void SetColor(GRIDNODE_COLOR value);
};