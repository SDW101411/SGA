#include "stdafx.h"
#include "cStateMoveToPos2.h"
#include "cMonster.h"
#include "cMapLoader.h"

cStateMoveToPos2::cStateMoveToPos2(cMonster* pThis)
{
	m_pThis = pThis;
}

cStateMoveToPos2::~cStateMoveToPos2()
{
}

void cStateMoveToPos2::Setup()
{
	cMapLoader loader;
	D3DXVECTOR3 pos1 = loader.LoadToMonsterPosition2();
	D3DXVECTOR3 pos2 = m_pThis->GetPosition();
	m_pThis->SetRoute(g_pASTAR->FindPath(pos2, pos1));
	m_pThis->SetMove(true);
	m_pThis->SetAnim(MON_ANIM_WALK);
}

void cStateMoveToPos2::Release()
{
	m_pThis->SetMove(false);
}

void cStateMoveToPos2::Update()
{
	if (m_pThis->GetRouteSize() <= 0)
		m_pThis->SetState(MON_STATE_WAIT);
	m_pThis->MoveRoute(0.006);
}

void cStateMoveToPos2::Render()
{

}
