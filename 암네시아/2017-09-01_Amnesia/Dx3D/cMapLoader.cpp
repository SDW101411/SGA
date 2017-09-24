#include "stdafx.h"
#include "cMapLoader.h"
#include "cObject_Game.h"
#include "cMapObject.h"
#include "cMapMesh.h"

vector<cObject_Game*> cMapLoader::LoadToObject_Game()
{
	vector<cObject_Game*> rtnObjList;

	m_fp = fopen("Data/MapData.txt", "r");

	if (IsEqual(GetToken(), ID_MESH))
	{
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CEILING_DEFAULT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_CEILING_DEFAULT));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CEILING_BROKEN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_CEILING_BROKEN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CEILING_NORMAL))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_CEILING_NORMAL));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_WALL_WORN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_WALL_WORN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_PILLAR_DEFAULT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_PILLAR_DEFAULT));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_PILLAR_FULL))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_PILLAR_FULL));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_FLOOR_DEFAULT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_FLOOR_DEFAULT));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CONCAVE_WORN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_CONCAVE_WORN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CORNER_CONCAVE_WORN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_CORNER_CONCAVE_WORN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CORNER_CONVER_SHORT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList.push_back(CreateObject_Game(MAPMESH_TAG_CORNER_CONVER_SHORT));
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

	if (IsEqual(GetToken(), ID_MESH))
	{
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CEILING_DEFAULT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_CEILING_DEFAULT));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CEILING_BROKEN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_CEILING_BROKEN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CEILING_NORMAL))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_CEILING_NORMAL));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_WALL_WORN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_WALL_WORN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_PILLAR_DEFAULT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_PILLAR_DEFAULT));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_PILLAR_FULL))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_PILLAR_FULL));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_FLOOR_DEFAULT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_FLOOR_DEFAULT));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CONCAVE_WORN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_CONCAVE_WORN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CORNER_CONCAVE_WORN))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_CORNER_CONCAVE_WORN));
			}
		}
		if (IsEqual(GetToken(), ID_MAPMESH_TAG_CORNER_CONVER_SHORT))
		{
			while (true)
			{
				if (IsEqual(GetToken(), ID_END)) break;
				rtnObjList[0][0].push_back(CreateMapObject(MAPMESH_TAG_CORNER_CONVER_SHORT));
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

cObject_Game* cMapLoader::CreateObject_Game(int id)
{
	D3DXVECTOR3 pos = LoadPos();
	D3DXVECTOR3 rot = LoadRot();
	D3DXVECTOR3 scl = LoadScl();
	cObject_Game* pObj = new cObject_Game;
	pObj->Set_Anit1hing(pos, rot.x, rot.y, rot.z, scl.x, scl.y, scl.z);
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
