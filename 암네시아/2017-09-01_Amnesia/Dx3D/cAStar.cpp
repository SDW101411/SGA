#include "stdafx.h"
#include "cAStar.h"
#include "cGridNode.h"

cAStar::cAStar()
{
}

cAStar::~cAStar()
{
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
			m_nodeList[row][col]->Render();
		}
	}
}

void cAStar::CreateNode(D3DXVECTOR3 pos, int row, int col)
{
	cGridNode* pNode = new cGridNode;
	pNode->SetUp(pos);
	m_nodeList[row][col] = pNode;
}

list<D3DXVECTOR3> cAStar::FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end)
{
	return list<D3DXVECTOR3>();
}
