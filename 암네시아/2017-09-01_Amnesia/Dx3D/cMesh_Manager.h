#pragma once

#include "singletonbase.h"

struct Mesh_Manager_Tag;

class cMesh_Manager : public singletonBase <cMesh_Manager>
{
public:
	map<string, Mesh_Manager_Tag*>	cMesh_database;
	map<string, void*>				cShader_database;
public:
	void INSERT(char * szName, Mesh_Manager_Tag* cMesh);
	void INSERT(char * szName, char * Object_Name);
	Mesh_Manager_Tag *FIND(char * szName);
	void INSERT_SHADER(char * szName, void* shader);
	void *FIND_SHADER(char * szName);
	void Destroy();

	cMesh_Manager();
	~cMesh_Manager();
	LPDIRECT3DTEXTURE9 LoadTexture(const char * filename);
	LPD3DXMESH LoadModel(const char * filename);
	LPD3DXEFFECT LoadShader(const char * filename);
};

