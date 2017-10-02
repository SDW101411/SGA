#include "stdafx.h"
#include "cGridNode.h"

cGridNode::cGridNode()
	: m_pGrid(NULL)
	, m_pParent(NULL)
	, m_isOpen(false)
	, m_isClose(false)
	, m_pos(0.0f, 0.0f, 0.0f)
	, m_g(0.0f)
	, m_h(0.0f)
	, m_f(0.0f)
{
	D3DXMatrixIdentity(&m_matWorld);
	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(0, 0, 1, 1);
}

cGridNode::~cGridNode()
{
	SAFE_RELEASE(m_pGrid);
}

void cGridNode::SetUp(D3DXVECTOR3 pos, int row, int col)
{
	m_pos = pos;
	m_row = row;
	m_col = col;
	D3DXMatrixTranslation(&m_matWorld, pos.x, pos.y, pos.z);
	D3DXCreateMeshFVF(2, 4, D3DXMESH_MANAGED, ST_PN_VERTEX::FVF, g_pD3DDevice, &m_pGrid);

	ST_PN_VERTEX* vertex;
	m_pGrid->LockVertexBuffer(0, (VOID**)&vertex);
	vertex[0] = ST_PN_VERTEX(D3DXVECTOR3(-GRIDNODE_HALFSIZE, 0.0f, -GRIDNODE_HALFSIZE), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	vertex[1] = ST_PN_VERTEX(D3DXVECTOR3(-GRIDNODE_HALFSIZE, 0.0f, +GRIDNODE_HALFSIZE), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	vertex[2] = ST_PN_VERTEX(D3DXVECTOR3(+GRIDNODE_HALFSIZE, 0.0f, +GRIDNODE_HALFSIZE), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
	vertex[3] = ST_PN_VERTEX(D3DXVECTOR3(+GRIDNODE_HALFSIZE, 0.0f, -GRIDNODE_HALFSIZE), D3DXVECTOR3(0.0f, 1.0f, 0.0f));
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
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetMaterial(&m_material);
	g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	m_pGrid->DrawSubset(0);
	g_pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
}

void cGridNode::SetClean()
{
	m_g = 0.0f;
	m_h = 0.0f;
	m_f = 0.0f;
	m_isClose = false;
	m_isOpen = false;
}
