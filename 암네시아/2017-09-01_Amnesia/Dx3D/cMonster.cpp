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
	m_pMesh->SetPosition(D3DXVECTOR3(0, 0, 0));
}

void cMonster::Render()
{
	m_pMesh->UpdateAndRender();
}
