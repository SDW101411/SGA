#pragma once

class cGridNode
{
private:
	LPD3DXMESH m_pSphere;
	LPD3DXMESH m_pBox;

	LPDIRECT3DINDEXBUFFER9	m_ib;
	LPDIRECT3DVERTEXBUFFER9	m_vb;

	D3DXMATRIX m_matWorld;

	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);

	SYNTHESIZE(cGridNode*, m_pParent, Parent);

	SYNTHESIZE(float, m_g, G);
	SYNTHESIZE(float, m_h, H);
	SYNTHESIZE(float, m_f, F);

	SYNTHESIZE(bool, m_isOpen, IsOpen);
	SYNTHESIZE(bool, m_isClose, IsClose);
	SYNTHESIZE(bool, m_isObstacle, IsObstacle);
public:
	cGridNode();
	~cGridNode();

	void SetUp(D3DXVECTOR3 pos);
	void Render();
	void SphereRender();

	void CleanUp();
};