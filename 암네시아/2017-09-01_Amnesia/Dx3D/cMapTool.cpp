#include "stdafx.h"
#include "cMapTool.h"
#include "cGridNode.h"
#include "cAStar.h"
#include "cRay.h"
#include "cMapObject.h"
#include "cMapMesh.h"
#include "cMapWall.h"

cMapTool::cMapTool()
	: m_curTag(0)
	, m_curFloor(0)
{
}

cMapTool::~cMapTool()
{
	DestroyNode();
	DestroyMesh();
	DestroyTile();
}

void cMapTool::SetUp(D3DXVECTOR3 leftTop, int row, int col)
{
	m_leftTop = leftTop;
	m_rowMax = row;
	m_colMax = col;
	CreateMesh();
}

void cMapTool::Update()
{
}

void cMapTool::Render()
{
	RenderNode();
	TileRender();
	RenderWall();
}

void cMapTool::CreateNode(D3DXVECTOR3 pos)
{
	int row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	int col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	CreateNode(row, col);
}

void cMapTool::CreateNode(int row, int col)
{
	if (m_nodeList[row][col] || row < 0 || row >= m_rowMax || col < 0 || col >= m_colMax) return;
	D3DXVECTOR3 pos = m_leftTop;
	pos.x += row * GRIDNODE_SIZE;
	pos.z -= col * GRIDNODE_SIZE;
	cGridNode* pNode = new cGridNode;
	pNode->SetUp(pos);
	m_nodeList[row][col] = pNode;
}

void cMapTool::DestroyNode()
{
	for (size_t row = 0; row < m_rowMax; row++)
	{
		for (size_t col = 0; col < m_colMax; col++)
		{
			SAFE_DELETE(m_nodeList[row][col]);
		}
	}
}

void cMapTool::RenderNode()
{
	for (int row = 0; row < m_rowMax; row++)
	{
		for (int col = 0; col < m_colMax; col++)
		{
			SAFE_RENDER(m_nodeList[row][col]);
		}
	}
}

void cMapTool::CreateTile(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl)
{
	int row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	int col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	if (row >= m_rowMax || col >= m_colMax) return;
	vector<cMapObject*> tileList = m_tileList[row][col];
	for each(auto p in tileList)
	{
		if (p->GetTag() == m_curTag)
		{
			if (p->GetFloor() == m_curFloor) return;
			else break;
		}
	}
	D3DXVECTOR3 _pos = m_leftTop;
	_pos.x += row * GRIDNODE_SIZE;
	_pos.y = m_curFloor;
	_pos.z -= col * GRIDNODE_SIZE;
	cMapObject* obj = new cMapObject;
	obj->Setup(m_curTag, _pos, rot, scl);
	obj->SetFloor(m_curFloor);
	obj->SetTag(m_curTag);
	m_tileList[row][col].push_back(obj);
}

void cMapTool::DeleteTile(D3DXVECTOR3 pos)
{
	int row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	int col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	if (m_tileList.find(row)->second.find(col)->second.size() > 0)
	{
		vector<cMapObject*>::iterator it = m_tileList[row][col].begin();
		for (; it != m_tileList[row][col].end(); it++)
		{
			if ((*it)->GetTag() == m_curTag && (*it)->GetFloor() == m_curFloor)
			{
				cMapObject* pObj = (*it);
				m_tileList[row][col].erase(it);
				SAFE_DELETE(pObj);
				return;
			}
		}
	}
}

void cMapTool::DestroyTile()
{
	for (int row = 0; row < m_rowMax; row++)
	{
		for (int col = 0; col < m_colMax; col++)
		{
			for each(auto p in m_tileList[row][col])
			{
				SAFE_DELETE(p);
			}
		}
	}
}

