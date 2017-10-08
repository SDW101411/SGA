#include "stdafx.h"
#include "cStateRunToPlayer.h"
#include "cMonster.h"

cStateRunToPlayer::cStateRunToPlayer(cMonster* pThis)
{
	m_pThis = pThis;
}

cStateRunToPlayer::~cStateRunToPlayer()
{

}

void cStateRunToPlayer::Setup()
{
	m_isMissedPlayer = false;
	m_pThis->SetAnim(MON_ANIM_RUN);
	m_pThis->SetRoute(g_pASTAR->FindPath(m_pThis->GetPosition(), m_pThis->GetPlayerPos()));
	m_pThis->SetMove(true);
}

void cStateRunToPlayer::Release()
{
	m_pThis->SetMove(false);
}

void cStateRunToPlayer::Update()
{
	if (m_pThis->IsMeetPlayer()) m_isMissedPlayer = false;
	else m_isMissedPlayer = true;

	if (!m_isMissedPlayer)
	{
		list<D3DXVECTOR3> route = g_pASTAR->FindPath(m_pThis->GetPosition(), m_pThis->GetPlayerPos());
		if(route.size() > 0) m_pThis->SetRoute(route);
	}
	m_pThis->MoveRoute(0.03f);
	if (m_pThis->GetRouteSize() <= 0)
	{
		m_pThis->SetState(MON_STATE_MISSEDPLAYER);
		return;
	}

	if (GetDistance(m_pThis->GetPosition(), m_pThis->GetPlayerPos()) < 1)
	{
		m_pThis->SetState(MON_STATE_ATTACK);
		return;
	}
}

void cStateRunToPlayer::Render()
{

}

float cStateRunToPlayer::GetDistance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
{
	D3DXVECTOR3 dist = pos1 - pos2;
	return sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);
}

float cStateRunToPlayer::GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
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

