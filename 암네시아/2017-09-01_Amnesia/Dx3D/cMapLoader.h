#pragma once

#define ID_END								("END")
#define ID_MAPMESH_TAG_CEILING_DEFAULT		("MAPMESH_TAG_CEILING_DEFAULT")
#define ID_MAPMESH_TAG_CEILING_BROKEN		("MAPMESH_TAG_CEILING_BROKEN")
#define ID_MAPMESH_TAG_CEILING_NORMAL		("MAPMESH_TAG_CEILING_NORMAL")
#define ID_MAPMESH_TAG_WALL_WORN			("MAPMESH_TAG_WALL_WORN")
#define ID_MAPMESH_TAG_CORNER_CONVER_SHORT	("MAPMESH_TAG_CORNER_CONVER_SHORT")
#define ID_MAPMESH_TAG_PILLAR_DEFAULT		("MAPMESH_TAG_PILLAR_DEFAULT")
#define ID_MAPMESH_TAG_PILLAR_FULL			("MAPMESH_TAG_PILLAR_FULL")
#define ID_MAPMESH_TAG_FLOOR_DEFAULT		("MAPMESH_TAG_FLOOR_DEFAULT")
#define ID_MAPMESH_TAG_CONCAVE_WORN			("MAPMESH_TAG_CONCAVE_WORN")
#define ID_MAPMESH_TAG_CORNER_CONCAVE_WORN	("MAPMESH_TAG_CORNER_CONCAVE_WORN")
#define ID_MESH								("<MESH>")

class cObject_Game;
class cMapObject;

class cMapLoader
{
private:
	FILE* m_fp;
	char m_szToken[1024];
public:
	vector<cObject_Game*> LoadToObject_Game();
	map<int, map<int, vector<cMapObject*>>> LoadToMapObject();

private:
	char*		GetToken();
	bool		IsEqual(char* str1, char* str2);
	float		GetFloat();
	D3DXVECTOR3 LoadPos();
	D3DXVECTOR3 LoadRot();
	D3DXVECTOR3 LoadScl();

	cObject_Game*	CreateObject_Game(int id);
	cMapObject*		CreateMapObject(int id);
};