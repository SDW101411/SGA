#include "stdafx.h"
#include "cStateWait.h"
#include "cMonster.h"
#include "cMapLoader.h"

cStateWait::cStateWait(cMonster* pThis)
{
	m_pThis = pThis;
}

cStateWait::~cStateWait()
{

}

void cStateWait::Setup()
{
	m_waitTime = 0.0f;
	m_pThis->SetAnim(MON_ANIM_IDLE);
}

void cStateWait::Release()
{

}

void cStateWait::Update()
{
	m_waitTime += g_pTimeManager->GetDeltaTime();
	if (m_waitTime >= MAX_WAITTIME)
	{
		cMapLoader loader;
		D3DXVECTOR3 pos1 = m_pThis->GetPosition();
		D3DXVECTOR3 pos2 = loader.LoadToMonsterPosition1();
		D3DXVECTOR3 dist = pos1 - pos2;
		if (dist.x * dist.x + dist.z * dist.z < 5.0f) m_pThis->SetState(MON_STATE_MOVE_MONPOS2);
		else m_pThis->SetState(MON_STATE_MOVE_MONPOS1);
	}
}

void cStateWait::Render()
{

}
