#include "stdafx.h"
#include "cMapTool.h"
#include "cGridNode.h"

cMapTool::cMapTool()
{
}

cMapTool::~cMapTool()
{
}

void cMapTool::SetUp(D3DXVECTOR3 leftTop, int row, int col)
{
	m_leftTop = leftTop;
	m_row = row;
	m_col = col;
}

void cMapTool::Update()
{
}

void cMapTool::Render()
{
}

vector<D3DXVECTOR3> cMapTool::FindPickingGround()
{
	D3DXVECTOR3 rightBottom = m_leftTop;
	rightBottom.x = m_leftTop.x + m_row * TILE_SIZE;
	rightBottom.z = m_leftTop.z - m_col * TILE_SIZE;

	D3DXVECTOR3 rightTop = D3DXVECTOR3(rightBottom.x, 0, m_leftTop.z);
	D3DXVECTOR3 leftBottom = D3DXVECTOR3(m_leftTop.x, 0, rightBottom.z);
	vector<D3DXVECTOR3> rtnVec;
	rtnVec.push_back(m_leftTop);
	rtnVec.push_back(rightTop);
	rtnVec.push_back(rightBottom);

	rtnVec.push_back(m_leftTop);
	rtnVec.push_back(rightBottom);
	rtnVec.push_back(leftBottom);

	return rtnVec;
}
