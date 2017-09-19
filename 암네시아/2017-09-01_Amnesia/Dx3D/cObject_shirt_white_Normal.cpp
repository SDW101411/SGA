#include "stdafx.h"
#include "cObject_shirt_white_Normal.h"
#include "cObject_Game.h"
#include "cObjLoader.h"


cObject_shirt_white_Normal::cObject_shirt_white_Normal()
{
	m_Mesh = LoadModel("Test/shirt_hanging_white.x");
	m_Texture = LoadTexture("Test/shirt_white.dds");
	m_Normal = LoadTexture("Test/shirt_white_nrm.dds");
	m_Specqural= LoadTexture("Test/shirt_white_spec.dds");
	m_Efffect = LoadShader("Test/NormalMapping.fx");
}


cObject_shirt_white_Normal::~cObject_shirt_white_Normal()
{
	SAFE_RELEASE(m_Mesh);
	SAFE_RELEASE(m_Texture);
	SAFE_RELEASE(m_Normal);
	SAFE_RELEASE(m_Specqural);
	SAFE_RELEASE(m_Efffect);
}

void cObject_shirt_white_Normal::Update()
{
	m_AngleY += 0.01f;
}

void cObject_shirt_white_Normal::Render()
{

	D3DXMATRIXA16 matView, matProjection;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &WorldReturn());
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
	D3DXVECTOR4		gWorldCameraPosition(cCameara_seting.x, cCameara_seting.y, cCameara_seting.z, 1.0f);

	FLOAT Length = D3DXVec3Length(&(m_Pos - cCameara_seting));

	m_Efffect->SetFloat("gLightLength", Length);

	m_Efffect->SetVector("gWorldCameraPosition", &gWorldCameraPosition);
	m_Efffect->SetVector("gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z,1.0f));
	m_Efffect->SetVector("gLightColor_1", &D3DXVECTOR4(cLight_Color_Seting_2.x, cLight_Color_Seting_2.y, cLight_Color_Seting_2.z, 1));
	m_Efffect->SetVector("gLightColor_2", &D3DXVECTOR4(cLight_Color_Seting.x, cLight_Color_Seting.y, cLight_Color_Seting.z, 1));
	m_Efffect->SetMatrix("gWorldMatrix", &WorldReturn());
	m_Efffect->SetMatrix("gViewMatrix", &matView);
	m_Efffect->SetMatrix("gProjectionMatrix", &matProjection);
	m_Efffect->SetMatrix("gWorldViewProjectionMatrix", &(WorldReturn()*matView * matProjection));
	m_Efffect->SetTexture("DiffuseMap_Tex", m_Texture);
	m_Efffect->SetTexture("NormalMap_Tex", m_Normal);
	m_Efffect->SetTexture("SpecularMap_Tex", m_Specqural);

	AnotherRander();
}
