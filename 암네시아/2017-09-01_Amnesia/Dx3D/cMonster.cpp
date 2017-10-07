#include "stdafx.h"
#include "cMonster.h"
#include "cSkinnedMesh.h"
#include "cStateMachine.h"
#include "cMonAnimCtrl.h"

cMonster::cMonster()
{
	m_pMachine = new cStateMachine(this);
	m_pos = D3DXVECTOR3(0, 0, 0);
	m_pMonAnim = new cMonAnimCtrl();
}

cMonster::~cMonster()
{
	SAFE_DELETE(m_pMachine);
	SAFE_DELETE(m_pMonAnim);
}

void cMonster::Update()
{
	SAFE_UPDATE(m_pMachine);

	D3DXMATRIX scale, rotY;
	D3DXMatrixScaling(&scale, 1.275f, 1.275f, 1.275f);
	D3DXMatrixRotationY(&rotY, D3DX_PI - m_angle);
	m_matWorld = scale * rotY;
	m_pMonAnim->SetPosition(m_pos);
	m_pMonAnim->SetWorldMatrix(m_matWorld);
}

void cMonster::Render()
{
	SAFE_RENDER(m_pMachine);
	SAFE_RENDER(m_pMonAnim);
}

void cMonster::SetAnim(int tag)
{
	m_pMonAnim->SetAnimation(tag);
}
