#pragma once
#include <set>

class cGridNode;

class cAStar
{
private:
	enum
	{
		GRIDNODE_DIR_LEFT = 1 << 0,
		GRIDNODE_DIR_RIGHT = 1 << 1,
		GRIDNODE_DIR_UP = 1 << 2,
		GRIDNODE_DIR_DOWN = 1 << 3,
	};
	typedef int GRIDNODE_DIR;

private:
	map<int, map<int, cGridNode*>>	m_nodeList;
	set<cGridNode*>					m_openList;
	vector<GRIDNODE_DIR>			m_dirList;
	map<GRIDNODE_DIR, float>		m_distList;
	D3DXVECTOR3						m_leftTop;
	int								m_curRow;
	int								m_curCol; 


	CRITICAL_SECTION				m_cs;
	DWORD							m_dwThID;

private:
	SYNTHESIZE(bool, m_isClear, IsClear);
	SYNTHESIZE(vector<cGridNode*>, m_nodeData, NodeData);

public:
	cAStar();
	~cAStar();
	void Render();

	list<D3DXVECTOR3> FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end);

	void AddOpenList(cGridNode* pNode);
	void AddCloseList(cGridNode* pNode);
	void ClearOpenList();
	cGridNode* MinFNodeAtOpenList();

	cGridNode* GetAdjNode(cGridNode* pExtNode, GRIDNODE_DIR e); // pExtNode의 e방향에 확장 대상 노드가 없는경우 NULL 리턴
	void Extend(cGridNode* pCurrNode, cGridNode* pDestNode);
	float CalcHeuristic(cGridNode* pCurrentNode, cGridNode* pDestNode);

	cGridNode* FindNode(D3DXVECTOR3 pos);
	bool FindRowCol(IN D3DXVECTOR3 pos, OUT int& row, OUT int& col);

	static void SetNodeCleanFunc(LPVOID param);
};