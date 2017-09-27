#include "stdafx.h"
#include "cScene_Light.h"

#include "cObject_shirt_white.h"
#include "cObject_shirt_white_Normal.h"
#include "cObject_shirt_white_Normal_Shadow.h"
#include "cObject_bottle.h"
#include "cPlayer.h"
#include "cObject_Torch.h"
#include "cObject_Map.h"
#include "cMapLoader.h"
#include "cObject_Light.h"
#include "cParticle_Fire.h"


cScene_Light::cScene_Light()
{
}


cScene_Light::~cScene_Light()
{
	for each(auto p in cObject_Map_Vec)SAFE_DELETE(p);
	for each(auto p in cObject_Light_Vec)SAFE_DELETE(p);

	
}

void cScene_Light::Setup()
{
	m_pPlayer = new cPlayer;

	cObject_Light *Save_1 = new cObject_Light(MAPMESH_TAG_TORCH_STATIC_01,D3DXVECTOR3(3,1,3), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	Save_1->m_Fire_On = true;

	cObject_Light *Save_2 = new cObject_Light(MAPMESH_TAG_TORCH_STATIC_01, D3DXVECTOR3(-3, 1, -3), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	Save_2->m_Fire_On = true;

	cObject_Map *Save_M_1 = new cObject_Map(MAPMESH_TAG_PILLAR_FULL, D3DXVECTOR3(0.5, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	cObject_Map *Save_M_2 = new cObject_Map(MAPMESH_TAG_PILLAR_FULL, D3DXVECTOR3(-0.5, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	cObject_Map *Save_M_3 = new cObject_Map(MAPMESH_TAG_PILLAR_FULL, D3DXVECTOR3(0, 0, 0.5), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	cObject_Map *Save_M_4 = new cObject_Map(MAPMESH_TAG_PILLAR_FULL, D3DXVECTOR3(0, 0, -0.5), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	Save_M_1->m_Light_Vec_Push(Save_1);
	Save_M_1->m_Light_Vec_Push(Save_2);

	Save_M_2->m_Light_Vec_Push(Save_1);
	Save_M_2->m_Light_Vec_Push(Save_2);

	Save_M_3->m_Light_Vec_Push(Save_1);
	Save_M_3->m_Light_Vec_Push(Save_2);

	Save_M_4->m_Light_Vec_Push(Save_1);
	Save_M_4->m_Light_Vec_Push(Save_2);

	cObject_Light_Vec.push_back(Save_1);
	cObject_Light_Vec.push_back(Save_2);
	cObject_Map_Vec.push_back(Save_M_1);
	cObject_Map_Vec.push_back(Save_M_2);
	cObject_Map_Vec.push_back(Save_M_3);
	cObject_Map_Vec.push_back(Save_M_4);

	Test_Particle = new cParticle_Fire;
}

void cScene_Light::Release()
{
	SAFE_DELETE(m_pPlayer);
	for each(auto p in cObject_Map_Vec)SAFE_DELETE(p);
	for each(auto p in cObject_Light_Vec)SAFE_DELETE(p);
	SAFE_DELETE(Test_Particle);

}

void cScene_Light::Update()
{
	SAFE_UPDATE(m_pPlayer);
	for each(auto p in cObject_Map_Vec)SAFE_UPDATE(p);
	for each(auto p in cObject_Light_Vec)SAFE_UPDATE(p);
	Test_Particle->Update();
}

void cScene_Light::Render()
{
	SAFE_RENDER(m_pPlayer);
	for each(auto p in cObject_Map_Vec)SAFE_RENDER(p);
	for each(auto p in cObject_Light_Vec)SAFE_RENDER(p);
	Test_Particle->Render();
}

void cScene_Light::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	m_pPlayer->MsgProc(hWnd, message, wParam, lParam);
}
