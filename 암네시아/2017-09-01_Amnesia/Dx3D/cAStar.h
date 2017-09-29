#pragma once

class cGridNode;

enum GRIDNODE_DIR
{
	GRIDNODE_DIR_LEFT = 1 << 0,
	GRIDNODE_DIR_RIGHT = 1 << 1,
	GRIDNODE_DIR_UP = 1 << 2,
	GRIDNODE_DIR_DOWN = 1 << 3,
};

class cAStar
{
private:
	map<int, map<int, cGridNode*>>	m_nodeList;
	D3DXVECTOR3						m_leftTop;
	int								m_curRow;
	int								m_curCol;

private:
	SYNTHESIZE(bool, m_isClear, IsClear);
	SYNTHESIZE(vector<cGridNode*>, m_nodeData, NodeData);

public:
	cAStar();
	~cAStar();
	void Render();

	void AddNearNode(IN D3DXVECTOR3 pos, OUT vector<cGridNode> openList);
	void AddCloseList(IN cGridNode* pNode, OUT vector<cGridNode*> openList, OUT vector<cGridNode*> closeList);

	list<D3DXVECTOR3> FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end);
	bool FindRowCol(IN D3DXVECTOR3 pos, OUT int& row, OUT int& col);

	static void SetNodeCleanFunc(LPVOID param);
};