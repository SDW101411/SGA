#include "stdafx.h"
#include "cMapMesh.h"
#include "cSkinnedMesh.h"

cMapMesh::cMapMesh()
	: m_pMesh(NULL)
{
}

cMapMesh::~cMapMesh()
{
	SAFE_RELEASE(m_pMesh);
	SAFE_RELEASE(m_pTexture);
}

void cMapMesh::Setup(int tag)
{
	string meshName;
	string textureName;
	switch (tag)
	{
	case MAPMESH_TAG_CEILING_DEFAULT:
		meshName = "X_File/static_objects/castlebase/ceiling/arched.X";
		textureName = "X_File/static_objects/castlebase/ceiling/ceiling02_arched.dds";
		break;
	case MAPMESH_TAG_CEILING_BROKEN:
		meshName = "X_File/static_objects/castlebase/ceiling/arched_broken.X";
		textureName = "X_File/static_objects/castlebase/ceiling/ceiling02_arched.dds";
		break;
	case MAPMESH_TAG_CEILING_NORMAL:
		meshName = "X_File/static_objects/castlebase/floor/deafult2.X";
		textureName = "X_File/static_objects/castlebase/ceiling/ceiling_rough.dds";
		break;
	case MAPMESH_TAG_WALL_WORN:
		meshName = "X_File/static_objects/castlebase/wall/default_worn.X";
		textureName = "X_File/static_objects/castlebase/wall/castlebase_wall_worn.dds";
		break;
	case MAPMESH_TAG_PILLAR_DEFAULT:
		meshName = "X_File/static_objects/castlebase/wall/welder.X";
		textureName = "X_File/static_objects/castlebase/wall/castlebase_wall.dds";
		break;
	case MAPMESH_TAG_PILLAR_FULL:
		meshName = "X_File/static_objects/castlebase/wall/welder_convex.X";
		textureName = "X_File/static_objects/castlebase/wall/castlebase_wall_welder_convex.dds";
		break;
	case MAPMESH_TAG_FLOOR_DEFAULT:
		meshName = "X_File/static_objects/castlebase/floor/deafult.X";
		textureName = "X_File/static_objects/castlebase/floor/castlebase_tiledfloor02.dds";
		break;
	case MAPMESH_TAG_CONCAVE_WORN:
		meshName = "X_File/static_objects/castlebase/ceiling/concave_worn.X";
		textureName = "X_File/static_objects/castlebase/wall/castlebase_wall_worn.dds";
		break;
	case MAPMESH_TAG_CORNER_CONCAVE_WORN:
		meshName = "X_File/static_objects/castlebase/ceiling/corner_concave_worn.X";
		textureName = "X_File/static_objects/castlebase/wall/castlebase_wall_worn.dds";
		break;
	case MAPMESH_TAG_CORNER_CONVER_SHORT:
		meshName = "X_File/static_objects/castlebase/ceiling/corner_convex_short.X";
		textureName = "X_File/static_objects/castlebase/wall/castlebase_wall_worn.dds";
		break;
	}
	m_pMesh = LoadMesh(meshName);
	m_pTexture = LoadTexture(textureName);
}

void cMapMesh::Render(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl)
{
	D3DXMATRIX matPos, matRotX, matRotY, matRotZ, matScl;
	D3DXMatrixTranslation(&matPos, pos.x, pos.y, pos.z);
	D3DXMatrixRotationX(&matRotX, rot.x);
	D3DXMatrixRotationY(&matRotY, rot.y);
	D3DXMatrixRotationZ(&matRotZ, rot.z);
	D3DXMatrixScaling(&matScl, scl.x, scl.y, scl.z);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &(matScl * matRotX * matRotY * matRotZ * matPos));
	g_pD3DDevice->SetTexture(0, m_pTexture);
	m_pMesh->DrawSubset(0);
}

LPD3DXMESH cMapMesh::LoadMesh(string filename)
{
	LPD3DXMESH ret = NULL;
	if (FAILED(D3DXLoadMeshFromX(filename.c_str(), D3DXMESH_SYSTEMMEM, g_pD3DDevice,
		NULL, NULL, NULL, NULL, &ret)))
	{
		OutputDebugString("모델 로딩 실패: ");
		OutputDebugString(filename.c_str());
		OutputDebugString("\n");
	};

	return ret;
}

LPDIRECT3DTEXTURE9 cMapMesh::LoadTexture(string fileName)
{
	LPDIRECT3DTEXTURE9 ret = NULL;
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, fileName.c_str(), &ret)))
	{
		OutputDebugString("텍스쳐 파일없다 이자식아 : ");
		OutputDebugString(fileName.c_str());
		OutputDebugString("\n");
	}

	return ret;
}
