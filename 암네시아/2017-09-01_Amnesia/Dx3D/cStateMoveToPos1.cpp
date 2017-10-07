#include "stdafx.h"
#include "cStateMoveToPos1.h"
#include "cMonster.h"
#include "cMapLoader.h"

cStateMoveToPos1::cStateMoveToPos1(cMonster* pThis)
{
	m_pThis = pThis;
}

cStateMoveToPos1::~cStateMoveToPos1()
{

}

void cStateMoveToPos1::Setup()
{
	cMapLoader loader;
	m_pThis->SetRoute(g_pASTAR->FindPath(m_pThis->GetPosition(), loader.LoadToMonsterPosition1()));
	m_pThis->SetMove(true);
	m_pThis->SetAnim(MON_ANIM_WALK);
}

void cStateMoveToPos1::Release()
{
	m_pThis->SetMove(false);
}

void cStateMoveToPos1::Update()
{
	if (m_pThis->GetRouteSize() <= 0)
		m_pThis->SetState(MON_STATE_WAIT);
	m_pThis->MoveRoute(0.006);
}

void cStateMoveToPos1::Render()
{

}
