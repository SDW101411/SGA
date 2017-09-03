#include "stdafx.h"
#include "cAStar.h"
#include "cGridNode.h"

cAStar::cAStar()
{
}

cAStar::~cAStar()
{
	for (int row = 0; row < m_rowMax; row++)
	{
		for (int col = 0; col < m_colMax; col++)
		{
			SAFE_DELETE(m_nodeList[row][col]);
		}
	}
}

void cAStar::SetUp(D3DXVECTOR3 leftTop, int row, int col)
{
	m_leftTopPos = leftTop;
	m_rowMax = row;
	m_colMax = col;
}

void cAStar::Render()
{
	for (int row = 0; row < m_rowMax; row++)
	{
		for (int col = 0; col < m_colMax; col++)
		{
			SAFE_RENDER(m_nodeList[row][col]);
		}
	}
}

void cAStar::CreateNode(D3DXVECTOR3 pos, int row, int col)
{
	cGridNode* pNode = new cGridNode;
	pNode->SetUp(pos);
	m_nodeList[row][col] = pNode;
}

void cAStar::CreateNode(D3DXVECTOR3 pos)
{
	cGridNode* pNode = new cGridNode;
	pNode->SetUp(pos);
	int row = abs((pos.x - m_leftTopPos.x) / TILE_SIZE);
	int col = abs((pos.z - m_leftTopPos.z) / TILE_SIZE);
	m_nodeList[row][col] = pNode;
}

void cAStar::CreateNode(int row, int col)
{
	D3DXVECTOR3 pos = m_leftTopPos;
	pos.x += row * TILE_SIZE;
	pos.z -= col * TILE_SIZE;
	CreateNode(pos, row, col);
}

bool cAStar::FindRowCol(IN D3DXVECTOR3 pos, OUT int & row, OUT int & col)
{
	int rtnRow = abs((pos.x - m_leftTopPos.x) / TILE_SIZE);
	int rtnCol = abs((pos.z - m_leftTopPos.z) / TILE_SIZE);
	row = rtnRow;
	col = rtnCol;

	if (rtnRow >= m_rowMax || rtnCol >= m_colMax || rtnRow < 0 || rtnCol < 0) return false;
	return true;
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
	vector<cGridNode*>::iterator it = openList.begin();

	for (; it != openList.end(); it++)
	{
		if ((*it) == pNode)
		{
			openList.erase(it);
			break;
		}
	}

	pNode->SetIsOpen(false);
	pNode->SetIsClose(true);
}

list<D3DXVECTOR3> cAStar::FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end)
{
	return list<D3DXVECTOR3>();
}
