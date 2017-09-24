#include "stdafx.h"
#include "cMapWall.h"

void cMapWall::SetPosition(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos, int floor)
{
	D3DXMatrixIdentity(&m_matWorld);
	ZeroMemory(&m_material, sizeof(D3DMATERIAL9));
	m_material.Ambient = m_material.Diffuse = m_material.Specular = D3DXCOLOR(0.5f, 0.5f, 0.5f, 1.0f);

	m_wallSurface.push_back(startPos);
	m_wallSurface.push_back(D3DXVECTOR3(startPos.x, startPos.y + floor, startPos.z));
	m_wallSurface.push_back(D3DXVECTOR3(endPos.x, endPos.y + floor, endPos.z));
	m_wallSurface.push_back(startPos);
	m_wallSurface.push_back(D3DXVECTOR3(endPos.x, endPos.y + floor, endPos.z));
	m_wallSurface.push_back(endPos);
}

void cMapWall::SetRowCol(int startRow, int startCol, int endRow, int endCol)
{
	m_startRow = startRow;
	m_startCol = startCol;
	m_endRow = endRow;
	m_endCol = endCol;
}

void cMapWall::Render()
{
	g_pD3DDevice->SetMaterial(&m_material);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &m_matWorld);
	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetFVF(D3DFVF_XYZ);
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
		m_wallSurface.size() / 3,
		&m_wallSurface[0],
		sizeof(D3DXVECTOR3));
}

bool cMapWall::IsSame(int startRow, int startCol, int endRow, int endCol)
{
	if (m_startRow == startRow && m_startCol == startCol && m_endRow == endRow && m_endCol == endCol ||
		m_startRow == endRow && m_startCol == endCol && m_endRow == startRow && m_endCol == startCol)
	{
		return true;
	}

	return false;
}

vector<D3DXVECTOR3> cMapWall::GetSurface()
{
	return m_wallSurface;
}
