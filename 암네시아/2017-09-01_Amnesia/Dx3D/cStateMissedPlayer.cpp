#include "stdafx.h"
#include "cStateMissedPlayer.h"
#include "cMonster.h"

cStateMissedPlayer::cStateMissedPlayer(cMonster * pThis)
{
	m_pThis = pThis;
}

cStateMissedPlayer::~cStateMissedPlayer()
{

}

void cStateMissedPlayer::Setup()
{
	SOUNDMANAGER->stop("MonsterMissedPlayer");
	SOUNDMANAGER->play("MonsterMissedPlayer");
	m_pThis->SetAnim(MON_ANIM_IDLE_EXTRA);
	m_pThis->SetMove(false);
	m_waitTime = 0.0f;
}

void cStateMissedPlayer::Release()
{

}

void cStateMissedPlayer::Update()
{
	m_waitTime += g_pTimeManager->GetDeltaTime();
	if (m_waitTime >= m_pThis->GetAnimationTime())
	{
		m_pThis->SetState(MON_STATE_WAIT);
		return;
	}
	if (m_pThis->IsPlayerAtNear())
	{
		SOUNDMANAGER->stop("MonsterRunToPlayer");
		SOUNDMANAGER->play("MonsterRunToPlayer");
		m_pThis->SetState(MON_STATE_RUNTOPLAYER);
		return;
	}
}

void cStateMissedPlayer::Render()
{

}