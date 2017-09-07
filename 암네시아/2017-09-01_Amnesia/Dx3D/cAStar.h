#pragma once

#define TILE_SIZE 1

class cGridNode;

class cAStar
{
private:
	// m_node[row][col]로 관리합니다.
	map<int, map<int, cGridNode*>>	m_nodeList;
	D3DXVECTOR3			m_leftTopPos;
	int					m_rowMax;
	int					m_colMax;

public:
	enum GRIDNODE_DIR
	{
		GRIDNODE_DIR_LEFT = 1 << 0,
		GRIDNODE_DIR_RIGHT = 1 << 1,
		GRIDNODE_DIR_UP = 1 << 2,
		GRIDNODE_DIR_DOWN = 1 << 3,
	};

public:
	cAStar();
	~cAStar();
	void SetUp(D3DXVECTOR3 leftTop, int row, int col);
	void Render();

	void CreateNode(D3DXVECTOR3 pos, int row, int col);
	void CreateNode(D3DXVECTOR3 pos);
	void CreateNode(int row, int col);

	bool FindRowCol(IN D3DXVECTOR3 pos, OUT int& row, OUT int& col);

	void AddNearNode(IN D3DXVECTOR3 pos, OUT vector<cGridNode> openList);
	void AddCloseList(IN cGridNode* pNode, OUT vector<cGridNode*> openList, OUT vector<cGridNode*> closeList);

	list<D3DXVECTOR3> FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end);
};