#include "stdafx.h"
#include "cMapObjState.h"

void cMapObjState::Setup(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl)
{
	m_pos = pos;
	m_rot = rot;
	m_scl = scl;
}

void cMapObjState::Clean()
{
	m_pos = D3DXVECTOR3(0, 0, 0);
	m_rot = D3DXVECTOR3(0, 0, 0);
	m_scl = D3DXVECTOR3(1, 1, 1);
}
