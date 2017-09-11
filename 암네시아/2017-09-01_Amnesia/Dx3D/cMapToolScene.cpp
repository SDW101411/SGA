#include "stdafx.h"
#include "cMapToolScene.h"
#include "cMapTool.h"


cMapToolScene::cMapToolScene()
	: m_pPickingArea(NULL)
	, m_state(0)
{
	m_pMapTool = new cMapTool;
	m_pMapTool->SetUp(D3DXVECTOR3(0, 0, 0), 10, 10);
	m_ground = m_pMapTool->FindPickingGround();

	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(1.0f, 1.0f, 0.0f, 1.0f);
	SetupPickingArea();
}


cMapToolScene::~cMapToolScene()
{
	SAFE_DELETE(m_pMapTool);

	SAFE_RELEASE(m_pPickingArea);
}

void cMapToolScene::Update()
{
	if (KEYMANAGER->isOnceKeyDown('1'))m_state = MAPTOOL_STATE_DRAW_GRID;
	if (KEYMANAGER->isOnceKeyDown('2'))m_state = MAPTOOL_STATE_DRAW_CUBE;

	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		D3DXVECTOR3 pos;
		if (m_pMapTool->FindPickingPosition(pos, m_ground))
		{
			if(m_state == MAPTOOL_STATE_DRAW_GRID) m_pMapTool->CreateNode(pos);
			else m_pMapTool->CreateObject(0, pos);
		}
	}
	SAFE_UPDATE(m_pMapTool);
}

void cMapToolScene::Render()
{
	RenderPickingArea();
	SAFE_RENDER(m_pMapTool);
}

void cMapToolScene::SetupPickingArea()
{
	SAFE_RELEASE(m_pPickingArea);

	D3DXCreateMeshFVF(2, 6, D3DXMESH_MANAGED, ST_PN_VERTEX::FVF, g_pD3DDevice, &m_pPickingArea);

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

	//DWORD* attribute;
	//m_pPickingArea->LockAttributeBuffer(0, &attribute);
	//attribute[0] = 0;
	//attribute[1] = 0;
	//m_pPickingArea->UnlockAttributeBuffer();

	D3DXVECTOR3 leftTop = m_pMapTool->GetLeftTopPos();
	D3DXMatrixTranslation(&m_matWorld, leftTop.x, -0.1f, leftTop.z);
}

void cMapToolScene::RenderPickingArea()
{
	if (m_pPickingArea)
	{
		g_pD3DDevice->SetMaterial(&m_material);
		g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
		m_pPickingArea->DrawSubset(0);
	}
}