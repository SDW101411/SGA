#include "stdafx.h"
#include "cMapObject.h"
#include "cSkinnedMesh.h"
#include "cMapObjState.h"

cMapObject::cMapObject()
	: m_id(0)
	, m_pMesh(NULL)
{
	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(1.0f, 1.0f, 1.0f, 1.0f);
}

cMapObject::~cMapObject()
{
	SAFE_RELEASE(m_pMesh);
}

void cMapObject::Setup(int id)
{
	m_id = id;

	//switch (id)
	//{
	//case MAP_OBJ_WALL_DEFAULT:
	//	m_pMesh = new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X");
	//	break;
	//}
	D3DXCreateBox(g_pD3DDevice, 1, 1, 1, &m_pMesh, NULL);
}

void cMapObject::Render()
{
	for each(auto p in m_objList)
	{
		g_pD3DDevice->SetMaterial(&m_material);
		D3DXMATRIX mat;
		D3DXMatrixTranslation(&mat, p.GetPosition().x, p.GetPosition().y, p.GetPosition().z);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &mat);
		m_pMesh->DrawSubset(0);
		//m_pMesh->SetPosition(p.GetPosition());
		//m_pMesh->SetRotation(p.GetRotation());
		//m_pMesh->UpdateAndRender();
	}
}

void cMapObject::AddObject(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl)
{
	cMapObjState state;
	state.Setup(pos, rot, scl);
	m_objList.push_back(state);
}
