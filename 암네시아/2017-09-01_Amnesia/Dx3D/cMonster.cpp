#include "stdafx.h"
#include "cMonster.h"
#include "cSkinnedMesh.h"

cMonster::cMonster()
{
	m_pMesh = new cSkinnedMesh("X_File/entities/enemy/servant_brute/", "servant_brute.X");
}

cMonster::~cMonster()
{
}

void cMonster::Update()
{
	D3DXMATRIX scale, rotY;
	D3DXMatrixScaling(&scale, 1.275f, 1.275f, 1.275f);
	D3DXMatrixRotationY(&rotY, D3DX_PI - m_angle);
	m_matWorld = scale * rotY;
	m_pMesh->SetPosition(m_pos);
}

void cMonster::Render()
{
	m_pMesh->UpdateAndRender(m_matWorld);
}
