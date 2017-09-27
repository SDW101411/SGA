#include "stdafx.h"
#include "cMapSurface.h"

cMapSurface::cMapSurface()
{
	D3DXMatrixIdentity(&m_matWorld);
	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f);
}

cMapSurface::~cMapSurface()
{
}

void cMapSurface::SetWall(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos, int floor)
{
	m_surface.push_back(startPos);
	m_surface.push_back(D3DXVECTOR3(startPos.x, startPos.y + floor, startPos.z));
	m_surface.push_back(D3DXVECTOR3(endPos.x, endPos.y + floor, endPos.z));
	m_surface.push_back(startPos);
	m_surface.push_back(D3DXVECTOR3(endPos.x, endPos.y + floor, endPos.z));
	m_surface.push_back(endPos);
}

void cMapSurface::SetGround(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos)
{
	m_surface.push_back(startPos);
	m_surface.push_back(D3DXVECTOR3(endPos.x, startPos.y, startPos.z));
	m_surface.push_back(endPos);
	m_surface.push_back(startPos);
	m_surface.push_back(endPos);
	m_surface.push_back(D3DXVECTOR3(startPos.x, endPos.y, endPos.z));
}

void cMapSurface::RenderSurface()
{
	g_pD3DDevice->SetMaterial(&m_material);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetFVF(D3DFVF_XYZ);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_surface.size() / 3,
		&m_surface[0],
		sizeof(D3DXVECTOR3));
}

vector<D3DXVECTOR3> cMapSurface::GetSurface()
{
	return m_surface;
}

void cMapSurface::PushSurface(vector<D3DXVECTOR3>& vecSurface)
{
	for each(auto p in m_surface)
		vecSurface.push_back(p);
}
