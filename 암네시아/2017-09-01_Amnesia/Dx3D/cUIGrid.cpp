#include "stdafx.h"
#include "cUIGrid.h"

cUIGrid::cUIGrid()
	: m_vPosition(0, 0, 0)
{
}

cUIGrid::~cUIGrid()
{
}

void cUIGrid::Setup(int nLine, float fInterVal)
{
	int nHalfLine = nLine / 2;

	float fMax = fabs(nHalfLine * fInterVal);

	D3DCOLOR c = D3DCOLOR_XRGB(255, 255, 255);
	for (int i = 1; i < nHalfLine; ++i)
	{
		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-fMax, i * fInterVal, 0), c));
		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(fMax, i * fInterVal, 0), c));

		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-fMax, -i * fInterVal, 0), c));
		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(fMax, -i * fInterVal, 0), c));

		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(i * fInterVal, -fMax, 0), c));
		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(i * fInterVal, fMax, 0), c));

		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-i * fInterVal, -fMax, 0), c));
		m_vecVertex.push_back(ST_PC_VERTEX(D3DXVECTOR3(-i * fInterVal, fMax, 0), c));
	}

	D3DXMATRIX matS;
	D3DXMatrixScaling(&matS, 0.1f, 20.f, 0.1f);
}

void cUIGrid::Render()
{
	DWORD dwPrev;
	g_pD3DDevice->GetRenderState(D3DRS_LIGHTING, &dwPrev);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);
//	D3DXMATRIX matWorld;
	D3DXMatrixIdentity(&m_matWorld);
//	m_matWorld._41 = m_vPosition.x;
//	m_matWorld._42 = m_vPosition.y;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetFVF(ST_PC_VERTEX::FVF);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_LINELIST,
		m_vecVertex.size() / 2,
		&m_vecVertex[0],
		sizeof(ST_PC_VERTEX));
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, (bool)dwPrev);
}
