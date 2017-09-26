#include "stdafx.h"
#include "cMapLoader.h"
#include "cObject_Game.h"
#include "cMapObject.h"
#include "cObject_Map.h"

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

D3DXVECTOR3 cMapLoader::LoadPos()
{
	D3DXVECTOR3 pos;
	pos.x = GetFloat();
	pos.y = GetFloat();
	pos.z = GetFloat();
	return pos;
}

D3DXVECTOR3 cMapLoader::LoadRot()
{
	D3DXVECTOR3 rot;
	rot.x = GetFloat();
	rot.y = GetFloat();
	rot.z = GetFloat();
	return rot;
}

D3DXVECTOR3 cMapLoader::LoadScl()
{
	D3DXVECTOR3 scl;
	scl.x = GetFloat();
	scl.y = GetFloat();
	scl.z = GetFloat();
	return scl;
}

cObject_Map* cMapLoader::CreateObject_Map(cMesh_Object_Tag id)
{
	D3DXVECTOR3 pos = LoadPos();
	D3DXVECTOR3 rot = LoadRot();
	D3DXVECTOR3 scl = LoadScl();
	cObject_Map* pObj = new cObject_Map(id, pos, rot, scl);
	return pObj;
}

cMapObject* cMapLoader::CreateMapObject(int id)
{
	D3DXVECTOR3 pos = LoadPos();
	D3DXVECTOR3 rot = LoadRot();
	D3DXVECTOR3 scl = LoadScl();
	cMapObject* pObj = new cMapObject;
	pObj->Setup(id, pos, rot, scl);
	return pObj;
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