void cMapTool::TileRender()
{
	D3DMATERIAL9 mat;
	ZeroMemory(&mat, sizeof(D3DMATERIAL9));
	mat.Ambient = mat.Diffuse = mat.Specular = D3DXCOLOR(1, 1, 1, 1);
	g_pD3DDevice->SetMaterial(&mat);
	for (int row = 0; row < m_rowMax; row++)
	{
		for (int col = 0; col < m_colMax; col++)
		{
			if (m_tileList[row][col].size() > 0)
			{
				for each(auto p in m_tileList[row][col])
				{
					m_meshList[p->GetTag()]->Render(p->GetPosition(), p->GetRotation(), p->GetScale());
				}
			}
		}
	}
}

void cMapTool::CreateMesh()
{
	CreateMesh(MAPMESH_TAG_CEILING_DEFAULT);
	CreateMesh(MAPMESH_TAG_CEILING_BROKEN);
	CreateMesh(MAPMESH_TAG_WALL_WORN);
	CreateMesh(MAPMESH_TAG_PILLAR_DEFAULT);
	CreateMesh(MAPMESH_TAG_PILLAR_FULL);
	CreateMesh(MAPMESH_TAG_FLOOR_DEFAULT);
	CreateMesh(MAPMESH_TAG_CONCAVE_WORN);
	CreateMesh(MAPMESH_TAG_CORNER_CONCAVE_WORN);
	CreateMesh(MAPMESH_TAG_CORNER_CONVER_SHORT);
}

void cMapTool::CreateMesh(int id)
{
	cMapMesh* pMesh = new cMapMesh;
	pMesh->Setup(id);
	m_meshList[id] = pMesh;
}

void cMapTool::DestroyMesh()
{
	for each(auto p in m_meshList)
	{
		SAFE_DELETE(p.second);
	}
}

void cMapTool::CreateWall(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos)
{
	int sRow, sCol, eRow, eCol;
	cMapWall wall;
	FindRowCol(startPos, sRow, sCol);
	FindRowCol(endPos, eRow, eCol);
	wall.SetPosition(startPos, endPos, 5);
	wall.SetRowCol(sRow, sCol, eRow, eCol);
	m_pickingWall.push_back(wall);
}

void cMapTool::DeleteWall(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos)
{
	int sRow, sCol, eRow, eCol;
	FindRowCol(startPos, sRow, sCol);
	FindRowCol(endPos, eRow, eCol);
	vector<cMapWall>::iterator it = m_pickingWall.begin();
	for (; it != m_pickingWall.end(); it++)
	{
		if ((*it).IsSame(sRow, sCol, eRow, eCol))
		{
			m_pickingWall.erase(it);
			return;
		}
	}
}

void cMapTool::RenderWall()
{
	for each(auto p in m_pickingWall)
	{
		p.Render();
	}
}

void cMapTool::RenderCurrentTag(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl)
{
	int row, col;
	FindRowCol(pos, row, col);
	D3DXVECTOR3 _pos = m_leftTop;
	_pos.x += row * GRIDNODE_SIZE;
	_pos.y = m_curFloor;
	_pos.z -= col * GRIDNODE_SIZE;
	m_meshList[m_curTag]->Render(_pos, rot, scl);
}

vector<D3DXVECTOR3> cMapTool::FindPickingGround()
{
	D3DXVECTOR3 rightBottom = m_leftTop;
	rightBottom.x = m_leftTop.x + m_rowMax * GRIDNODE_SIZE;
	rightBottom.z = m_leftTop.z - m_colMax * GRIDNODE_SIZE;

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
	row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);

	if (row >= m_rowMax || col >= m_colMax || row < 0 || col < 0) return false;
	return true;
}

void cMapTool::FindNearNode(IN D3DXVECTOR3 pos, OUT D3DXVECTOR3& nodePos)
{
	int row, col;
	FindRowCol(pos, row, col);
	nodePos = m_leftTop;
	nodePos.x += row * GRIDNODE_SIZE;
	nodePos.y = m_curFloor;
	nodePos.z -= col * GRIDNODE_SIZE;
}
