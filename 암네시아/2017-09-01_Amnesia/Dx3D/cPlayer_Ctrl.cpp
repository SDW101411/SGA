#include "stdafx.h"
#include "cPlayer_Ctrl.h"

cPlayer_Ctrl::cPlayer_Ctrl()
{
	m_pTarget = new D3DXVECTOR3(0.f,0.f,0.f);
}

cPlayer_Ctrl::cPlayer_Ctrl(D3DXVECTOR3 Save)
	: m_fAngleX(0.0f)
	, m_fAngleY(0.0f)
	, m_isLButtonDown(false)
	, m_Speed(0.3f)
	, m_pTarget(NULL)
{
	m_pPos = new D3DXVECTOR3(0.f, 0.f, 0.f);
	*m_pPos = m_Camera = Save;
	m_Camera.y += 10.0f;
}

cPlayer_Ctrl::~cPlayer_Ctrl()
{
	SAFE_DELETE(m_pPos);
	SAFE_DELETE(m_pTarget);
}

void cPlayer_Ctrl::Update()
{
	cPlayer_cCamera_Update();
	cPlayer_cMove_Update();
}

void cPlayer_Ctrl::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	cPlayer_cCamera_MsgProc(hWnd, message, wParam, lParam);
}





void cPlayer_Ctrl::cPlayer_cCamera_Update()
{
	D3DXMATRIX matRX, matRY, matR;
	D3DXMatrixRotationX(&matRX, m_fAngleX);
	D3DXMatrixRotationY(&matRY, m_fAngleY);

	D3DXMatrixIdentity(&matR);

	m_pViewTarget = D3DXVECTOR3(0, 0, -10.0);
	matR = matRX * matRY;
	D3DXVec3TransformCoord(&m_pViewTarget, &m_pViewTarget, &matR);

	m_pViewTarget = m_pViewTarget + m_Camera;

	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView,
		&m_Camera,
		&m_pViewTarget,
		&D3DXVECTOR3(0, 1, 0));

	m_World = matView;

	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);

}

void cPlayer_Ctrl::cPlayer_cCamera_MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	//bool Mouse_Move_Check = falsae;;
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
		m_isLButtonDown = true;
		m_ptPrevMouse.x = LOWORD(lParam);
		m_ptPrevMouse.y = HIWORD(lParam);
	}
	break;
	case WM_LBUTTONUP:
	{
		m_isLButtonDown = false;
	}
	break;
	case WM_MOUSEMOVE:
	{
		if (m_isLButtonDown)
		{
			POINT ptCurrMouse;

			ptCurrMouse.x = LOWORD(lParam);
			ptCurrMouse.y = HIWORD(lParam);
			float fDeltaX = (ptCurrMouse.x - m_ptPrevMouse.x) / 500.f;
			float fDeltaY = (ptCurrMouse.y - m_ptPrevMouse.y) / 250.f;

			m_fAngleY += fDeltaX;
			m_fAngleX -= fDeltaY;

			if (m_fAngleX < -D3DX_PI / 2.0f + 0.0001f)
				m_fAngleX = -D3DX_PI / 2.0f + 0.0001f;

			if (m_fAngleX >  D3DX_PI / 2.0f - 0.0001f)
				m_fAngleX = D3DX_PI / 2.0f - 0.0001f;

			m_ptPrevMouse = ptCurrMouse;
		}
		
	}
		break;
	default:
		break;
	}
}




void cPlayer_Ctrl::cPlayer_cMove_Update()
{
	D3DXVECTOR3 Direction;
	D3DXVECTOR3 anothor = m_pViewTarget;
	anothor.y = m_pPos->y;
	Direction = anothor - *m_pPos;

	D3DXVec3Normalize(&Direction, &Direction);

	if (KEYMANAGER->isStayKeyDown('W'))
	{
		*m_pPos += Direction * m_Speed;
		m_Camera = *m_pPos;
		m_Camera.y += 10.0f;
	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		*m_pPos += Direction * -m_Speed;
		m_Camera = *m_pPos;
		m_Camera.y += 10.0f;
	}
}



D3DXVECTOR3 * cPlayer_Ctrl::Get_m_pTarget()
{
	return m_pPos;
}

D3DXVECTOR3 * cPlayer_Ctrl::Get_m_Pos()
{
	return m_pPos;
}

D3DXVECTOR3 cPlayer_Ctrl::Get_m_Camera()
{
	return m_Camera;
}

D3DXMATRIX cPlayer_Ctrl::Get_m_pTarget_Matrix(D3DXVECTOR3 Insert)
{
	D3DXMATRIX matR;
	D3DXVECTOR3 View = m_pViewTarget;
	D3DXVec3Normalize(&View, &View);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixLookAtLH(&matR,
		&m_Camera,
		&(m_pViewTarget),
		&D3DXVECTOR3(0, 1, 0));

	return matR;
}

D3DXMATRIX cPlayer_Ctrl::Get_m_pTarget_Matrix()
{
	/*D3DXMATRIX matR;
	D3DXVECTOR3 View = m_pViewTarget;
	D3DXVec3Normalize(&View, &View);
	D3DXMatrixIdentity(&matR);
	D3DXMatrixLookAtLH(&matR,
		&m_Camera,
		&(m_pViewTarget),
		&D3DXVECTOR3(0, 1, 0));

	return matR;*/
	D3DXMATRIX matRX, matRY, matR;
	D3DXMatrixRotationX(&matRX, m_fAngleX * -1);
	D3DXMatrixRotationY(&matRY, m_fAngleY + 3.14);
	D3DXMatrixIdentity(&matR);
	matR = matRX * matRY;

	return matR;
}
