#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
#include "cMapToolScene.h"   // �׽�Ʈ �� �Դϴ� -����-
#include "cUIToolTestScene.h"
#include "cScene_Shader_Scene_Test.h"
#include "cMainMenuScene.h"
#include "cUITool_In_Game_Test.h"	// ���� UI - LEE
#include "cLoadingScene.h"
#include "cScene_Light.h"
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
	g_pSceneManager->INSERT("cScene_Light", new cScene_Light);
	//g_pSceneManager->INSERT("cScene_Shader_Scene_Test", new cScene_Shader_Scene_Test);

	g_pSceneManager->SceneChange("cMainMenuScene");


	cMESH_MANAGER->INSERT("MAPMESH_TAG_CEILING_DEFAULT",		"X_File/MapObjects/ceiling/arched");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CEILING_BROKEN",			"X_File/MapObjects/ceiling/arched_broken");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CEILING_NORMAL",			"X_File/MapObjects/ceiling/deafult2");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_WALL_WORN",				"X_File/MapObjects/wall/default_worn");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_PILLAR_DEFAULT",			"X_File/MapObjects/pillar/welder");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_PILLAR_FULL",			"X_File/MapObjects/pillar/welder_convex");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_FLOOR_DEFAULT",			"X_File/MapObjects/floor/deafult");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CONCAVE_WORN",			"X_File/MapObjects/ceiling/concave_worn");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CORNER_CONCAVE_WORN",	"X_File/MapObjects/ceiling/corner_concave_worn");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CORNER_CONVER_SHORT",	"X_File/MapObjects/ceiling/corner_concave_short");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_TORCH_STATIC_01",		"X_File/MapObjects/torch/torch_static01");
	
	
	
	//g_pSceneManager->SceneChange("cScene_Light");
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
