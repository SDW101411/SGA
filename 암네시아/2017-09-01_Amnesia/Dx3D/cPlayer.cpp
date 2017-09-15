#include "stdafx.h"
#include "cPlayer.h"
#include "cSkinnedMesh.h"
#include "cPlayer_Ctrl.h"
#include "cAllocateHierarchy.h"




cPlayer::cPlayer()
	:m_pPlayerCtrl(NULL)
{
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_draw.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_idle.X"));
	m_pPlayer_animation_Vec.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_holster.X"));
	m_PTarget_Mesh = m_pPlayer_animation_Vec[0];

	m_pPlayerCtrl = new cPlayer_Ctrl(D3DXVECTOR3(0.f,0.f,0.f));
	m_pPlayer_Animation_Index = cPlayer_Animation_HAND;
}

cPlayer::~cPlayer()
{
	SAFE_DELETE(m_pPlayerCtrl);
	for each(auto p in m_pPlayer_animation_Vec)
		SAFE_DELETE(p);
}

void cPlayer::Update()
{
	SAFE_UPDATE(m_pPlayerCtrl);
	if(m_PTarget_Mesh)Animation_Change();
}

void cPlayer::Render()
{
	if (m_PTarget_Mesh)
	{
		D3DXVECTOR3 Hand_Vector = D3DXVECTOR3(
			m_pPlayerCtrl->Get_m_Camera().x,
			m_pPlayerCtrl->Get_m_Camera().y / 2,
			m_pPlayerCtrl->Get_m_Camera().z);

		D3DXMATRIX Hands_Matrix, matR;
		D3DXMatrixIsIdentity(&Hands_Matrix);

		D3DXMatrixTranslation(&Hands_Matrix, Hand_Vector.x, Hand_Vector.y, Hand_Vector.z);

		Hands_Matrix = m_pPlayerCtrl->Get_m_pTarget_Matrix() * Hands_Matrix;
		if(m_pPlayer_Animation_Index != cPlayer_Animation_HAND) m_PTarget_Mesh->UpdateAndRender(Hands_Matrix);

	}
	
}

void cPlayer::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pPlayerCtrl)
		m_pPlayerCtrl->MsgProc( hWnd, message, wParam, lParam);
}

void cPlayer::Animation_Change()
{
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND)
			Animation_Change_Set(cPlayer_Animation_HAND_UP, &Save_ANI);
		else if(m_pPlayer_Animation_Index == cPlayer_Animation_HAND_UP)
			if (GetTickCount64() >= Save_ANI)
				Animation_Change_Set(cPlayer_Animation_HAND_STAY);
	}
	if (KEYMANAGER->isOnceKeyUp('F'))
		Animation_Change_Set(cPlayer_Animation_HAND_DOWN, &Save_ANI);
	if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND_DOWN)
		if (GetTickCount64() >= Save_ANI)Animation_Change_Set(cPlayer_Animation_HAND);
	

}

void cPlayer::Animation_Change_Set(cPlayer_Animation_Index Set_Type)
{
	m_PTarget_Mesh = m_pPlayer_animation_Vec[Set_Type];
	m_pPlayer_Animation_Index = Set_Type;
	m_PTarget_Mesh->Anireset();
}

void cPlayer::Animation_Change_Set(cPlayer_Animation_Index Set_Type, float * SaveTarget)
{
	m_PTarget_Mesh = m_pPlayer_animation_Vec[Set_Type];
	*SaveTarget = GetTickCount64() + (m_PTarget_Mesh->Get_Return_ANIM_Time() * 1000.f);
	m_pPlayer_Animation_Index = Set_Type;
	m_PTarget_Mesh->Anireset();
}


