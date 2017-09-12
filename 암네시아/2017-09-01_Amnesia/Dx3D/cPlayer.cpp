#include "stdafx.h"
#include "cPlayer.h"
#include "cSkinnedMesh.h"
#include "cPlayer_Ctrl.h"


cPlayer::cPlayer()
	:m_pPlayerCtrl(NULL)
{
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X"));
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_draw.X"));
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_holster.X"));
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_idle.X"));

	m_PTarget_Mesh = m_pPlayer_animation[0];

	m_pPlayerCtrl = new cPlayer_Ctrl(D3DXVECTOR3(0.f,0.f,0.f));

}

cPlayer::~cPlayer()
{
	SAFE_DELETE(m_pPlayerCtrl);
	for each(auto p in m_pPlayer_animation)
		SAFE_DELETE(p);
}

void cPlayer::Update()
{
	SAFE_UPDATE(m_pPlayerCtrl);
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



		m_PTarget_Mesh->UpdateAndRender(Hands_Matrix);
	}
	
}

void cPlayer::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pPlayerCtrl)
		m_pPlayerCtrl->MsgProc( hWnd, message, wParam, lParam);
}