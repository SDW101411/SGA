#include "stdafx.h"
#include "cParticle_Fire.h"


cParticle_Fire::cParticle_Fire()
{
	Seting_Fire_Ver();
	Seting_Smoke_Ver();
}

cParticle_Fire::cParticle_Fire(D3DXVECTOR3 *Target)
{
	Seting_Fire_Ver();
	Seting_Smoke_Ver();
	pos_xyz = Target;
}

void cParticle_Fire::Seting_Fire_Ver()
{
	m_Particle_Vec.resize(300);
	for (int i = 0; i < m_Particle_Vec.size(); ++i)
	{
		//Particle_Data Save = new Particle_Data;
		//m_Particle_Vec[i] = Save;

		float fRadius = rand() % 100 * 0.001f;

		m_Particle_Vec[i].p = D3DXVECTOR3(0, 0, fRadius);


		D3DXVECTOR3 vAngle = D3DXVECTOR3(
			D3DXToRadian(rand() % 3600 / 10.0f),
			D3DXToRadian(rand() % 3600 / 10.0f),
			D3DXToRadian(rand() % 3600 / 10.0f));

		D3DXMATRIX matRX, matRY, matRZ, matWorld, Sca;
		D3DXMatrixRotationX(&matRX, vAngle.x);
		D3DXMatrixRotationY(&matRY, vAngle.y);
		D3DXMatrixRotationZ(&matRZ, vAngle.z);
		D3DXMatrixScaling(&Sca, 1,1,1);
		matWorld = matRX * matRY * matRZ ;

		D3DXVec3TransformCoord(
			&m_Particle_Vec[i].p,
			&m_Particle_Vec[i].p,
			&matWorld);

		m_Particle_Vec[i].c = D3DCOLOR_ARGB(255, 255, 180, 0);
	}

	// 포인트를 확대 축소 할 수 있게 해줌
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALEENABLE, true);

	// 포인트 사이즈 설정
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE, FtoDw(0.5f));

	// 포인트 스케일링 Factor값 설정
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_A, FtoDw(1.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_B, FtoDw(1.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_C, FtoDw(1.0f));

	// 포인트 최소 크기
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MIN, FtoDw(1.0f));

	// 포인트 최대 크기
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MAX, FtoDw(30));

	// 포인트에 텍스쳐를 입힐 수 있게 해줌
	g_pD3DDevice->SetRenderState(D3DRS_POINTSPRITEENABLE, true);

	// 텍스쳐 알파 옵션 설정
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
}

void cParticle_Fire::Seting_Smoke_Ver()
{
	m_Particle_Smoke_Vec.resize(300);
	for (int i = 0; i < m_Particle_Smoke_Vec.size(); ++i)
	{
		//Particle_Data Save = new Particle_Data;
		//m_Particle_Vec[i] = Save;

		float fRadius = rand() % 100 * 0.0003f;

		m_Particle_Smoke_Vec[i].p = D3DXVECTOR3(0, 0, fRadius);


		D3DXVECTOR3 vAngle = D3DXVECTOR3(
			D3DXToRadian(rand() % 3600 / 10.0f),
			D3DXToRadian(rand() % 3600 / 10.0f),
			D3DXToRadian(rand() % 3600 / 10.0f));

		D3DXMATRIX matRX, matRY, matRZ, matWorld, Sca;
		D3DXMatrixRotationX(&matRX, vAngle.x);
		D3DXMatrixRotationY(&matRY, vAngle.y);
		D3DXMatrixRotationZ(&matRZ, vAngle.z);
		D3DXMatrixScaling(&Sca, 1, 1, 1);
		matWorld = matRX * matRY * matRZ;

		D3DXVec3TransformCoord(
			&m_Particle_Smoke_Vec[i].p,
			&m_Particle_Smoke_Vec[i].p,
			&matWorld);

		m_Particle_Smoke_Vec[i].c = D3DCOLOR_ARGB(255, 80, 80, 80);
	}

	// 포인트를 확대 축소 할 수 있게 해줌
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALEENABLE, true);

	// 포인트 사이즈 설정
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE, FtoDw(0.5f));

	// 포인트 스케일링 Factor값 설정
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_A, FtoDw(1.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_B, FtoDw(1.0f));
	g_pD3DDevice->SetRenderState(D3DRS_POINTSCALE_C, FtoDw(1.0f));

	// 포인트 최소 크기
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MIN, FtoDw(1.0f));

	// 포인트 최대 크기
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE_MAX, FtoDw(30));

	// 포인트에 텍스쳐를 입힐 수 있게 해줌
	g_pD3DDevice->SetRenderState(D3DRS_POINTSPRITEENABLE, true);

	// 텍스쳐 알파 옵션 설정
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAOP, D3DTOP_MODULATE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG1, D3DTA_TEXTURE);
	g_pD3DDevice->SetTextureStageState(0, D3DTSS_ALPHAARG2, D3DTA_DIFFUSE);

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);

	
}


cParticle_Fire::~cParticle_Fire()
{
}

