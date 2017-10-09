#include "stdafx.h"
#include "cStateAttack.h"
#include "cMonster.h"
#include "cDamegeImpact.h"

cStateAttack::cStateAttack(cMonster * pThis)
{
	m_pThis = pThis;
}

cStateAttack::~cStateAttack()
{
}

void cStateAttack::Setup()
{
	m_pImpact = new cDamegeImpact();
	m_attackTime = 0.0f;
	m_isAttack = false;
	m_pThis->SetAnim(MON_ANIM_ATTACK);
	m_pThis->SetMove(false);
}

void cStateAttack::Release()
{

}

void cStateAttack::Update()
{
	m_attackTime += g_pTimeManager->GetDeltaTime();
	if (!m_isAttack && m_attackTime >= 0.5f)
	{
		m_pImpact->BloodImpact();
		DATABASE->SetHp(DATABASE->GetHp() - 30.0f);
		m_isAttack = true;
	}
	if (m_attackTime >= m_pThis->GetAnimationTime())
	{
		m_pThis->SetState(MON_STATE_RUNTOPLAYER);
		return;
	}
	m_pThis->SetAngle(GetAngle(m_pThis->GetPosition(), m_pThis->GetPlayerPos()));
	SAFE_UPDATE(m_pImpact);
}

void cStateAttack::Render()
{
	SAFE_RENDER(m_pImpact);
}

float cStateAttack::GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
{
	float nWidth, nHeight;
	float fHypotenuse;
	float fAngle;
	nWidth = pos2.x - pos1.x;
	nHeight = pos2.z - pos1.z;
	fHypotenuse = sqrtf(nWidth * nWidth + nHeight * nHeight);
	fAngle = acosf(nWidth / fHypotenuse);
	if (pos2.z < pos1.z)
	{
		fAngle = 2 * D3DX_PI - fAngle;
		if (fAngle >= 2 * D3DX_PI) fAngle -= 2 * D3DX_PI;
	}
	return fAngle;
}
