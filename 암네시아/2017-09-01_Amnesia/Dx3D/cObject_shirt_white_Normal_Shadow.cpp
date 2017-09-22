#include "stdafx.h"
#include "cObject_shirt_white_Normal_Shadow.h"


cObject_shirt_white_Normal_Shadow::cObject_shirt_white_Normal_Shadow()
{
	m_Mesh = LoadModel("Test/shirt_hanging_white.x");
	m_Texture = LoadTexture("Test/shirt_white.dds");
	m_Normal = LoadTexture("Test/shirt_white_nrm.dds");
	m_Specqural = LoadTexture("Test/shirt_white_spec.dds");
	m_Efffect = LoadShader("Test/NormalMappingAndShadow.fx");

	if (FAILED(g_pD3DDevice->CreateTexture(shadowMapSize, shadowMapSize, 1, D3DUSAGE_RENDERTARGET, D3DFMT_R32F, D3DPOOL_DEFAULT, &gpShadowRenderTarget, NULL)))return;
	
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
	m_AngleY += 0.01f;
}

void cObject_shirt_white_Normal_Shadow::Render()
{
	D3DXMATRIXA16 matView, matProjection, matLightView;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &WorldReturn());
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
	D3DXVECTOR4	gWorldCameraPosition(cCameara_seting.x, cCameara_seting.y, cCameara_seting.z, 1.0f);


	pHWBackBuffer = NULL;
	pHWDepthStencilBuffer = NULL;
	g_pD3DDevice->GetRenderTarget(0, &pHWBackBuffer);
	g_pD3DDevice->GetDepthStencilSurface(&pHWDepthStencilBuffer);

	// 그림자 맵의 렌더타깃과 깊이버퍼를 사용한다.
	pShadowSurface = NULL;
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

	/*FLOAT Length = D3DXVec3Length(&(m_Pos - cCameara_seting));
	m_Efffect->SetFloat("gLightLength", Length);*/

	m_Efffect->SetVector("gWorldCameraPosition", &gWorldCameraPosition);
	m_Efffect->SetVector("gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Efffect->SetVector("gLightColor_1", &D3DXVECTOR4(cLight_Color_Seting_2.x, cLight_Color_Seting_2.y, cLight_Color_Seting_2.z, 1));
	m_Efffect->SetVector("gLightColor_2", &D3DXVECTOR4(cLight_Color_Seting.x, cLight_Color_Seting.y, cLight_Color_Seting.z, 1));
	m_Efffect->SetVector("NormalMapping_Pass_0_Pixel_Shader_gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Efffect->SetMatrix("gWorldMatrix", &WorldReturn());
	m_Efffect->SetMatrix("gViewMatrix", &matView);
	m_Efffect->SetMatrix("gProjectionMatrix", &matProjection);
	m_Efffect->SetMatrix("gWorldViewProjectionMatrix", &(WorldReturn()*matView * matProjection));
	m_Efffect->SetMatrix("NormalMapping_Pass_0_Vertex_Shader_gWorldMatrix", &WorldReturn());
	m_Efffect->SetVector("NormalMapping_Pass_0_Vertex_Shader_gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Efffect->SetMatrix("NormalMapping_Pass_0_Vertex_Shader_gProjectionMatrix", &matProjection);

	m_Efffect->SetTexture("ShadowMap_Tex", gpShadowRenderTarget);

	//LPDIRECT3DSURFACE9 pShadowSurface = NULL;
	//gpShadowRenderTarget->GetSurfaceLevel(0, &pShadowSurface);

	D3DXVECTOR3 vEyePt(cLight_Seting);
	D3DXVECTOR3 vUpVec(0.0f, 1.0f, 0.0f);
	D3DXMatrixLookAtLH(&matLightView, &vEyePt, &m_Pos, &vUpVec);

	m_Efffect->SetMatrix("gLightViewMatrix", &matLightView);
	m_Efffect->SetMatrix("NormalMapping_Pass_0_Vertex_Shader_gLightViewMatrix", &matLightView);
	m_Efffect->SetTexture("DiffuseMap_Tex", m_Texture);
	m_Efffect->SetTexture("NormalMap_Tex", m_Normal);
	m_Efffect->SetTexture("SpecularMap_Tex", m_Specqural);

	Shadow_Render();

	//AnotherRander();


}
