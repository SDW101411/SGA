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
#include "cMapLoader.h"


cScene_Shader_Scene_Test::cScene_Shader_Scene_Test()
{
	m_pPlayer = NULL;
}


cScene_Shader_Scene_Test::~cScene_Shader_Scene_Test()
{
	//SAFE_DELETE(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_DELETE(p);
	for each(auto p in cObject_Map_Vec)SAFE_DELETE(p);
}

void cScene_Shader_Scene_Test::Setup()
{
	//cMapLoader loader;
	//cObject_Map_Vec = loader.LoadToObject_Map();
	
	m_pPlayer = new cPlayer;
	for (int i = 0; i < g_pLoadManager()->GetObject_Map_Vec().size(); ++i)
	{
		cObject_Map_Vec.push_back(g_pLoadManager()->GetObject_Map_Vec()[i]);
	}
	g_pLoadManager()->GetObject_Map_Vec().clear();
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
	SAFE_DELETE(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_DELETE(p);

	for each(auto p in cObject_Map_Vec)SAFE_DELETE(p);

	
}

void cScene_Shader_Scene_Test::Update()
{
	SAFE_UPDATE(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_UPDATE(p);

	for each(auto p in cObject_Map_Vec)SAFE_UPDATE(p);
}

void cScene_Shader_Scene_Test::Render()
{
	SAFE_RENDER(m_pPlayer);
	for each(auto p in cObject_Vec)SAFE_RENDER(p);

	for each(auto p in cObject_Map_Vec)SAFE_RENDER(p);
}

void cScene_Shader_Scene_Test::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pPlayer) m_pPlayer->MsgProc(hWnd, message, wParam, lParam);
}
