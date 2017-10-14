#include "stdafx.h"
#include "cStateLookPlayer.h"
#include "cMonster.h"

cStateLookPlayer::cStateLookPlayer(cMonster* pThis)
{
	m_pThis = pThis;
}

cStateLookPlayer::~cStateLookPlayer()
{

}

void cStateLookPlayer::Setup()
{
	SOUNDMANAGER->stop("MonsterLookPlayer");
	SOUNDMANAGER->play("MonsterLookPlayer");
	m_lookTime = 0.0f;
	m_pThis->SetAnim(MON_ANIM_IDLE);
	m_pThis->SetMove(false);
}

void cStateLookPlayer::Release()
{

}

void cStateLookPlayer::Update()
{
	m_lookTime += g_pTimeManager->GetDeltaTime();
	m_pThis->SetAngle(GetAngle(m_pThis->GetPosition(), m_pThis->GetPlayerPos()));
	if (m_pThis->IsMeetPlayer() == false)
	{
		m_pThis->SetState(MON_STATE_WAIT);
		return;
	}
	if (m_lookTime >= 2.0f)
	{
		SOUNDMANAGER->stop("MonsterRunToPlayer");
		SOUNDMANAGER->play("MonsterRunToPlayer");
		m_pThis->SetState(MON_STATE_RUNTOPLAYER);
	}
}

void cStateLookPlayer::Render()
{

}

float cStateLookPlayer::GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
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