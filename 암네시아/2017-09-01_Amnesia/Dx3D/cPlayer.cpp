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

	m_pPlayerCtrl = new cPlayer_Ctrl(D3DXVECTOR3(0.f,0.f,0.f), 1.0f);
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
		D3DXVECTOR3 m_Camera = m_pPlayerCtrl->Get_m_Camera();
		D3DXVECTOR3 Hand_Vector = D3DXVECTOR3(m_Camera.x,m_Camera.y - 0.1f, m_Camera.z);
		cLight_Seting = D3DXVECTOR3(m_Camera.x, m_Camera.y - 0.1f, m_Camera.z);

		D3DXMATRIX Hands_Matrix, matS, matR;
		D3DXMatrixIsIdentity(&Hands_Matrix);
		D3DXMatrixIsIdentity(&matS);
		D3DXMatrixScaling(&matS, 0.1f, 0.1f, 0.1f);


		D3DXMatrixTranslation(&Hands_Matrix, Hand_Vector.x, Hand_Vector.y, Hand_Vector.z);
		//D3DXMatrixTranslation(&Hands_Matrix, 0, 0, 0);

		Hands_Matrix = matS * Hands_Matrix;
		
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
	bool KeyCheck = false;
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND)
		{
			Animation_Change_Set(cPlayer_Animation_HAND_UP, &Save_ANI);
		}
		if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND_UP)
		{
			if (GetTickCount64() >= Save_ANI)
			{
				Animation_Change_Set(cPlayer_Animation_HAND_STAY);
			}
		}
	
				
		if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND_UP || m_pPlayer_Animation_Index == cPlayer_Animation_HAND_STAY)
		{
			KeyCheck = true;
			if (cLight_Color_Seting.x < 0.8f) cLight_Color_Seting.x += 0.04f;
			if (cLight_Color_Seting.y < 0.6f) cLight_Color_Seting.y += 0.04f;
		}
	}
	if (KEYMANAGER->isOnceKeyUp('F'))
	{
		Animation_Change_Set(cPlayer_Animation_HAND_DOWN, &Save_ANI);
	}

	if (m_pPlayer_Animation_Index == cPlayer_Animation_HAND_DOWN)
	{
		if (GetTickCount64() >= Save_ANI)
		{
			Animation_Change_Set(cPlayer_Animation_HAND);
		}
	}
		
	
	if (!KeyCheck)
	{
		if (cLight_Color_Seting.x > 0.0f) cLight_Color_Seting.x -= 0.04f;
		if (cLight_Color_Seting.y > 0.0f) cLight_Color_Seting.y -= 0.04f;
	}
}

void cPlayer::Animation_Change_Set(cPlayer_Animation_Index Set_Type)
{
	/*if (Set_Type == cPlayer_Animation_HAND_DOWN)
	{
		m_PTarget_Mesh = m_pPlayer_animation_Vec[Set_Type];
		m_pPlayer_Animation_Index = Set_Type;
	}
	else
	{*/
		m_PTarget_Mesh = m_pPlayer_animation_Vec[Set_Type];
		m_PTarget_Mesh->Anireset();
		m_pPlayer_Animation_Index = Set_Type;
	//}
	
}

void cPlayer::Animation_Change_Set(cPlayer_Animation_Index Set_Type, float * SaveTarget)
{
	m_PTarget_Mesh = m_pPlayer_animation_Vec[Set_Type];
	*SaveTarget = GetTickCount64() + (m_PTarget_Mesh->Get_Return_ANIM_Time() * 1000.f);
	m_PTarget_Mesh->Anireset();
	m_pPlayer_Animation_Index = Set_Type;
}


