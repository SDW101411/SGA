#include "stdafx.h"
#include "cMapLoader.h"
#include "cObject_Game.h"
#include "cMapObject.h"
#include "cObject_Map.h"
#include "cObject_Light.h"

vector<cObject_Map*> cMapLoader::LoadToObject_Map()
{
	vector<cObject_Map*> rtnObjList;

	m_fp = fopen("Data/MapData.txt", "r");

	char* str;

	while (!feof(m_fp))
	{
		str = GetToken();

		if (str == NULL) continue;
		else if (IsEqual(str, ID_LTPOS))
		{
			m_leftTop.x = GetFloat();
			m_leftTop.y = GetFloat();
			m_leftTop.z = GetFloat();
			GetToken();
		}
		else if (IsEqual(str, ID_MESH))
		{
			while (true)
			{
				str = GetToken();
				if (IsEqual(str, ID_MAPMESH_TAG_CEILING_DEFAULT))
					PushObject_Map(MAPMESH_TAG_CEILING_DEFAULT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CEILING_BROKEN))
					PushObject_Map(MAPMESH_TAG_CEILING_BROKEN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CEILING_NORMAL))
					PushObject_Map(MAPMESH_TAG_CEILING_NORMAL, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_WALL_WORN))
					PushObject_Map(MAPMESH_TAG_WALL_WORN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_PILLAR_DEFAULT))
					PushObject_Map(MAPMESH_TAG_PILLAR_DEFAULT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_PILLAR_FULL))
					PushObject_Map(MAPMESH_TAG_PILLAR_FULL, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_FLOOR_DEFAULT))
					PushObject_Map(MAPMESH_TAG_FLOOR_DEFAULT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CONCAVE_WORN))
					PushObject_Map(MAPMESH_TAG_CONCAVE_WORN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CORNER_CONCAVE_WORN))
					PushObject_Map(MAPMESH_TAG_CORNER_CONCAVE_WORN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CORNER_CONVER_SHORT))
					PushObject_Map(MAPMESH_TAG_CORNER_CONVER_SHORT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_TORCH_STATIC_01))
					PushObject_Map(MAPMESH_TAG_TORCH_STATIC_01, rtnObjList);
				else if (IsEqual(str, ID_END))
					break;
			}
		}
	}

	fclose(m_fp);

	return rtnObjList;
}

vector<cObject_Light*> cMapLoader::LoadToObject_Light()
{
	vector<cObject_Light*> lightPos;

	m_fp = fopen("Data/MapData.txt", "r");

	char* str;

	while (!feof(m_fp))
	{
		str = GetToken();

		if (str == NULL) continue;
		else if (IsEqual(str, ID_MESH))
		{
			while (true)
			{
				str = GetToken();
				if (str == NULL) continue;
				else if (IsEqual(str, ID_MAPMESH_TAG_TORCH_STATIC_01))
				{
					PushLight(lightPos);
				}
			}
		}
	}

	fclose(m_fp);

	return lightPos;
}

vector<D3DXVECTOR3> cMapLoader::LoadToGroundSurface()
{
	vector<D3DXVECTOR3> rtnObjList;

	m_fp = fopen("Data/MapData.txt", "r");

	char* str;

	while (!feof(m_fp))
	{
		str = GetToken();

		if (str == NULL) continue;
		else if (IsEqual(str, ID_SURFACE))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(LoadVec3());
			}
		}
	}

	fclose(m_fp);

	return rtnObjList;
}

map<int, map<int, vector<cMapObject*>>> cMapLoader::LoadToMapObject()
{
	map<int, map<int, vector<cMapObject*>>> rtnObjList;

	m_fp = fopen("Data/MapData.txt", "r");

	char* str;

	while (!feof(m_fp))
	{
		str = GetToken();
		if (str == NULL) continue;
		else if (IsEqual(str, ID_LTPOS))
		{
			m_leftTop.x = GetFloat();
			m_leftTop.y = GetFloat();
			m_leftTop.z = GetFloat();
			GetToken();
		}
		else if (IsEqual(str, ID_MESH))
		{
			while (true)
			{
				str = GetToken();
				if (IsEqual(str, ID_MAPMESH_TAG_CEILING_DEFAULT))
					PushMapObject(MAPMESH_TAG_CEILING_DEFAULT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CEILING_BROKEN))
					PushMapObject(MAPMESH_TAG_CEILING_BROKEN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CEILING_NORMAL))
					PushMapObject(MAPMESH_TAG_CEILING_NORMAL, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_WALL_WORN))
					PushMapObject(MAPMESH_TAG_WALL_WORN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_PILLAR_DEFAULT))
					PushMapObject(MAPMESH_TAG_PILLAR_DEFAULT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_PILLAR_FULL))
					PushMapObject(MAPMESH_TAG_PILLAR_FULL, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_FLOOR_DEFAULT))
					PushMapObject(MAPMESH_TAG_FLOOR_DEFAULT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CONCAVE_WORN))
					PushMapObject(MAPMESH_TAG_CONCAVE_WORN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CORNER_CONCAVE_WORN))
					PushMapObject(MAPMESH_TAG_CORNER_CONCAVE_WORN, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_CORNER_CONVER_SHORT))
					PushMapObject(MAPMESH_TAG_CORNER_CONVER_SHORT, rtnObjList);
				else if (IsEqual(str, ID_MAPMESH_TAG_TORCH_STATIC_01))
					PushMapObject(MAPMESH_TAG_TORCH_STATIC_01, rtnObjList);
				else if (IsEqual(str, ID_END))
					break;
			}
		}
	}

	fclose(m_fp);

	return rtnObjList;
}

