#include "stdafx.h"
#include "cMapTool.h"
#include "cGridNode.h"
#include "cAStar.h"
#include "cRay.h"
#include "cMapObject.h"
#include "cMapMesh.h"
#include "cMapSurface.h"
#include "cMapLoader.h"

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
	RenderGround();
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
	pNode->SetUp(pos, row, col);
	m_nodeList[row][col] = pNode;
}

void cMapTool::DeleteNode(D3DXVECTOR3 pos)
{
	int row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	int col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	DeleteNode(row, col);
}

void cMapTool::DeleteNode(int row, int col)
{
	if (row < 0 || row >= m_rowMax || col < 0 || col >= m_colMax) return;
	SAFE_DELETE(m_nodeList[row][col]);
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
	if (m_curTag == MAPMESH_TAG_CORNER_CONVER_SHORT)
	{
		_pos.x += 0.5f;
		_pos.z += 0.5f;
	}
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
	CreateMesh(MAPMESH_TAG_CEILING_NORMAL);
	CreateMesh(MAPMESH_TAG_WALL_WORN);
	CreateMesh(MAPMESH_TAG_PILLAR_DEFAULT);
	CreateMesh(MAPMESH_TAG_PILLAR_FULL);
	CreateMesh(MAPMESH_TAG_FLOOR_DEFAULT);
	CreateMesh(MAPMESH_TAG_CONCAVE_WORN);
	CreateMesh(MAPMESH_TAG_CORNER_CONCAVE_WORN);
	CreateMesh(MAPMESH_TAG_CORNER_CONVER_SHORT);
	CreateMesh(MAPMESH_TAG_TORCH_STATIC_01);
	CreateMesh(MAPMESH_TAG_BARREL_DEFAULT);
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
	cMapSurface wall;
	wall.SetWall(startPos, endPos, 5);
	m_wallSurface.push_back(wall);
}

void cMapTool::DeleteWall()
{
	vector<cMapSurface>::iterator it = m_wallSurface.begin();
	for (; it != m_wallSurface.end(); it++)
	{
		if (FindPickingPosition(D3DXVECTOR3(0, 0, 0), (*it).GetSurface()))
		{
			m_wallSurface.erase(it);
			break;
		}
	}
}

void cMapTool::RenderWall()
{
	for each(auto p in m_wallSurface)
	{
		p.RenderSurface();
	}
}

void cMapTool::CreateGround(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos)
{
	cMapSurface ground;
	ground.SetGround(startPos, endPos);
	m_groundSurface.push_back(ground);
}

void cMapTool::DeleteGround()
{
	vector<cMapSurface>::iterator it = m_groundSurface.begin();
	for (; it != m_groundSurface.end(); it++)
	{
		if (FindPickingPosition(D3DXVECTOR3(0, 0, 0), (*it).GetSurface()))
		{
			m_groundSurface.erase(it);
			break;
		}
	}
}

