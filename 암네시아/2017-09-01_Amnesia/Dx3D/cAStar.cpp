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
}

void cAStar::CreateNode(D3DXVECTOR3 pos, int row, int col)
{
}

list<D3DXVECTOR3> cAStar::FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end)
{
	return list<D3DXVECTOR3>();
}
