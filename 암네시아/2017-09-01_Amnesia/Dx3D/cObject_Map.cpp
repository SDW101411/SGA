#include "stdafx.h"
#include "cObject_Map.h"
#include "cObject_Light.h"


cObject_Map::cObject_Map()
{
}

cObject_Map::cObject_Map(cMesh_Object_Tag Name, D3DXVECTOR3 Pos, D3DXVECTOR3 Rotate, D3DXVECTOR3 Scare)
{
	//m_Normal_Effect = cMESH_MANAGER->LoadShader("Test/Normal_Light_4_Version.fx");
	m_Normal_Effect = (LPD3DXEFFECT)cMESH_MANAGER->FIND_SHADER("Shader_Light");
	m_Pos = Pos;
	m_AngleX = Rotate.x; m_AngleY = Rotate.y; m_AngleZ = Rotate.z;
	m_ScaleX = Scare.x; m_ScaleY = Scare.y; m_ScaleZ = Scare.z;
	switch (Name)
	{
	case MAPMESH_TAG_CEILING_DEFAULT:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_CEILING_DEFAULT");
		break;
	case MAPMESH_TAG_CEILING_BROKEN:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_CEILING_BROKEN");
		break;
	case MAPMESH_TAG_CEILING_NORMAL:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_CEILING_NORMAL");
		break;
	case MAPMESH_TAG_WALL_WORN:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_WALL_WORN");
		break;
	case MAPMESH_TAG_PILLAR_DEFAULT:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_PILLAR_DEFAULT");
		break;
	case MAPMESH_TAG_PILLAR_FULL:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_PILLAR_FULL");
		break;
	case MAPMESH_TAG_FLOOR_DEFAULT:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_FLOOR_DEFAULT");
		break;
	case MAPMESH_TAG_CONCAVE_WORN:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_CONCAVE_WORN");
		break;
	case MAPMESH_TAG_CORNER_CONCAVE_WORN:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_CORNER_CONCAVE_WORN");
		break;
	case MAPMESH_TAG_CORNER_CONVER_SHORT:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_CORNER_CONVER_SHORT");
		break;
	case MAPMESH_TAG_BARREL_DEFAULT:
		cObject = cMESH_MANAGER->FIND("MAPMESH_TAG_BARREL_DEFAULT");
		break;
	default:
		break;
	}
}


cObject_Map::~cObject_Map()
{
	SAFE_DELETE(cObject);
	SAFE_DELETE(m_Normal_Effect);
	for each(auto p in m_Light_vec)
	{
		SAFE_DELETE(p);
	}
}

void cObject_Map::Update()
{

}

void cObject_Map::Render()
{
	AnotherRander_1_4Light_Version();
	AnotherRander_2();
}