void cMapTool::RenderGround()
{
	for each(auto p in m_groundSurface)
	{
		p.RenderSurface();
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

void cMapTool::SaveData()
{
	char str[1024];
	FILE* fp = fopen("Data/MapData.txt", "w");
	map<int, vector<cMapObject*>> objData;
	for each(auto row in m_tileList)
	{
		for each(auto col in row.second)
		{
			if (col.second.size() > 0)
			{
				for each(auto p in col.second)
				{
					objData[p->GetTag()].push_back(p);
				}
			}
		}
	}

	fputs("<LEFTTOP>\n", fp);
	sprintf(str, "%f %f %f\n", m_leftTop.x, m_leftTop.y, m_leftTop.z);
	fputs(str, fp);
	fputs("END\n", fp);

	fputs("<MESH>\n", fp);
	PutData("MAPMESH_TAG_CEILING_DEFAULT\n",		fp, objData[MAPMESH_TAG_CEILING_DEFAULT]);
	PutData("MAPMESH_TAG_CEILING_BROKEN\n",			fp, objData[MAPMESH_TAG_CEILING_BROKEN]);
	PutData("MAPMESH_TAG_CEILING_NORMAL\n",			fp, objData[MAPMESH_TAG_CEILING_NORMAL]);
	PutData("MAPMESH_TAG_WALL_WORN\n",				fp, objData[MAPMESH_TAG_WALL_WORN]);
	PutData("MAPMESH_TAG_PILLAR_DEFAULT\n",			fp, objData[MAPMESH_TAG_PILLAR_DEFAULT]);
	PutData("MAPMESH_TAG_PILLAR_FULL\n",			fp, objData[MAPMESH_TAG_PILLAR_FULL]);
	PutData("MAPMESH_TAG_FLOOR_DEFAULT\n",			fp, objData[MAPMESH_TAG_FLOOR_DEFAULT]);
	PutData("MAPMESH_TAG_CONCAVE_WORN\n",			fp, objData[MAPMESH_TAG_CONCAVE_WORN]);
	PutData("MAPMESH_TAG_CORNER_CONCAVE_WORN\n",	fp, objData[MAPMESH_TAG_CORNER_CONCAVE_WORN]);
	PutData("MAPMESH_TAG_CORNER_CONVER_SHORT\n",	fp, objData[MAPMESH_TAG_CORNER_CONVER_SHORT]);
	PutData("MAPMESH_TAG_TORCH_STATIC_01\n",		fp, objData[MAPMESH_TAG_TORCH_STATIC_01]);
	PutData("MAPMESH_TAG_BARREL_DEFAULT\n",			fp, objData[MAPMESH_TAG_BARREL_DEFAULT]);
	fputs("END\n", fp);

	fputs("<SURFACE>\n", fp);
	PutSurface(fp);
	fputs("END\n", fp);

	fputs("<GRIDNODE>\n", fp);
	PutGridNode(fp);
	fputs("END\n", fp);

	fputs("<PLAYER>\n", fp);
	sprintf(str, "%f %f %f\n", m_playerPos.x, m_playerPos.y, m_playerPos.z);
	fputs(str, fp);
	fputs("END\n", fp);
	fputs("<MON1>\n", fp);
	sprintf(str, "%f %f %f\n", m_monsterPos1.x, m_monsterPos1.y, m_monsterPos1.z);
	fputs(str, fp);
	fputs("END\n", fp);
	fputs("<MON2>\n", fp);
	sprintf(str, "%f %f %f\n", m_monsterPos2.x, m_monsterPos2.y, m_monsterPos2.z);
	fputs(str, fp);
	fputs("END\n", fp);

	fclose(fp);
}

void cMapTool::LoadData()
{
	cMapLoader loader;
	m_tileList = loader.LoadToMapObject();
	m_nodeList = loader.LoadToGridNode();
}

void cMapTool::PutData(string name, FILE* fp, vector<cMapObject*> pObj)
{
	char str[1024];
	fputs(name.c_str(), fp);
	for each(auto p in pObj)
	{
		fputs("NEW\n", fp);
		D3DXVECTOR3 pos = p->GetPosition();
		D3DXVECTOR3 rot = p->GetRotation();
		D3DXVECTOR3 scl = p->GetScale();
		sprintf(str, "%f %f %f\n", pos.x, pos.y, pos.z);
		fputs(str, fp);
		sprintf(str, "%f %f %f\n", rot.x, rot.y, rot.z);
		fputs(str, fp);
		sprintf(str, "%f %f %f\n", scl.x, scl.y, scl.z);
		fputs(str, fp);
	}
	fputs("END\n", fp);
}

void cMapTool::PutSurface(FILE* fp)
{
	char str[1024];
	fputs("<WALL>\n", fp);
	for each(auto p in m_wallSurface)
	{
		vector<D3DXVECTOR3> vecList = p.GetSurface();
		for each(auto vec in vecList)
		{
			fputs("NEW\n", fp);
			sprintf(str, "%f %f %f\n", vec.x, vec.y, vec.z);
			fputs(str, fp);
		}
	}
	fputs("END\n", fp);
	fputs("<GROUND>\n", fp);
	for each(auto p in m_groundSurface)
	{
		vector<D3DXVECTOR3> vecList = p.GetSurface();
		for each(auto vec in vecList)
		{
			fputs("NEW\n", fp);
			sprintf(str, "%f %f %f\n", vec.x, vec.y, vec.z);
			fputs(str, fp);
		}
	}
	fputs("END\n", fp);
}

void cMapTool::PutGridNode(FILE* fp)
{
	char str[1024];
	for each(auto f in m_nodeList)
	{
		for each(auto s in f.second)
		{
			if (s.second)
			{
				fputs("NEW\n", fp);
				D3DXVECTOR3 pos = s.second->GetPosition();
				sprintf(str, "%f %f %f\n", pos.x, pos.y, pos.z);
				fputs(str, fp);
				sprintf(str, "%d %d\n", f.first, s.first);
				fputs(str, fp);
			}
		}
	}
	fputs("END\n", fp);
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
