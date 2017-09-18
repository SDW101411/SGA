#include "stdafx.h"
#include "cObject_bottle.h"
#include "cObject_Game.h"
#include "cObjLoader.h"


cObject_bottle::cObject_bottle()
{

	m_Mesh = LoadModel("Test/amnesia_bottle.x");
	m_Texture = LoadTexture("Test/amnesia_bottle.dds");
	m_Efffect = LoadShader("Test/Texture_Shader.fx");

	/*m_Mesh = LoadModel("Test/amnesia_bottle.x");
	m_Texture = LoadTexture("Test/amnesia_bottle.dds");
	m_Normal = LoadTexture("Test/shirt_white_nrm.dds");
	m_Specqural = LoadTexture("Test/shirt_white_spec.dds");
		m_Efffect = LoadShader("Test/NormalMapping.fx");*/
}


cObject_bottle::~cObject_bottle()
{
	SAFE_RELEASE(m_Mesh);
	SAFE_RELEASE(m_Texture);
}

void cObject_bottle::Update()
{
	m_AngleY += 0.01f;
}

void cObject_bottle::Render()
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
