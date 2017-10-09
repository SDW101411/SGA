#include "stdafx.h"
#include "cScene_Shader_Scene_Test.h"
#include "cObject_Game.h"
#include "cObject_shirt_white.h"
#include "cObject_shirt_white_Normal.h"
#include "cObject_shirt_white_Normal_Shadow.h"
#include "cObject_bottle.h"
#include "cPlayer.h"
#include "cObject_Torch.h"
#include "cObject_Map.h"
#include "cObject_Light.h"
#include "cObject_Item.h"
#include "cMapLoader.h"
#include "cDamegeImpact.h"
#include "cUI_In_Game.h"
#include "cCursorStatus.h"
#include "cFrustum.h"
#include "cCloseOption.h"

cScene_Shader_Scene_Test::cScene_Shader_Scene_Test()
	: m_pDamegeImpact(NULL)
	, m_pUI_In_Game(NULL)
	, m_pCursorStatus(NULL)
	, m_pCloseOption(NULL)
{
	m_pPlayer = NULL;
}


cScene_Shader_Scene_Test::~cScene_Shader_Scene_Test()
{
	m_pUI_In_Game->GetTabUIOn(false);
	SAFE_DELETE(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_DELETE(p);
	for each(auto p in cObject_Map_Vec)SAFE_DELETE(p);
	for each(auto p in cObject_Light_vec)SAFE_DELETE(p);
	for each(auto p in cObject_Item_vec)SAFE_DELETE(p);
	SAFE_DELETE(m_pDamegeImpact);
	SAFE_DELETE(m_pUI_In_Game);
	SAFE_DELETE(m_pCursorStatus);
	SAFE_DELETE(m_pCloseOption);
}

void cScene_Shader_Scene_Test::Setup()
{
	m_pPlayer = new cPlayer(this, D3DXVECTOR3(10.0f,0.0f,-10.0f));
	m_pUI_In_Game = new cUI_In_Game;
	m_pDamegeImpact = new cDamegeImpact;
	m_pCursorStatus = new cCursorStatus;
	m_pCloseOption = new cCloseOption;

	cObject_Map_Vec = g_pLoadManager()->GetObject_Map_Vec();
	cObject_Light_vec = g_pLoadManager()->GetObject_Light_Vec();

	D3DXVECTOR3 lightPos, Light_Position, Particle_Position;
	D3DXMATRIX	matRX, matRY, matRZ, matR;
	D3DXMatrixRotationX(&matRX, 0);
	D3DXMatrixRotationY(&matRY, 0);
	D3DXMatrixRotationZ(&matRZ, 0);
	matR = matRX * matRY * matRZ;
	D3DXVec3TransformCoord(&Particle_Position, &D3DXVECTOR3(0, 0.9, -0.65), &matR);

	D3DXVec3TransformCoord(&Light_Position, &D3DXVECTOR3(0, 1, -1), &matR);
	//Save_1->m_lightPos_Light = dir;
	
	cObject_Light *Save_1 = new cObject_Light(MAPMESH_TAG_TORCH_STATIC_01, D3DXVECTOR3(3, 1, 3), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1), Particle_Position, Light_Position);
	Save_1->m_Fire_On = true;

	cObject_Light_vec.push_back(Save_1);

	cObject_Item *Save_Item_1 = new cObject_Item(ITEMMESH_TAG_POTION_OIL, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_1);

	cObject_Item *Save_Item_2 = new cObject_Item(ITEMMESH_TAG_POTION_TINDERBOX, D3DXVECTOR3(1, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_2);

	cObject_Item *Save_Item_3 = new cObject_Item(ITEMMESH_TAG_POTION_HEALTH, D3DXVECTOR3(2, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_3);

	cObject_Item *Save_Item_4 = new cObject_Item(ITEMMESH_TAG_POTION_SANITY, D3DXVECTOR3(3, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_4);

	g_pLoadManager()->GetObject_Map_Vec().clear();
	g_pLoadManager()->GetObject_Light_Vec().clear();

	m_pFrustum_c = NULL;
	m_pFrustum_c = new cFrustum;
}

void cScene_Shader_Scene_Test::Release()
{
	for each(auto p in cObject_Vec)SAFE_DELETE(p);

	for each(auto p in cObject_Map_Vec)SAFE_DELETE(p);

	for each(auto p in cObject_Light_vec)SAFE_DELETE(p);

	for each(auto p in cObject_Item_vec)SAFE_DELETE(p);
}

void cScene_Shader_Scene_Test::Update()
{
	m_pCursorStatus->CursorStatus(CURSORSTATUS::CUR_NORMAL);
	SAFE_UPDATE(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_UPDATE(p);

	for each(auto p in cObject_Map_Vec)SAFE_UPDATE(p);

	for each(auto p in cObject_Light_vec)SAFE_UPDATE(p);

	for each(auto p in cObject_Item_vec)SAFE_UPDATE(p);
	SAFE_UPDATE(m_pDamegeImpact);
	SAFE_UPDATE(m_pUI_In_Game);
	SAFE_UPDATE(m_pCursorStatus);
	SAFE_UPDATE(m_pCloseOption);
	
	if (m_pFrustum_c) m_pFrustum_c->Update();
}

void cScene_Shader_Scene_Test::Render()
{
	SAFE_RENDER(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_RENDER(p);


	for each (auto p in cObject_Map_Vec)
	{
		ST_SPHERE stSphere;
		stSphere.p = p->GetPosition();
		stSphere.r = 1.5f;
		if (m_pFrustum_c->IsIn(&stSphere))
		{
			SAFE_RENDER(p);
		}
	}

	for each(auto p in cObject_Light_vec)SAFE_RENDER(p);

	for each(auto p in cObject_Item_vec)
	{
		if(p->m_Render_On)
		SAFE_RENDER(p);
	}

	SAFE_RENDER(m_pPlayer);
}

void cScene_Shader_Scene_Test::RenderUI()
{
	SAFE_RENDER(m_pDamegeImpact);
	SAFE_RENDER(m_pCursorStatus);
	SAFE_RENDER(m_pUI_In_Game);
	SAFE_RENDER(m_pCloseOption);
}

void cScene_Shader_Scene_Test::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pPlayer) m_pPlayer->MsgProc(hWnd, message, wParam, lParam);
}
