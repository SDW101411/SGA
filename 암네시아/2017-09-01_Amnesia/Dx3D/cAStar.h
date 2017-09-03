#pragma once

#define TILE_SIZE 1

class cAStarNode;
class cGridNode;

class cAStar
{
private:
	map<int, map<int, cGridNode*>>	m_nodeList;
	D3DXVECTOR3			m_leftTopPos;
	int					m_rowMax;
	int					m_colMax;

public:
	cAStar();
	~cAStar();
	void SetUp(D3DXVECTOR3 leftTop, int row, int col);
	void Render();

	void CreateNode(D3DXVECTOR3 pos, int row, int col);

	list<D3DXVECTOR3> FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end);
};