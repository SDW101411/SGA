#include "stdafx.h"
#include "cMenuCamera.h"

cMenuCamera::cMenuCamera()
{
}

cMenuCamera::~cMenuCamera()
{
}

void cMenuCamera::Update()
{
	m_fDistance = 7.0f;
	m_fAngleX = 0.27f;
	m_fAngleY = 0.54f;
	D3DXMATRIX matRX;
	D3DXMatrixRotationX(&matRX, m_fAngleX);
	D3DXMATRIX matRY;
	D3DXMatrixRotationY(&matRY, m_fAngleY);
	D3DXMATRIX matR = matRX * matRY;

	m_vEye = D3DXVECTOR3(0, 0, -m_fDistance);
	D3DXVec3TransformCoord(&m_vEye, &m_vEye, &matR);

	D3DXVECTOR3 vTarget = D3DXVECTOR3(7.91f, 0.3f, -3.24f);

	m_vEye = m_vEye + vTarget;

	D3DXMATRIX matView;
	D3DXMatrixLookAtLH(&matView,
		&m_vEye,
		&vTarget,
		&D3DXVECTOR3(0, 1, 0));
	g_pD3DDevice->SetTransform(D3DTS_VIEW, &matView);
}