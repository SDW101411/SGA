#include "stdafx.h"
#include "cMapToolScene.h"
#include "cMapTool.h"
#include "cMapSaveBtn.h"


cMapToolScene::cMapToolScene()
	: m_pPickingArea(NULL)
	, m_state(0)
	, m_curRotation(0, 0, 0)
	, m_curScale(1.275, 1.275, 1.275)
{
	m_pMapTool = new cMapTool;
	m_pMapTool->SetUp(D3DXVECTOR3(0, 0, 0), 50, 50);
	m_pMapTool->SetCurrentTag(2);

	cMapSaveBtn* pBtn = new cMapSaveBtn;
	pBtn->SetMapToolPointer(m_pMapTool);
	m_pIUI = pBtn;
	m_ground = m_pMapTool->FindPickingGround();


	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(0.8f, 0.8f, 0.8f, 1.0f);
	SetupPickingArea();
}


cMapToolScene::~cMapToolScene()
{
	SAFE_DELETE(m_pMapTool);
	SAFE_DELETE(m_pIUI);

	SAFE_RELEASE(m_pPickingArea);
}

void cMapToolScene::Update()
{
	if (KEYMANAGER->isOnceKeyDown('1')) m_state = MAPTOOL_STATE_CREATE_GRID;
	if (KEYMANAGER->isOnceKeyDown('2')) m_state = MAPTOOL_STATE_DELETE_GRID;
	if (KEYMANAGER->isOnceKeyDown('3')) m_state = MAPTOOL_STATE_CREATE_MESH;
	if (KEYMANAGER->isOnceKeyDown('4')) m_state = MAPTOOL_STATE_DELETE_MESH;
	if (KEYMANAGER->isOnceKeyDown('5')) m_state = MAPTOOL_STATE_SET_WALL;
	if (KEYMANAGER->isOnceKeyDown('6')) m_state = MAPTOOL_STATE_SET_GROUND;
	if (KEYMANAGER->isOnceKeyDown('7')) m_pMapTool->LoadData();

	if (KEYMANAGER->isOnceKeyDown('E'))
	{
		m_curRotation.y += D3DX_PI * 0.5f;
		if (m_curRotation.y >= D3DX_PI * 2) m_curRotation.y -= D3DX_PI * 2;
	}
	if (KEYMANAGER->isOnceKeyDown('Q'))
	{
		m_curRotation.y -= D3DX_PI * 0.5f;
		if (m_curRotation.y < 0) m_curRotation.y += D3DX_PI * 2;
	}

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		m_curScale.x -= 0.05f;
		m_curScale.y -= 0.05f;
		m_curScale.z -= 0.05f;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		m_curScale.x += 0.05f;
		m_curScale.y += 0.05f;
		m_curScale.z += 0.05f;
	}

	if (KEYMANAGER->isOnceKeyDown('C'))
	{
		if (m_pMapTool->FindPickingPosition(m_curPickikngPos, m_ground))
		{
			if(m_state == MAPTOOL_STATE_SET_WALL || m_state == MAPTOOL_STATE_SET_GROUND)
				m_pMapTool->FindNearNode(m_curPickikngPos, m_curPickikngPos);
		}
	}
	if (KEYMANAGER->isOnceKeyDown('V'))
	{
		D3DXVECTOR3 pos;
		if (m_pMapTool->FindPickingPosition(pos, m_ground))
		{
			if (m_state == MAPTOOL_STATE_SET_WALL)
			{
				m_pMapTool->FindNearNode(pos, pos);
				m_pMapTool->CreateWall(m_curPickikngPos, pos);
			}
			if (m_state == MAPTOOL_STATE_SET_GROUND)
			{
				m_pMapTool->FindNearNode(pos, pos);
				m_pMapTool->CreateGround(m_curPickikngPos, pos);
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		m_pMapTool->SetCurrentTag(m_pMapTool->GetCurrentTag() - 1);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		m_pMapTool->SetCurrentTag(m_pMapTool->GetCurrentTag() + 1);
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (m_pMapTool->GetCurrentFloor() < 5) m_pMapTool->SetCurrentFloor(m_pMapTool->GetCurrentFloor() + 1);
		SetupPickingArea();
		for (int i = 0; i < m_ground.size(); i++)
		{
			m_ground[i].y = m_pMapTool->GetCurrentFloor();
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		if (m_pMapTool->GetCurrentFloor() > 0) m_pMapTool->SetCurrentFloor(m_pMapTool->GetCurrentFloor() - 1);
		SetupPickingArea();
		for (int i = 0; i < m_ground.size(); i++)
		{
			m_ground[i].y = m_pMapTool->GetCurrentFloor();
		}
	}

	if (KEYMANAGER->isStayKeyDown(VK_RBUTTON))
	{
		D3DXVECTOR3 pos;
		if (m_pMapTool->FindPickingPosition(pos, m_ground))
		{
			if (m_state == MAPTOOL_STATE_CREATE_GRID) m_pMapTool->CreateNode(pos);
			else if (m_state == MAPTOOL_STATE_DELETE_GRID) m_pMapTool->DeleteNode(pos);
			else if (m_state == MAPTOOL_STATE_CREATE_MESH) m_pMapTool->CreateTile(pos, m_curRotation, m_curScale);
			else if (m_state == MAPTOOL_STATE_DELETE_MESH) m_pMapTool->DeleteTile(pos);
		}
		if (m_state == MAPTOOL_STATE_SET_WALL)
			m_pMapTool->DeleteWall();
		else if (m_state == MAPTOOL_STATE_SET_GROUND)
			m_pMapTool->DeleteGround();
	}
	SAFE_UPDATE(m_pMapTool);
	SAFE_UPDATE(m_pIUI);
}

void cMapToolScene::Render()
{
	RenderPickingArea();
	if (KEYMANAGER->isStayKeyDown(VK_SPACE) && m_state == MAPTOOL_STATE_CREATE_MESH || KEYMANAGER->isStayKeyDown(VK_SPACE) && m_state == MAPTOOL_STATE_DELETE_MESH)
	{
		D3DXVECTOR3 pos;
		if (m_pMapTool->FindPickingPosition(pos, m_ground))
		{
			m_pMapTool->RenderCurrentTag(pos, m_curRotation, m_curScale);
		}
	}
	SAFE_RENDER(m_pMapTool);
	SAFE_RENDER(m_pIUI);
}

void cMapToolScene::SetupPickingArea()
{
	SAFE_RELEASE(m_pPickingArea);

	D3DXCreateMeshFVF(2, 6, D3DXMESH_MANAGED, ST_PN_VERTEX::FVF, g_pD3DDevice, &m_pPickingArea);

	ST_PN_VERTEX* vertex;
	m_pPickingArea->LockVertexBuffer(0, (VOID**)&vertex);
	for (size_t i = 0; i < m_ground.size(); i++)
	{
		vertex[i] = ST_PN_VERTEX(D3DXVECTOR3(m_ground[i].x, m_pMapTool->GetCurrentFloor(), m_ground[i].z), D3DXVECTOR3(0, 1, 0));
	}
	m_pPickingArea->UnlockVertexBuffer();

	WORD* index = NULL;
	m_pPickingArea->LockIndexBuffer(0, (VOID**)&index);
	for (size_t i = 0; i < m_ground.size(); i++)
	{
		index[i] = i;
	}
	m_pPickingArea->UnlockIndexBuffer();

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