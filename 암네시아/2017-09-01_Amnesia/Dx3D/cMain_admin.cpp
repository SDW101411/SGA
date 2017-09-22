#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
#include "cMapToolScene.h"   // 테스트 씬 입니다 -영빈-
#include "cUIToolTestScene.h"
#include "cScene_Shader_Scene_Test.h"
#include "cMainMenuScene.h"
#include "cUITool_In_Game_Test.h"	// 게임 UI - LEE
/*
		2017-09-02 Main_admin.
		이곳에서 부터 게임제작을 시작 하도록 합시다. 
		cMain_Game에서 가져온 값들 Update와 Render, MsgProc 
		*/


cMain_admin::cMain_admin()
{
	//SCENE_MANAGER->INSERT("MapToolScene", new cMapToolScene);
	//SCENE_MANAGER->INSERT("1", new cScene_Test_1);
	//g_pSceneManager->INSERT("2", new cUITool_In_Game_Test);
	g_pSceneManager->INSERT("3", new cMainMenuScene);
	g_pSceneManager->INSERT("4", new cScene_Shader_Scene_Test);

	g_pSceneManager->SceneChange("3");
}


cMain_admin::~cMain_admin()
{
}


void cMain_admin::Update()
{
	g_pSceneManager->Update();
}

void cMain_admin::Render()
{
	g_pSceneManager->Render();
}

void cMain_admin::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}
