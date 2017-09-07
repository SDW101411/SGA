#include "stdafx.h"
#include "cMapToolTestScene.h"
#include "cMapTool.h"


cMapToolTestScene::cMapToolTestScene()
	: m_pPickingArea(NULL)
{
	m_pMapTool = new cMapTool;
	m_pMapTool->SetUp(D3DXVECTOR3(0, 0, 0), 10, 10);
	m_ground = m_pMapTool->FindPickingGround();

	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	SetupPickingArea();
}


cMapToolTestScene::~cMapToolTestScene()
{
	SAFE_DELETE(m_pMapTool);

	SAFE_RELEASE(m_pPickingArea);
}

void cMapToolTestScene::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		D3DXVECTOR3 pos;
		if (m_pMapTool->FindPickingPosition(pos, m_ground))
		{
			m_pMapTool->CreateNode(pos);
		}
	}
	SAFE_UPDATE(m_pMapTool);
}

void cMapToolTestScene::Render()
{
	SAFE_RENDER(m_pMapTool);
	RenderPickingArea();
}

void cMapToolTestScene::SetupPickingArea()
{
	SAFE_RELEASE(m_pPickingArea);

	D3DXCreateMeshFVF(2, 4, D3DXMESH_MANAGED, ST_PN_VERTEX::FVF, g_pD3DDevice, &m_pPickingArea);

	ST_PN_VERTEX* vertex;
	m_pPickingArea->LockVertexBuffer(0, (VOID**)&vertex);
	for (size_t i = 0; i < m_ground.size(); i++)
	{
		vertex[i] = ST_PN_VERTEX(m_ground[i], D3DXVECTOR3(0, 1, 0));
	}
	m_pPickingArea->UnlockVertexBuffer();

	WORD* index = NULL;
	m_pPickingArea->LockIndexBuffer(0, (VOID**)&index);
	for (size_t i = 0; i < m_ground.size(); i++)
	{
		index[i] = i;
	}
	m_pPickingArea->UnlockIndexBuffer();

	DWORD* attribute;
	m_pPickingArea->LockAttributeBuffer(0, &attribute);
	attribute[0] = 0;
	attribute[1] = 0;
	m_pPickingArea->UnlockAttributeBuffer();

	D3DXVECTOR3 leftTop = m_pMapTool->GetLeftTopPos();
	D3DXMatrixTranslation(&m_matWorld, leftTop.x, 0, leftTop.z);
}

void cMapToolTestScene::RenderPickingArea()
{
	if (m_pPickingArea)
	{
		g_pD3DDevice->SetMaterial(&m_material);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
		m_pPickingArea->DrawSubset(0);
	}
}