void cParticle_Fire::Update()
{
	for (int i = 0; i < m_Particle_Vec.size(); ++i)
	{
		m_Particle_Vec[i].m_Alpha += -1;

		if (m_Particle_Vec[i].m_Alpha < 0)
		{
			m_Particle_Vec[i].m_Alpha = (rand() % 155) + 100 ;

			float fRadius = rand() % 100 * 0.001f;

			m_Particle_Vec[i].p = D3DXVECTOR3(0, 0, fRadius);


			D3DXVECTOR3 vAngle = D3DXVECTOR3(
				D3DXToRadian(rand() % 3600 * 0.1f),
				D3DXToRadian(rand() % 3600 * 0.1f),
				D3DXToRadian(rand() % 3600 * 0.1f));

			D3DXMATRIX matRX, matRY, matRZ, matWorld;
			D3DXMatrixRotationX(&matRX, vAngle.x);
			D3DXMatrixRotationY(&matRY, vAngle.y);
			D3DXMatrixRotationZ(&matRZ, vAngle.z);
			matWorld = matRX * matRY * matRZ;

			D3DXVec3TransformCoord(
				&m_Particle_Vec[i].p,
				&m_Particle_Vec[i].p,
				&matWorld);

		}
		m_Particle_Vec[i].p.y += 0.001f;

		m_Particle_Vec[i].c = D3DCOLOR_ARGB((int)m_Particle_Vec[i].m_Alpha, 255, 180, 0);
	}

	for (int i = 0; i < m_Particle_Smoke_Vec.size(); ++i)
	{
		m_Particle_Smoke_Vec[i].m_Alpha += -0.8;

		if (m_Particle_Smoke_Vec[i].m_Alpha < 0)
		{
			m_Particle_Smoke_Vec[i].m_Alpha = (rand() % 155) + 100;

			float fRadius = rand() % 100 * 0.0003f;

			m_Particle_Smoke_Vec[i].p = D3DXVECTOR3(0, 0, fRadius);


			D3DXVECTOR3 vAngle = D3DXVECTOR3(
				D3DXToRadian(rand() % 3600 * 0.1f),
				D3DXToRadian(rand() % 3600 * 0.1f),
				D3DXToRadian(rand() % 3600 * 0.1f));

			D3DXMATRIX matRX, matRY, matRZ, matWorld;
			D3DXMatrixRotationX(&matRX, vAngle.x);
			D3DXMatrixRotationY(&matRY, vAngle.y);
			D3DXMatrixRotationZ(&matRZ, vAngle.z);
			matWorld = matRX * matRY * matRZ;

			D3DXVec3TransformCoord(
				&m_Particle_Smoke_Vec[i].p,
				&m_Particle_Smoke_Vec[i].p,
				&matWorld);

		}
		m_Particle_Smoke_Vec[i].p.y += 0.001f;

		m_Particle_Smoke_Vec[i].c = D3DCOLOR_ARGB((int)m_Particle_Vec[i].m_Alpha, 200, 200, 200);
	}
}

void cParticle_Fire::Render()
{
	g_pD3DDevice->SetRenderState(D3DRS_LIGHTING, false);

	g_pD3DDevice->SetRenderState(D3DRS_BLENDOP, D3DBLENDOP_ADD);


	g_pD3DDevice->SetRenderState(D3DRS_SRCBLEND, D3DBLEND_SRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, true);


	D3DXMATRIXA16 matWorld;
	D3DXMatrixIdentity(&matWorld);
	D3DXMatrixTranslation(&matWorld, pos_xyz->x, pos_xyz->y, pos_xyz->z);
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &matWorld);

	g_pD3DDevice->SetTexture(0, NULL);
	g_pD3DDevice->SetFVF(Particle_Data::FVF);

	g_pD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, false);

	g_pD3DDevice->SetTexture(0, g_pTextureManager->GetTexture("Test/ps_torch_fire_smoke.tga"));
	
	//for (int i = 0; m_Particle_Vec.size(); ++i)
	//{
	//	//g_pD3DDevice->DrawIndexedPrimitive(D3DPT_POINTLIST,1,&m_Particle_Vec[i],);
	//	g_pD3DDevice->DrawPrimitiveUP(D3DPT_POINTLIST,
	//		1,
	//		&m_Particle_Vec[i],
	//		sizeof(Particle_Data));
	//}

	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_INVSRCALPHA);
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE, FtoDw(2.0f));

	
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_POINTLIST,
		m_Particle_Smoke_Vec.size(),
		&m_Particle_Smoke_Vec[0],
		sizeof(Particle_Data));

	g_pD3DDevice->SetRenderState(D3DRS_DESTBLEND, D3DBLEND_ONE);
	g_pD3DDevice->SetRenderState(D3DRS_POINTSIZE, FtoDw(0.5f));
	g_pD3DDevice->DrawPrimitiveUP(D3DPT_POINTLIST,
		m_Particle_Vec.size(),
		&m_Particle_Vec[0],
		sizeof(Particle_Data));


	

	g_pD3DDevice->SetRenderState(D3DRS_ZWRITEENABLE, true);
	g_pD3DDevice->SetRenderState(D3DRS_ALPHABLENDENABLE, false);
}


