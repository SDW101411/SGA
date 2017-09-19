#include "stdafx.h"
#include "cObject_shirt_white.h"
#include "cObject_Game.h"
#include "cObjLoader.h"


cObject_shirt_white::cObject_shirt_white()
{
	m_Mesh = LoadModel("Test/shirt_hanging_white.x");
	m_Texture = LoadTexture("Test/shirt_white.dds");
	m_Efffect = LoadShader("Test/Texture_Shader.fx");
}


cObject_shirt_white::~cObject_shirt_white()
{
	SAFE_RELEASE(m_Mesh);
	SAFE_RELEASE(m_Texture);
}

void cObject_shirt_white::Update()
{
	m_AngleY += 0.01f;
}

void cObject_shirt_white::Render()
{

	D3DXMATRIXA16 matView, matProjection;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &WorldReturn());
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
	

	m_Efffect->SetMatrix("WorldMatrix", &WorldReturn());
	m_Efffect->SetMatrix("ViewMatrix", &matView);
	m_Efffect->SetMatrix("ProjectionMatrix", &matProjection);
	m_Efffect->SetTexture("DiffuseMap_Tex", m_Texture);


	AnotherRander();
}