void cMapLoader::PushNearLight(IN vector<cObject_Light*> objLight, IN vector<cObject_Map*>& objMap)
{
	for each(auto map in objMap)
	{
		for each(auto light in objLight)
		{
			if (GetDistance(light->m_lightPos, map->GetPosition()) < 12)
				map->m_Light_Vec_Push(light);
		}
	}
}

char * cMapLoader::GetToken()
{
	bool isQuote = false;
	int nReadCount = 0;
	while (!feof(m_fp))
	{
		char c = fgetc(m_fp);
		if (c == '\"')
		{
			if (isQuote) break;
			isQuote = true;
			continue;
		}

		if (c < 33 && !isQuote)
		{
			if (nReadCount == 0) continue;
			break;
		}
		m_szToken[nReadCount++] = c;
	}

	if (nReadCount == 0)
		return NULL;

	m_szToken[nReadCount] = '\0';
	return m_szToken;
}

bool cMapLoader::IsEqual(char * str1, char * str2)
{
	return strcmp(str1, str2) == 0;
}

float cMapLoader::GetFloat()
{
	return (float)atof(GetToken());
}

D3DXVECTOR3 cMapLoader::LoadVec3()
{
	D3DXVECTOR3 vec;
	vec.x = GetFloat();
	vec.y = GetFloat();
	vec.z = GetFloat();
	return vec;
}

cObject_Map* cMapLoader::CreateObject_Map(cMesh_Object_Tag id)
{
	D3DXVECTOR3 pos = LoadVec3();
	D3DXVECTOR3 rot = LoadVec3();
	D3DXVECTOR3 scl = LoadVec3();
	cObject_Map* pObj = new cObject_Map(id, pos, rot, scl);
	return pObj;
}

cMapObject* cMapLoader::CreateMapObject(int id)
{
	D3DXVECTOR3 pos = LoadVec3();
	D3DXVECTOR3 rot = LoadVec3();
	D3DXVECTOR3 scl = LoadVec3();
	cMapObject* pObj = new cMapObject;
	pObj->Setup(id, pos, rot, scl);
	return pObj;
}

cObject_Light* cMapLoader::CreateObject_Light()
{
	D3DXVECTOR3 pos = LoadVec3();
	D3DXVECTOR3 rot = LoadVec3();
	D3DXVECTOR3 scl = LoadVec3();
	D3DXVECTOR3 lightPos, dir;
	D3DXMATRIX	matRX, matRY, matRZ, matR;
	D3DXMatrixRotationX(&matRX, rot.x);
	D3DXMatrixRotationY(&matRY, rot.y);
	D3DXMatrixRotationZ(&matRZ, rot.z);
	matR = matRX * matRY * matRZ;
	D3DXVec3TransformCoord(&dir, &D3DXVECTOR3(0, 1, -1), &matR);
	cObject_Light* pLight = new cObject_Light(MAPMESH_TAG_TORCH_STATIC_01, pos, rot, scl, pos + dir);
	return pLight;
}

void cMapLoader::PushMapObject(int id, map<int, map<int, vector<cMapObject*>>>& pObjList)
{
	while (true)
	{
		if (IsEqual(GetToken(), ID_END)) break;
		cMapObject* pObj = CreateMapObject(id);
		D3DXVECTOR3 pos = pObj->GetPosition();
		int row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
		int col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
		pObjList[row][col].push_back(pObj);
	}
}

void cMapLoader::PushObject_Map(cMesh_Object_Tag id, vector<cObject_Map*>& rtnObjList)
{
	while (true)
	{
		if (IsEqual(GetToken(), ID_END)) break;
		rtnObjList.push_back(CreateObject_Map(id));
	}
}

void cMapLoader::PushLight(vector<cObject_Light*>& lightPos)
{
	while (true)
	{
		if (IsEqual(GetToken(), ID_END)) break;
		lightPos.push_back(CreateObject_Light());
	}
}

float cMapLoader::GetDistance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
{
	D3DXVECTOR3 dist = pos1 - pos2;
	return sqrtf(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);
}