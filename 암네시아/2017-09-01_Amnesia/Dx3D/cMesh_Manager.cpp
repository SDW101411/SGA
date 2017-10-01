#include "stdafx.h"
#include "cMesh_Manager.h"


void cMesh_Manager::INSERT(char * szName, Mesh_Manager_Tag * cMesh)
{
	cMesh_database[szName] = cMesh;
}
void cMesh_Manager::INSERT(char * szName, char * Object_Name)
{
	Mesh_Manager_Tag* Save_Mesh;
	Save_Mesh = new Mesh_Manager_Tag;

	std::string sMesh(Object_Name); sMesh += std::string(".x");
	std::string sTex(Object_Name); sTex += std::string(".dds");
	std::string sNormal(Object_Name); sNormal += std::string("_nrm.dds");
	std::string sSpec(Object_Name); sSpec += std::string("_spec.dds");

	Save_Mesh->m_Mesh = LoadModel(sMesh.c_str());
	Save_Mesh->m_Texture = LoadTexture(sTex.c_str());
	Save_Mesh->m_Normal = LoadTexture(sNormal.c_str());
	Save_Mesh->m_Specqural = LoadTexture(sSpec.c_str());

	cMesh_database[szName] = Save_Mesh;
}

Mesh_Manager_Tag * cMesh_Manager::FIND(char * szName)
{
	return cMesh_database.find(szName)->second;
}

void cMesh_Manager::INSERT_SHADER(char * szName, void * shader)
{
	cShader_database[szName] = shader;
}

void * cMesh_Manager::FIND_SHADER(char * szName)
{
	return cShader_database.find(szName)->second;
}

void cMesh_Manager::Destroy()
{
	for each(auto p in cMesh_database)
	{
		SAFE_RELEASE(p.second->m_Mesh);
		SAFE_RELEASE(p.second->m_Normal);
		SAFE_RELEASE(p.second->m_Specqural);
		SAFE_RELEASE(p.second->m_Texture);
		SAFE_DELETE(p.second);
	}

	for each(auto p in cShader_database)
	{
		SAFE_DELETE(p.second);
	}
}

cMesh_Manager::cMesh_Manager()
{
}


cMesh_Manager::~cMesh_Manager()
{
}


LPDIRECT3DTEXTURE9 cMesh_Manager::LoadTexture(const char * filename)
{
	LPDIRECT3DTEXTURE9 ret = NULL;
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, filename, &ret)))
	{
		OutputDebugString("텍스쳐 파일없다 이자식아 : ");
		OutputDebugString(filename);
		OutputDebugString("\n");
	}

	return ret;
}

LPD3DXMESH cMesh_Manager::LoadModel(const char * filename)
{
	LPD3DXMESH ret = NULL;
	if (FAILED(D3DXLoadMeshFromX(filename, D3DXMESH_SYSTEMMEM, g_pD3DDevice,
		NULL, NULL, NULL, NULL, &ret)))
	{
		OutputDebugString("메쉬 파일 없다 이자식아: ");
		OutputDebugString(filename);
		OutputDebugString("\n");
	};

	return ret;
}

LPD3DXEFFECT cMesh_Manager::LoadShader(const char * filename)
{
	LPD3DXEFFECT ret = NULL;
	LPD3DXBUFFER pError = NULL;
	DWORD dwShaderFlags = 0;

#if _DEBUG
	dwShaderFlags |= D3DXSHADER_DEBUG;
#endif

	D3DXCreateEffectFromFile(g_pD3DDevice, filename,
		NULL, NULL, dwShaderFlags, NULL, &ret, &pError);

	// 쉐이더 로딩에 실패한 경우 output창에 쉐이더
	// 컴파일 에러를 출력한다.
	if (!ret && pError)
	{
		int size = pError->GetBufferSize();
		void *ack = pError->GetBufferPointer();

		if (ack)
		{
			char* str = new char[size];
			sprintf(str, (const char*)ack, size);
			OutputDebugString(str);
			delete[] str;
		}
	}

	return ret;
}
