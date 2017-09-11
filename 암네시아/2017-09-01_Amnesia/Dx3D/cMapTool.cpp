#include "stdafx.h"
#include "cMapTool.h"
#include "cGridNode.h"
#include "cAStar.h"
#include "cRay.h"
#include "cMapObject.h"

cMapTool::cMapTool()
{
}

cMapTool::~cMapTool()
{
	for (size_t row = 0; row < m_row; row++)
	{
		for (size_t col = 0; col < m_col; col++)
		{
			SAFE_DELETE(m_nodeList[row][col]);
		}
	}

	for each(auto p in m_objList)
	{
		SAFE_DELETE(p.second);
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
	if (KEYMANAGER->isToggleKey('Q'))
	{
		for (int row = 0; row < m_row; row++)
		{
			for (int col = 0; col < m_col; col++)
			{
				SAFE_RENDER(m_nodeList[row][col]);
			}
		}
	}

	if (KEYMANAGER->isToggleKey('E'))
	{
		for each (auto p in m_objList)
		{
			p.second->Render();
		}
	}
}

void cMapTool::CreateNode(D3DXVECTOR3 pos)
{
	int row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	int col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	CreateNode(row, col);
}

void cMapTool::CreateNode(int row, int col)
{
	if (m_nodeList[row][col] || row < 0 || row >= m_row || col < 0 || col >= m_col) return;
	D3DXVECTOR3 pos = m_leftTop;
	pos.x += row * GRIDNODE_SIZE;
	pos.z -= col * GRIDNODE_SIZE;
	cGridNode* pNode = new cGridNode;
	pNode->SetUp(pos);
	m_nodeList[row][col] = pNode;
}

void cMapTool::CreateObject(int id, D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl)
{
	int row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	int col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	if (row < 0 || row >= m_row || col < 0 || col >= m_col) return;
	D3DXVECTOR3 _pos = m_leftTop;
	_pos.x += row * GRIDNODE_SIZE;
	_pos.z -= col * GRIDNODE_SIZE;
	_pos.y = 0;
	if (m_objList[id])
	{
		m_objList[id]->AddObject(_pos, rot, scl);
	}
	else
	{
		cMapObject* pObj = new cMapObject;
		pObj->Setup(id);
		pObj->AddObject(_pos, rot, scl);
		m_objList[id] = pObj;
	}
}

vector<D3DXVECTOR3> cMapTool::FindPickingGround()
{
	D3DXVECTOR3 rightBottom = m_leftTop;
	rightBottom.x = m_leftTop.x + m_row * GRIDNODE_SIZE;
	rightBottom.z = m_leftTop.z - m_col * GRIDNODE_SIZE;

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

bool cMapTool::FindPickingPosition(OUT D3DXVECTOR3& pos, vector<D3DXVECTOR3> ground)
{
	cRay ray = cRay::RayAtWorldSpace(_ptMousePos.x, _ptMousePos.y);
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
	int rtnRow = (pos.x - m_leftTop.x) / GRIDNODE_SIZE;
	int rtnCol = m_col - (pos.z - m_leftTop.z) / GRIDNODE_SIZE;
	row = rtnRow;
	col = rtnCol;

	if (rtnRow >= m_row || rtnCol >= m_col || rtnRow < 0 || rtnCol < 0) return false;
	return true;
}
