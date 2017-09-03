#pragma once

#define TILE_SIZE 1

class cAStarNode;

class cAStar
{
private:
	vector<cAStarNode*>	m_nodeList;
	D3DXVECTOR3			m_leftTopPos;
	int					m_rowMax;
	int					m_colMax;

public:
	cAStar();
	~cAStar();
	void SetUp(D3DXVECTOR3 leftTop, int row, int col);
	void Render();

	list<D3DXVECTOR3> FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end);
};