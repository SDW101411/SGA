#include "stdafx.h"
#include "cGridNode.h"

cGridNode::cGridNode()
	: m_pSphere(NULL)
	, m_pBox(NULL)
	, m_pGrid(NULL)
	, m_pParent(NULL)
	, m_pos(0.0f, 0.0f, 0.0f)
	, m_g(0.0f)
	, m_h(0.0f)
	, m_f(0.0f)
	, m_isOpen(false)
	, m_isClose(false)
	, m_isObstacle(false)
{
	D3DXMatrixIdentity(&m_matWorld);
	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(0.0f, 1.0f, 0.0f, 1.0f);
}

cGridNode::~cGridNode()
{
	SAFE_RELEASE(m_pSphere);
	SAFE_RELEASE(m_pBox);
	SAFE_RELEASE(m_pGrid);
}

void cGridNode::SetUp(D3DXVECTOR3 pos)
{
	m_pos = pos;
	D3DXMatrixTranslation(&m_matWorld, pos.x, pos.y, pos.z);
	D3DXCreateSphere(g_pD3DDevice, 0.2f, 10, 10, &m_pSphere, NULL);
	D3DXCreateBox(g_pD3DDevice, 1.0f, 1.0f, 1.0f, &m_pBox, NULL);

	D3DXCreateMeshFVF(2, 4, D3DXMESH_MANAGED, ST_PN_VERTEX::FVF, g_pD3DDevice, &m_pGrid);

	ST_PN_VERTEX* vertex;
	m_pGrid->LockVertexBuffer(0, (VOID**)&vertex);
	vertex[0] = ST_PN_VERTEX(D3DXVECTOR3(-0.5f, 0.0f, -0.5f), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	vertex[1] = ST_PN_VERTEX(D3DXVECTOR3(-0.5f, 0.0f, +0.5f), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	vertex[2] = ST_PN_VERTEX(D3DXVECTOR3(+0.5f, 0.0f, +0.5f), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	vertex[3] = ST_PN_VERTEX(D3DXVECTOR3(+0.5f, 0.0f, -0.5f), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	m_pGrid->UnlockVertexBuffer();

	WORD* index = NULL;

	m_pGrid->LockIndexBuffer(0, (VOID**)&index);
	index[0] = 0;
	index[1] = 1;
	index[2] = 2;

	index[3] = 0;
	index[4] = 2;
	index[5] = 3;
	m_pGrid->UnlockIndexBuffer();

	DWORD* attribute;

	m_pGrid->LockAttributeBuffer(0, &attribute);

	attribute[0] = 0;
	attribute[1] = 0;

	m_pGrid->UnlockAttributeBuffer();
}

void cGridNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetMaterial(&m_material);
	m_pGrid->DrawSubset(0);
	if (m_isObstacle) m_pBox->DrawSubset(0);
}

void cGridNode::SphereRender()
{
	m_pSphere->DrawSubset(0);
}

void cGridNode::CleanUp()
{
	m_pParent = NULL;
	m_pos = D3DXVECTOR3(0.0f, 0.0f, 0.0f);
	m_g = 0.0f;
	m_h = 0.0f;
	m_f = 0.0f;
	m_isOpen = false;
	m_isClose = false;
}
