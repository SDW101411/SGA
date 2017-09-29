#pragma once

#define ID_LTPOS							("<LEFTTOP>")
#define ID_MESH								("<MESH>")
#define ID_SURFACE							("<SURFACE>")
#define ID_GRIDNODE							("<GRIDNODE>")
#define ID_WALL								("<WALL>")
#define ID_GROUND							("<GROUND>")
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
#define ID_MAPMESH_TAG_TORCH_STATIC_01		("MAPMESH_TAG_TORCH_STATIC_01")

class cObject_Game;
class cObject_Map;
class cMapObject;
class cObject_Light;
class cGridNode;
class cMapSurface;

class cMapLoader
{
private:
	FILE*			m_fp;
	char			m_szToken[1024];
	D3DXVECTOR3		m_leftTop;
public:
	vector<cObject_Map*>					LoadToObject_Map();
	vector<cObject_Light*>					LoadToObject_Light();
	vector<D3DXVECTOR3>						LoadToGroundSurface();
	vector<D3DXVECTOR3>						LoadToWallSurface();
	map<int, map<int, vector<cMapObject*>>> LoadToMapObject();
	map<int, map<int, cGridNode*>>			LoadToGridNode();

	void									PushNearLight(IN vector<cObject_Light*> objLight, IN vector<cObject_Map*>& objMap);

private:
	char*			GetToken();
	bool			IsEqual(char* str1, char* str2);
	float			GetFloat();
	int				GetInt();
	D3DXVECTOR3		LoadVec3();

	cObject_Map*	CreateObject_Map(cMesh_Object_Tag id);
	cMapObject*		CreateMapObject(int id);
	cObject_Light*	CreateObject_Light();
	void			PushMapObject(int id, map<int, map<int, vector<cMapObject*>>>& pObjList);
	void			PushObject_Map(cMesh_Object_Tag id, vector<cObject_Map*>& rtnObjList);
	void			PushLight(vector<cObject_Light*>& lightPos);
	void			PushGridNode(map<int, map<int, cGridNode*>>& nodeList);

	float			GetDistance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
};