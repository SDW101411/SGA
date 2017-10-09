#include "stdafx.h"
#include "cMonAnimCtrl.h"
#include "cSkinnedMesh.h"

cMonAnimCtrl::cMonAnimCtrl()
{
	m_meshList[MON_ANIM_IDLE]		= g_pSkinnedMeshManager->GetSkinnedMesh("Monster/", "idle");
	m_meshList[MON_ANIM_IDLE_EXTRA] = g_pSkinnedMeshManager->GetSkinnedMesh("Monster/", "idle_extra");
	m_meshList[MON_ANIM_WALK]		= g_pSkinnedMeshManager->GetSkinnedMesh("Monster/", "walk");
	m_meshList[MON_ANIM_RUN]		= g_pSkinnedMeshManager->GetSkinnedMesh("Monster/", "run");
	m_meshList[MON_ANIM_ATTACK]		= g_pSkinnedMeshManager->GetSkinnedMesh("Monster/", "attack");

	SetAnimation(MON_ANIM_IDLE);
}

cMonAnimCtrl::~cMonAnimCtrl()
{
}

void cMonAnimCtrl::SetAnimation(MON_ANIM tag)
{
	assert(m_meshList.find(tag)->second && "해당 애니메이션은 없습니다(cMonAnimCtrl)");
	m_pCurMesh = m_meshList[tag];
	m_pCurMesh->AniTrackReset();
	m_pCurMesh->SetPosition(D3DXVECTOR3(0, 0, 0));
}

float cMonAnimCtrl::GetAnimationTime()
{
	return m_pCurMesh->Get_Return_ANIM_Time();
}

void cMonAnimCtrl::Render()
{
	if (m_pCurMesh) m_pCurMesh->UpdateAndRender(m_matWorld);
}
