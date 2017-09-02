#include "stdafx.h"
#include "cGridNode.h"

cGridNode::cGridNode()
	: m_pSphere(NULL)
	, m_pBox(NULL)
	, m_ib(NULL)
	, m_vb(NULL)
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
}

cGridNode::~cGridNode()
{
	SAFE_RELEASE(m_pSphere);
	SAFE_RELEASE(m_pBox);
}

void cGridNode::SetUp(D3DXVECTOR3 pos)
{
	m_pos = pos;
	D3DXMatrixTranslation(&m_matWorld, pos.x, pos.y, pos.z);
}

void cGridNode::Render()
{
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
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
