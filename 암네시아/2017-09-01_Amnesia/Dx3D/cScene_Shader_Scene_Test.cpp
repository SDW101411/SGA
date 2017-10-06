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
#include "cMapLoader.h"
<<<<<<< HEAD
#include "cObject_Item.h"

=======
#include "cDamegeImpact.h"
#include "cUI_In_Game.h"
#include "cCursorStatus.h"
>>>>>>> 0cff4a77d546dc449eb389c6aa0db8854e255bf2

cScene_Shader_Scene_Test::cScene_Shader_Scene_Test()
	: m_pDamegeImpact(NULL)
	, m_pUI_In_Game(NULL)
{
	m_pPlayer = NULL;
}


cScene_Shader_Scene_Test::~cScene_Shader_Scene_Test()
{
	SAFE_DELETE(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_DELETE(p);
	for each(auto p in cObject_Map_Vec)SAFE_DELETE(p);
	for each(auto p in cObject_Light_vec)SAFE_DELETE(p);
	SAFE_DELETE(m_pDamegeImpact);
	SAFE_DELETE(m_pUI_In_Game);
}

void cScene_Shader_Scene_Test::Setup()
{
	//cMapLoader loader;
	//cObject_Map_Vec = loader.LoadToObject_Map();
	//cObject_Light_vec = loader.LoadToObject_Light();
	
<<<<<<< HEAD
	m_pPlayer = new cPlayer(this);
	/*for (int i = 0; i < g_pLoadManager()->GetObject_Map_Vec().size(); ++i)
=======
	m_pPlayer = new cPlayer;
	m_pUI_In_Game = new cUI_In_Game;
	m_pDamegeImpact = new cDamegeImpact;
	for (int i = 0; i < g_pLoadManager()->GetObject_Map_Vec().size(); ++i)
>>>>>>> 0cff4a77d546dc449eb389c6aa0db8854e255bf2
	{
		cObject_Map_Vec.push_back(g_pLoadManager()->GetObject_Map_Vec()[i]);
	}

	for (int i = 0; i < g_pLoadManager()->GetObject_Light_Vec().size(); ++i)
	{
		cObject_Light_vec.push_back(g_pLoadManager()->GetObject_Light_Vec()[i]);
	}

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

<<<<<<< HEAD

	

	cObject_Item *Save_Item_1 = new cObject_Item(ITEMMESH_TAG_POTION_OIL, D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_1);

	cObject_Item *Save_Item_2 = new cObject_Item(ITEMMESH_TAG_POTION_TINDERBOX, D3DXVECTOR3(1, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_2);

	cObject_Item *Save_Item_3 = new cObject_Item(ITEMMESH_TAG_POTION_HEALTH, D3DXVECTOR3(2, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_3);

	cObject_Item *Save_Item_4 = new cObject_Item(ITEMMESH_TAG_POTION_SANITY, D3DXVECTOR3(3, 0, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));

	cObject_Item_vec.push_back(Save_Item_4);

	//g_pLoadManager()->GetObject_Map_Vec().clear();
	//g_pLoadManager()->GetObject_Light_Vec().clear();
=======
	g_pLoadManager()->GetObject_Map_Vec().clear();
	g_pLoadManager()->GetObject_Light_Vec().clear();
>>>>>>> 0cff4a77d546dc449eb389c6aa0db8854e255bf2
	/*cObject_Game *Test = new cObject_shirt_white;
	Test->Set_Anit1hing(D3DXVECTOR3(-5, 1, 0), 0, 0, 0, 1, 1, 1);
	cObject_Game *Test_1 = new cObject_shirt_white_Normal;
	Test_1->Set_Anit1hing_Test(D3DXVECTOR3(-5, 1, -5), 0, 0, 0, 1, 1, 1);
	cObject_Game *Test_2 = new cObject_shirt_white_Normal;
	Test_2->Set_Anit1hing_Test(D3DXVECTOR3(-5, 1, -6), 0, 0, 0, 1, 1, 1);
	cObject_Game *Test_3 = new cObject_shirt_white_Normal;
	Test_3->Set_Anit1hing_Test(D3DXVECTOR3(-5, 1, -7), 0, 0, 0, 1, 1, 1);
	cObject_Game *Test_4 = new cObject_shirt_white_Normal;
	Test_4->Set_Anit1hing_Test(D3DXVECTOR3(-5, 1, -8), 0, 0, 0, 1, 1, 1);

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cObject_Game *forTest = new cObject_shirt_white_Normal;
			forTest->Set_Anit1hing_Test(D3DXVECTOR3(i * 2 + 3, 1, j * 2 + 3), 0, 0, 0, 1, 1, 1);
			cObject_Vec.push_back(forTest);
		}
	}

	cObject_Vec.push_back(Test);
	cObject_Vec.push_back(Test_1);
	cObject_Vec.push_back(Test_2);
	cObject_Vec.push_back(Test_3);
	cObject_Vec.push_back(Test_4);

	cObject_Game *Test_6 = new cObject_shirt_white_Normal_Shadow;
	Test_6->Set_Anit1hing_Test(D3DXVECTOR3(0, 1, 0), 0, 0, 0, 5, 5, 5);
	cObject_Vec.push_back(Test_6);
	m_pPlayer = new cPlayer;


	cObject_Game *Test_Torch = new cObject_Torch;
	Test_Torch->Set_Anit1hing_Test(D3DXVECTOR3(1, 1, 1), 0, 0, 0, 1, 1, 1);
	cObject_Vec.push_back(Test_Torch);*/


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
	SAFE_UPDATE(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_UPDATE(p);

	for each(auto p in cObject_Map_Vec)SAFE_UPDATE(p);

	for each(auto p in cObject_Light_vec)SAFE_UPDATE(p);
<<<<<<< HEAD

	for each(auto p in cObject_Item_vec)SAFE_UPDATE(p);
=======
	SAFE_UPDATE(m_pDamegeImpact);
	SAFE_UPDATE(m_pUI_In_Game);
>>>>>>> 0cff4a77d546dc449eb389c6aa0db8854e255bf2
}

void cScene_Shader_Scene_Test::Render()
{
	SAFE_RENDER(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_RENDER(p);

	for each(auto p in cObject_Map_Vec)SAFE_RENDER(p);

	for each(auto p in cObject_Light_vec)SAFE_RENDER(p);
<<<<<<< HEAD

	for each(auto p in cObject_Item_vec)SAFE_RENDER(p);

	SAFE_RENDER(m_pPlayer);
=======
	SAFE_RENDER(m_pUI_In_Game);
	SAFE_RENDER(m_pDamegeImpact);
>>>>>>> 0cff4a77d546dc449eb389c6aa0db8854e255bf2
}

void cScene_Shader_Scene_Test::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pPlayer) m_pPlayer->MsgProc(hWnd, message, wParam, lParam);
}
