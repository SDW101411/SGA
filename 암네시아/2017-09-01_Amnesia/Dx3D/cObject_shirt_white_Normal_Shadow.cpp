#include "stdafx.h"
#include "cObject_shirt_white_Normal_Shadow.h"


cObject_shirt_white_Normal_Shadow::cObject_shirt_white_Normal_Shadow()
{
	m_Mesh = LoadModel("Test/shirt_hanging_white.x");
	m_Texture = LoadTexture("Test/shirt_white.dds");
	m_Normal = LoadTexture("Test/shirt_white_nrm.dds");
	m_Specqural = LoadTexture("Test/shirt_white_spec.dds");
	m_Efffect = LoadShader("Test/NormalMappingAndShadow.fx");


	const int shadowMapSize = 2048;
	//if (FAILED()return;
	g_pD3DDevice->CreateTexture(
		shadowMapSize, 
		shadowMapSize, 
		1, 
		D3DUSAGE_RENDERTARGET, 
		D3DFMT_R32F, 
		D3DPOOL_DEFAULT, 
		&gpShadowRenderTarget, 
		NULL);

	g_pD3DDevice->CreateDepthStencilSurface(
		shadowMapSize,
		shadowMapSize,
		D3DFMT_D24X8,
		D3DMULTISAMPLE_NONE,
		0,
		TRUE,
		&m_pShadowDepthStencil,
		NULL);
}


cObject_shirt_white_Normal_Shadow::~cObject_shirt_white_Normal_Shadow()
{
	SAFE_RELEASE(m_Mesh);
	SAFE_RELEASE(m_Texture);
	SAFE_RELEASE(m_Normal);
	SAFE_RELEASE(m_Specqural);
	SAFE_RELEASE(m_Efffect);
}

void cObject_shirt_white_Normal_Shadow::Update()
{
	//m_AngleY += 0.01f;
}

void cObject_shirt_white_Normal_Shadow::Render()
{
	

	

	LPDIRECT3DSURFACE9 pHWBackBuffer = NULL;
	LPDIRECT3DSURFACE9 pHWDepthStencilBuffer = NULL;
	//pHWBackBuffer = NULL;
	//pHWDepthStencilBuffer = NULL;
	g_pD3DDevice->GetRenderTarget(0, &pHWBackBuffer);
	g_pD3DDevice->GetDepthStencilSurface(&pHWDepthStencilBuffer);

	// 그림자 맵의 렌더타깃과 깊이버퍼를 사용한다.
	LPDIRECT3DSURFACE9 pShadowSurface = NULL;
	//pShadowSurface = NULL;
	gpShadowRenderTarget->GetSurfaceLevel(0, &pShadowSurface);

	g_pD3DDevice->SetRenderTarget(0, pShadowSurface);
	SAFE_RELEASE(pShadowSurface);

	g_pD3DDevice->SetDepthStencilSurface(m_pShadowDepthStencil);

	// 저번 프레임에 그렸던 그림자 정보를 지움
	g_pD3DDevice->Clear(0,
		NULL,
		(D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER),
		0xFFFFFFFF,
		1.0f,
		0);

	/*FLOAT Length = D3DXVec3Length(&(m_Pos - cCameafra_seting));
	m_Efffect->SetFloat("gLightLength", Length);*/
	D3DXMATRIXA16 matView, matProjection, matLightView;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &WorldReturn());
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
	D3DXVECTOR3 vEyePt(10,10,10);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXVECTOR3 Target;
	D3DXVec3Normalize(&Target, &m_Pos);

	D3DXMatrixLookAtLH(&matLightView, &cLight_Seting, &Target, &vUpVec);
	D3DXMATRIXA16 matLightProjection;
	D3DXMatrixPerspectiveFovLH(&matLightProjection, D3DX_PI / 2.0f , 1, 1, 10);
	

	m_Efffect->SetMatrix("gWorldMatrix", &WorldReturn());
	m_Efffect->SetMatrix("gLightViewMatrix", &matLightView);
	m_Efffect->SetMatrix("gProjectionMatrix", &matProjection);
	m_Efffect->SetMatrix("gLightProjection", &matLightProjection);
	m_Efffect->SetMatrix("gWorldViewProjectionMatrix", &(WorldReturn()*matView * matProjection));

	m_Efffect->SetVector("gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Efffect->SetVector("gWorldCameraPosition", &D3DXVECTOR4(cCameara_seting.x, cCameara_seting.y, cCameara_seting.z, 1.0f));
	m_Efffect->SetVector("gLightColor_1", &D3DXVECTOR4(cLight_Color_Seting_2.x, cLight_Color_Seting_2.y, cLight_Color_Seting_2.z, 1));
	m_Efffect->SetVector("gLightColor_2", &D3DXVECTOR4(cLight_Color_Seting.x, cLight_Color_Seting.y, cLight_Color_Seting.z, 1));

	
	m_Efffect->SetTexture("ShadowMap_Tex", gpShadowRenderTarget);
	m_Efffect->SetTexture("DiffuseMap_Tex", m_Texture);
	m_Efffect->SetTexture("NormalMap_Tex", m_Normal);
	m_Efffect->SetTexture("SpecularMap_Tex", m_Specqural);


	UINT numPasses = 0;
	m_Efffect->Begin(&numPasses, NULL);
	{
		m_Efffect->BeginPass(0);
		{
			m_Mesh->DrawSubset(0);
		}
		m_Efffect->EndPass();

		g_pD3DDevice->SetRenderTarget(0, pHWBackBuffer);
		g_pD3DDevice->SetDepthStencilSurface(pHWDepthStencilBuffer);


		SAFE_RELEASE(pHWBackBuffer);
		SAFE_RELEASE(pHWDepthStencilBuffer);

		m_Efffect->CommitChanges();

		m_Efffect->BeginPass(1);
		{
			m_Mesh->DrawSubset(0);
		}
		m_Efffect->EndPass();
	}
	m_Efffect->End();

	//Shadow_Render();

	//AnotherRander();


}
