#include "stdafx.h"
#include "cMapTool.h"
#include "cGridNode.h"
#include "cAStar.h"
#include "cRay.h"

cMapTool::cMapTool()
{
}

cMapTool::~cMapTool()
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
	for (int row = 0; row < m_row; row++)
	{
		for (int col = 0; col < m_col; col++)
		{
			SAFE_RENDER(m_nodeList[row][col]);
		}
	}
}

void cMapTool::CreateNode(D3DXVECTOR3 pos)
{
	int row = abs((pos.x - m_leftTop.x + (TILE_SIZE * 0.5f)) / TILE_SIZE);
	int col = abs((pos.z - m_leftTop.z - (TILE_SIZE * 0.5f)) / TILE_SIZE);
	CreateNode(row, col);
}

void cMapTool::CreateNode(int row, int col)
{
	D3DXVECTOR3 pos = m_leftTop;
	pos.x += row * TILE_SIZE;
	pos.z -= col * TILE_SIZE;
	cGridNode* pNode = new cGridNode;
	pNode->SetUp(pos);
	m_nodeList[row][col] = pNode;
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

bool cMapTool::FindPickingPosition(IN int x, IN int y, OUT D3DXVECTOR3& pos)
{
	vector<D3DXVECTOR3> ground = FindPickingGround();

	cRay ray = cRay::RayAtWorldSpace(x, y);
	float dist = 0;
	float nearDist = -1;
	for (size_t i = 0; i < ground.size(); i += 3)
	{
		if (D3DXIntersectTri(&ground[i], &ground[i + 1], &ground[i + 2], &ray.GetRayOrg(), &ray.GetRayDir(), NULL, NULL, &dist))
		{
			if (nearDist < 0) nearDist = dist;
			else if (dist < nearDist) nearDist = dist;
		}
	}

	if (nearDist < 0) return false;

	pos = ray.GetRayOrg() + ray.GetRayDir() * nearDist;

	return true;
}

bool cMapTool::FindRowCol(IN D3DXVECTOR3 pos, OUT int & row, OUT int & col)
{
	int rtnRow = (pos.x - m_leftTop.x) / TILE_SIZE;
	int rtnCol = m_col - (pos.z - m_leftTop.z) / TILE_SIZE;
	row = rtnRow;
	col = rtnCol;

	if (rtnRow >= m_row || rtnCol >= m_col || rtnRow < 0 || rtnCol < 0) return false;
	return true;
}
