#include "stdafx.h"
#include "cMonster.h"
#include "cSkinnedMesh.h"
#include "cStateMachine.h"

cMonster::cMonster()
{
	m_pMesh = new cSkinnedMesh("X_File/entities/enemy/servant_brute/", "run.X");
	m_pMachine = new cStateMachine(this);
	m_pos = D3DXVECTOR3(0, 0, 0);
}

cMonster::~cMonster()
{
	SAFE_DELETE(m_pMachine);
	SAFE_DELETE(m_pMesh);
}

void cMonster::Update()
{
	SAFE_UPDATE(m_pMachine);

	D3DXMATRIX scale, rotY;
	D3DXMatrixScaling(&scale, 1.275f, 1.275f, 1.275f);
	D3DXMatrixRotationY(&rotY, D3DX_PI - m_angle);
	m_matWorld = scale * rotY;
	m_pMesh->SetPosition(m_pos);
}

void cMonster::Render()
{
	SAFE_RENDER(m_pMachine);

	m_pMesh->UpdateAndRender(m_matWorld);
}
