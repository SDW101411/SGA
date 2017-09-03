#pragma once

#define TILE_SIZE 1

class cGridNode;
class cAStar;

class cMapTool
{
private:
	D3DXVECTOR3		m_leftTop;
	int				m_row;
	int				m_col;
	cGridNode*		m_pCurrentNode;

public:
	cMapTool();
	~cMapTool();

	void SetUp(D3DXVECTOR3 leftTop, int row, int col);
	void Update();
	void Render();

	vector<D3DXVECTOR3> FindPickingGround();
};