D3DXMATRIX cObject_Map::WorldReturn()
{
	D3DXMATRIX Worldmat, Transmat, Anglemat, Scalemat;
	D3DXMATRIX xMat, yMat, zMat;
	D3DXMatrixIdentity(&Worldmat);
	D3DXMatrixIdentity(&Transmat);
	D3DXMatrixIdentity(&Anglemat);
	D3DXMatrixIdentity(&Scalemat);
	D3DXMatrixIdentity(&xMat);
	D3DXMatrixIdentity(&yMat);
	D3DXMatrixIdentity(&zMat);
	D3DXMatrixTranslation(&Transmat, m_Pos.x, m_Pos.y, m_Pos.z);
	D3DXMatrixRotationX(&xMat, m_AngleX);
	D3DXMatrixRotationY(&yMat, m_AngleY);
	D3DXMatrixRotationZ(&zMat, m_AngleZ);
	Anglemat = xMat * yMat * zMat;
	D3DXMatrixScaling(&Scalemat, m_ScaleX, m_ScaleY, m_ScaleZ);


	return Worldmat = Scalemat * Anglemat * Transmat;
}
void cObject_Map::AnotherRander_1()
{

	D3DXMATRIXA16 matView, matProjection;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &WorldReturn());
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
	D3DXVECTOR4	gWorldCameraPosition(cCameara_seting.x, cCameara_seting.y, cCameara_seting.z, 1.0f);

	/*FLOAT Length = D3DXVec3Length(&(m_Pos - cCameara_seting));
	m_Efffect->SetFloat("gLightLength", Length);*/


	m_Normal_Effect->SetVector("gWorldCameraPosition", &gWorldCameraPosition);
	m_Normal_Effect->SetVector("gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Normal_Effect->SetVector("gLightColor_1", &D3DXVECTOR4(cLight_Color_Seting_2.x, cLight_Color_Seting_2.y, cLight_Color_Seting_2.z, 1));
	m_Normal_Effect->SetVector("gLightColor_2", &D3DXVECTOR4(cLight_Color_Seting.x, cLight_Color_Seting.y, cLight_Color_Seting.z, 1));
	m_Normal_Effect->SetVector("gLightColor_3", &D3DXVECTOR4(cLight_Color_Seting_3.x, cLight_Color_Seting_3.y, cLight_Color_Seting_3.z, 1));
	m_Normal_Effect->SetVector("NormalMapping_Pass_0_Pixel_Shader_gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Normal_Effect->SetMatrix("gWorldMatrix", &WorldReturn());
	m_Normal_Effect->SetMatrix("gViewMatrix", &matView);
	m_Normal_Effect->SetMatrix("gProjectionMatrix", &matProjection);
	m_Normal_Effect->SetMatrix("gWorldViewProjectionMatrix", &(WorldReturn()*matView * matProjection));
	m_Normal_Effect->SetTexture("DiffuseMap_Tex", cObject->m_Texture);
	m_Normal_Effect->SetTexture("NormalMap_Tex", cObject->m_Normal);
	m_Normal_Effect->SetTexture("SpecularMap_Tex", cObject->m_Specqural);
}
void cObject_Map::AnotherRander_1_4Light_Version()
{
	D3DXMATRIXA16 matView, matProjection;
	g_pD3DDevice->SetTransform(D3DTS_WORLD, &WorldReturn());
	g_pD3DDevice->GetTransform(D3DTS_VIEW, &matView);
	g_pD3DDevice->GetTransform(D3DTS_PROJECTION, &matProjection);
	D3DXVECTOR4	gWorldCameraPosition(cCameara_seting.x, cCameara_seting.y, cCameara_seting.z, 1.0f);

	m_Normal_Effect->SetMatrix("gWorldMatrix", &WorldReturn());
	m_Normal_Effect->SetMatrix("gWorldViewProjectionMatrix", &(WorldReturn()*matView * matProjection));

	m_Normal_Effect->SetVector("gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Normal_Effect->SetVector("Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));

	if (m_Light_vec.size() > 0)
	{
		m_Normal_Effect->SetVector("gWorldLightPosition_2", &D3DXVECTOR4(m_Light_vec[0]->m_Pos.x, m_Light_vec[0]->m_Pos.y, m_Light_vec[0]->m_Pos.z, 1.0f));
		m_Normal_Effect->SetVector("Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_2", &D3DXVECTOR4(m_Light_vec[0]->m_Pos.x, m_Light_vec[0]->m_Pos.y, m_Light_vec[0]->m_Pos.z, 1.0f));
		m_Normal_Effect->SetBool("Light_2", m_Light_vec[0]->m_Fire_On);
	}
	if (m_Light_vec.size() > 1)
	{
		m_Normal_Effect->SetVector("gWorldLightPosition_3", &D3DXVECTOR4(m_Light_vec[1]->m_Pos.x, m_Light_vec[1]->m_Pos.y, m_Light_vec[1]->m_Pos.z, 1.0f));
		m_Normal_Effect->SetVector("Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_3", &D3DXVECTOR4(m_Light_vec[1]->m_Pos.x, m_Light_vec[1]->m_Pos.y, m_Light_vec[1]->m_Pos.z, 1.0f));
		m_Normal_Effect->SetBool("Light_3", m_Light_vec[1]->m_Fire_On);
	}
	if (m_Light_vec.size() > 2)
	{
		m_Normal_Effect->SetVector("gWorldLightPosition_4", &D3DXVECTOR4(m_Light_vec[2]->m_Pos.x, m_Light_vec[2]->m_Pos.y, m_Light_vec[2]->m_Pos.z, 1.0f));
		m_Normal_Effect->SetVector("Normal_Light_ALL_Pass_0_Pixel_Shader_gWorldLightPosition_4", &D3DXVECTOR4(m_Light_vec[2]->m_Pos.x, m_Light_vec[2]->m_Pos.y, m_Light_vec[2]->m_Pos.z, 1.0f));
		m_Normal_Effect->SetBool("Light_4", m_Light_vec[2]->m_Fire_On);
	}
	m_Normal_Effect->SetFloat("cLight_Length",10.0f);



	m_Normal_Effect->SetVector("gWorldCameraPosition", &gWorldCameraPosition);
	m_Normal_Effect->SetVector("gLightColor_1", &D3DXVECTOR4(cLight_Color_Seting_2.x, cLight_Color_Seting_2.y, cLight_Color_Seting_2.z, 1));
	m_Normal_Effect->SetVector("gLightColor_2", &D3DXVECTOR4(cLight_Color_Seting.x, cLight_Color_Seting.y, cLight_Color_Seting.z, 1));
	m_Normal_Effect->SetVector("gLightColor_3", &D3DXVECTOR4(cLight_Color_Seting_3.x, cLight_Color_Seting_3.y, cLight_Color_Seting_3.z, 1));
	m_Normal_Effect->SetVector("NormalMapping_Pass_0_Pixel_Shader_gWorldLightPosition", &D3DXVECTOR4(cLight_Seting.x, cLight_Seting.y, cLight_Seting.z, 1.0f));
	m_Normal_Effect->SetMatrix("gWorldMatrix", &WorldReturn());
	m_Normal_Effect->SetMatrix("gViewMatrix", &matView);
	m_Normal_Effect->SetMatrix("gProjectionMatrix", &matProjection);
	m_Normal_Effect->SetTexture("DiffuseMap_Tex", cObject->m_Texture);
	m_Normal_Effect->SetTexture("NormalMap_Tex", cObject->m_Normal);
	m_Normal_Effect->SetTexture("SpecularMap_Tex", cObject->m_Specqural);
}
void cObject_Map::AnotherRander_2()
{
	UINT numPasses = 0;
	m_Normal_Effect->Begin(&numPasses, NULL);

	for (UINT i = 0; i < numPasses; ++i)
	{
		m_Normal_Effect->BeginPass(i);

		cObject->m_Mesh->DrawSubset(0);

		m_Normal_Effect->EndPass();
	}

	m_Normal_Effect->End();
}

void cObject_Map::m_Light_Vec_Push(cObject_Light * save_Target)
{
	if (m_Light_vec.size() < 2)
	{
		m_Light_vec.push_back(save_Target);
	}
	
}
