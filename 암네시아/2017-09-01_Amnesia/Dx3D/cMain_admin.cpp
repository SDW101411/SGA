#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
#include "cMapToolScene.h"   // �׽�Ʈ �� �Դϴ� -����-
#include "cUIToolTestScene.h"
#include "cScene_Shader_Scene_Test.h"
#include "cMainMenuScene.h"
#include "cUITool_In_Game_Test.h"	// ���� UI - LEE
/*
		2017-09-02 Main_admin.
		�̰����� ���� ���������� ���� �ϵ��� �սô�. 
		cMain_Game���� ������ ���� Update�� Render, MsgProc 
		*/

cMain_admin::cMain_admin()
{
	g_pSceneManager->INSERT("cMapToolScene", new cMapToolScene);
	g_pSceneManager->INSERT("cUITool_In_Game_Test", new cUITool_In_Game_Test);
	g_pSceneManager->INSERT("cMainMenuScene", new cMainMenuScene);
<<<<<<< .mine













=======
	//g_pSceneManager->INSERT("cScene_Shader_Scene_Test", new cScene_Shader_Scene_Test);
<<<<<<< HEAD
=======
=======
	//SCENE_MANAGER->INSERT("MapToolScene", new cMapToolScene);
	//SCENE_MANAGER->INSERT("1", new cScene_Test_1);

	//g_pSceneManager->INSERT("2", new cUITool_In_Game_Test);
	/*g_pSceneManager->INSERT("3", new cMainMenuScene);
	g_pSceneManager->INSERT("4", new cScene_Shader_Scene_Test);*/

	g_pSceneManager->INSERT("2", new cUITool_In_Game_Test);
	g_pSceneManager->INSERT("3", new cMainMenuScene);
>>>>>>> .theirs
	g_pSceneManager->INSERT("cScene_Shader_Scene_Test", new cScene_Shader_Scene_Test);
>>>>>>> dafb71557db0837db8fc103699c52e669c1b74ce

	g_pSceneManager->SceneChange("cMainMenuScene");

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
	g_pSceneManager->MsgProc(hWnd, message, wParam, lParam);
}
