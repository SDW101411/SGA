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
	, m_Speed(0.1f)
	, m_pTarget(NULL)
	, check(0.0f)
	, fx(0.0f)
	, fy(0.0f)
{
	m_pPos = new D3DXVECTOR3(0.f, 0.f, 0.f);
	*m_pPos = m_Camera = Save;
	m_Camera.y += 10.0f;
}

cPlayer_Ctrl::cPlayer_Ctrl(D3DXVECTOR3 Save, float UpY)
	: m_fAngleX(0.0f)
	, m_fAngleY(0.0f)
	, m_isLButtonDown(false)
	, m_Speed(0.05f)
	, m_pTarget(NULL)
	, check(0.0f)
	, fx(0.0f)
	, fy(0.0f)
{
	m_pPos = new D3DXVECTOR3(0.f, 0.f, 0.f);
	*m_pPos = m_Camera = Save;
	m_UpY = UpY;
	m_Camera.y += UpY;
}

cPlayer_Ctrl::~cPlayer_Ctrl()
{
	SAFE_DELETE(m_pPos);
	SAFE_DELETE(m_pTarget);
}

void cPlayer_Ctrl::Update()
{
	cPlayer_cMove_Update();
	cPlayer_cCamera_Update();

	cCameara_seting = m_Camera;
}

void cPlayer_Ctrl::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
		cPlayer_cCamera_MsgProc(hWnd, message, wParam, lParam);
	}
}

void cPlayer_Ctrl::cPlayer_cCamera_Update()
{
	D3DXMATRIX matRX, matRY, matR;
	D3DXMatrixRotationX(&matRX, m_fAngleX);
	D3DXMatrixRotationY(&matRY, m_fAngleY);
	D3DXMatrixIdentity(&matR);
	m_pViewTarget = D3DXVECTOR3(0, 0, -10.0);
	m_pViewTarget_2 = D3DXVECTOR3(-10.0f, 0, 0);
	matR = matRX * matRY;

	D3DXVec3TransformCoord(&m_pViewTarget, &m_pViewTarget, &matR);
	D3DXVec3TransformCoord(&m_pViewTarget_2, &m_pViewTarget_2, &matR);

	m_pViewTarget = m_pViewTarget + m_Camera;
	m_pViewTarget_2 = m_pViewTarget_2 + m_Camera;

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
	D3DXVECTOR3 Direction, Direction_2;
	D3DXVECTOR3 anothor = m_pViewTarget;
	D3DXVECTOR3 anothor_2 = m_pViewTarget_2;
	D3DXVECTOR3 Update_Pos;
	anothor.y = m_pPos->y;
	Direction = anothor - *m_pPos;
	anothor_2.y = m_pPos->y;
	Direction_2 = anothor_2 - *m_pPos;

	D3DXVec3Normalize(&Direction, &Direction);
	D3DXVec3Normalize(&Direction_2, &Direction_2);
	
	static float Speed = 0.01f;
	Update_Pos = *m_pPos;

	bool On = false;
	if (KEYMANAGER->isStayKeyDown('W'))
	{
		//*m_pPos += Direction * m_Speed;
		Update_Pos = *m_pPos + (Direction * m_Speed);
		/*m_Camera = *m_pPos;
		m_Camera.y += m_UpY + check;*/
		//check += Speed;
		On = true;

	}
	if (KEYMANAGER->isStayKeyDown('S'))
	{
		Update_Pos = *m_pPos + (Direction * -m_Speed);
		/**m_pPos += Direction * -m_Speed;
		m_Camera = *m_pPos;
		m_Camera.y += m_UpY + check;*/
		//check += Speed * -1;
		On = true;
	}
	if (KEYMANAGER->isStayKeyDown('D'))
	{
		Update_Pos = *m_pPos + (Direction_2 * m_Speed);
		/**m_pPos += Direction_2 * m_Speed;
		m_Camera = *m_pPos;
		m_Camera.y += m_UpY + check;*/
		//check += Speed;
		On = true;

	}
	if (KEYMANAGER->isStayKeyDown('A'))
	{
		Update_Pos = *m_pPos + (Direction_2 * -m_Speed);
		/**m_pPos += Direction_2 * -m_Speed;
		m_Camera = *m_pPos;
		m_Camera.y += m_UpY + check;*/
		On = true;
		
	}

	if (check >= m_UpY/6)
	{
		Speed *= -1;
	}
	else if (check < 0.f)
	{
		Speed *= -1;
	}

	if (Get_Ray(Update_Pos.x, Update_Pos.y, Update_Pos.z))
	{
		if (On)
			check += Speed * -1;
		*m_pPos = Update_Pos;
		m_Camera = Update_Pos;
		m_Camera.y += m_UpY + check;
	}
	else
	{
		m_Camera = *m_pPos;
		m_Camera.y += m_UpY;
	}
}

void cPlayer_Ctrl::m_surface_Insert(D3DXVECTOR3 Save)
{
	m_Surface.push_back(Save);
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

	D3DXMATRIX matRX, matRY, matR;
	float SAVE = fy - m_fAngleY;
	if (fabs(SAVE) > 0.0001)
	{
		fy -= SAVE * 0.1f ;
	}

	SAVE = fx - m_fAngleX;
	if (fabs(SAVE) > 0.0001)
	{
		fx -= SAVE * 0.1f;
	}

	D3DXMatrixRotationX(&matRX, fx * -1);
	D3DXMatrixRotationY(&matRY, fy + 3.14);
	D3DXMatrixIdentity(&matR);
	matR = matRX * matRY;

	return matR;
}

bool cPlayer_Ctrl::Get_Ray(IN float x, OUT float& y, IN float z)
{
	D3DXVECTOR3 vRayPos(x, 1000.f, z);
	D3DXVECTOR3 vRayDir(0, -1, 0);
	float u, v, d;
	for (size_t i = 0; i < m_Surface.size(); i += 3)
	{
		if (D3DXIntersectTri(&m_Surface[i],
			&m_Surface[i + 1],
			&m_Surface[i + 2],
			&vRayPos,
			&vRayDir,
			&u, &v, &d))
		{
			y = 1000 - d;
			return true;
		}
	}
	return false;
}