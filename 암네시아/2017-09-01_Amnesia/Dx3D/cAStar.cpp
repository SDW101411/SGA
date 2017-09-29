#include "stdafx.h"
#include "cAStar.h"
#include "cGridNode.h"
#include "cMapLoader.h"
#include "cMapTool.h"

cAStar::cAStar()
{
	cMapLoader loader;
}

cAStar::~cAStar()
{
	map<int, map<int, cGridNode*>>::iterator row = m_nodeList.begin();
	for (; row != m_nodeList.end(); row++)
	{
		map<int, cGridNode*>::iterator col = (*row).second.begin();
		for (; col != (*row).second.end(); col++)
		{
			SAFE_DELETE((*col).second);
		}
	}
}

void cAStar::Render()
{
	map<int, map<int, cGridNode*>>::iterator first = m_nodeList.begin();
	for (; first != m_nodeList.end(); first++)
	{
		map<int, cGridNode*>::iterator second = (*first).second.begin();
		for (; second != (*first).second.end(); second++)
		{
			SAFE_RENDER((*second).second);
		}
	}
}

void cAStar::AddNearNode(IN D3DXVECTOR3 pos, OUT vector<cGridNode> openList)
{
	int centerRow = 0;
	int centerCol = 0;
	if (FindRowCol(pos, centerRow, centerCol))	// 가운데 노드가 존재할경우
	{
		DWORD state = 0;
	}
}

void cAStar::AddCloseList(IN cGridNode* pNode, OUT vector<cGridNode*> openList, OUT vector<cGridNode*> closeList)
{
	if (pNode == NULL) return;

	vector<cGridNode*>::iterator it = openList.begin();

	for (; it != openList.end(); it++)
	{
		if ((*it) == pNode)
		{
			openList.erase(it);
			break;
		}
	}
}

list<D3DXVECTOR3> cAStar::FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end)
{
	vector<cGridNode*> OpenList;
	vector<cGridNode*> CloseList;
	return list<D3DXVECTOR3>();
}

bool cAStar::FindRowCol(IN D3DXVECTOR3 pos, OUT int & row, OUT int & col)
{
	row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	if (row < 0 || col < 0) return false;
	return true;
}
