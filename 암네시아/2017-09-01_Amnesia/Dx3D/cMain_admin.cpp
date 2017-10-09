#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
#include "cMapToolScene.h"   // 테스트 씬 입니다 -영빈-
#include "cUIToolTestScene.h"
#include "cScene_Shader_Scene_Test.h"
#include "cMainMenuScene.h"
#include "cUITool_In_Game_Test.h"	// 게임 UI - LEE
#include "cLoadingScene.h"
#include "cScene_Light.h"
#include "cAStarScene.h"
#include "cDamegeImpact.h"
#include "cCursorStatus.h"
#include "cMouseCursor.h"
#include "cCloseOption.h"
/*
		2017-09-02 Main_admin.
		이곳에서 부터 게임제작을 시작 하도록 합시다. 
		cMain_Game에서 가져온 값들 Update와 Render, MsgProc 
*/

cMain_admin::cMain_admin()
{
	cMESH_MANAGER->INSERT_SHADER("Shader_Light", cMESH_MANAGER->LoadShader("Test/Normal_Light_4_Version.fx"));
	cMESH_MANAGER->INSERT_SHADER("Shader_Light_OutLine", cMESH_MANAGER->LoadShader("Test/Nomal_4Light_OutLine.fx"));
	cMESH_MANAGER->INSERT_SHADER("Shader_Lantern", cMESH_MANAGER->LoadShader("Test/Lantern.fx"));

	cMESH_MANAGER->INSERT("MAPMESH_TAG_CEILING_DEFAULT", "X_File/MapObjects/ceiling/arched");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CEILING_BROKEN", "X_File/MapObjects/ceiling/arched_broken");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CEILING_NORMAL", "X_File/MapObjects/ceiling/deafult2");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_WALL_WORN", "X_File/MapObjects/wall/default_worn");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_PILLAR_DEFAULT", "X_File/MapObjects/pillar/welder");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_PILLAR_FULL", "X_File/MapObjects/pillar/welder_convex");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_FLOOR_DEFAULT", "X_File/MapObjects/floor/deafult");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CONCAVE_WORN", "X_File/MapObjects/ceiling/concave_worn");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CORNER_CONCAVE_WORN", "X_File/MapObjects/ceiling/corner_concave_worn");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_CORNER_CONVER_SHORT", "X_File/MapObjects/ceiling/corner_concave_short");
	cMESH_MANAGER->INSERT("MAPMESH_TAG_TORCH_STATIC_01", "X_File/MapObjects/torch/torch_static01");
	//cMESH_MANAGER->INSERT("MAPMESH_TAG_BARREL_DEFAULT",			"X_File/MapObjects/barrel/barrel01");
	cMESH_MANAGER->INSERT("ITEMMESH_TAG_POTION_OIL", "X_File/entities/potion_oil/potion_oil");
	cMESH_MANAGER->INSERT("ITEMMESH_TAG_POTION_TINDERBOX", "X_File/entities/tinderbox/tinderbox");
	cMESH_MANAGER->INSERT("ITEMMESH_TAG_POTION_HEALTH", "X_File/entities/potion_health/potion_health");
	cMESH_MANAGER->INSERT("ITEMMESH_TAG_POTION_SANITY", "X_File/entities/potion_sanity/potion_sanity");
	cMESH_MANAGER->INSERT("PLAYERMESH_TAG_LANTERN", "X_File/entities/lantern/hand_lantern");

	g_pSoundTrack->Insert();
	
	g_pSceneManager->INSERT("cMapToolScene", new cMapToolScene);
	g_pSceneManager->INSERT("cAStarScene", new cAStarScene);
	g_pSceneManager->INSERT("cUITool_In_Game_Test", new cUITool_In_Game_Test);
	g_pSceneManager->INSERT("cMainMenuScene", new cMainMenuScene);
	g_pSceneManager->INSERT("cLoadingScene", new cLoadingScene);
	g_pSceneManager->INSERT("cScene_Light", new cScene_Light);
	g_pSceneManager->INSERT("cScene_Shader_Scene_Test", new cScene_Shader_Scene_Test);

	g_pSceneManager->SceneChange("cMainMenuScene");
	
	
	
	/*ITEMMESH_TAG_POTION_OIL,
	ITEMMESH_TAG_POTION_TINDERBOX,
	ITEMMESH_TAG_POTION_HEALTH,
	ITEMMESH_TAG_POTION_SANITY,*/
	
	//g_pSceneManager->SceneChange("cScene_Light");

	m_pMouseCursor = new cMouseCursor;
}

cMain_admin::~cMain_admin()
{
	SAFE_DELETE(m_pMouseCursor);
}

void cMain_admin::Update()
{
	g_pSceneManager->Update();
	SAFE_UPDATE(m_pMouseCursor);
}

void cMain_admin::Render()
{
	g_pSceneManager->Render();
	
}

void cMain_admin::RenderUI()
{
	g_pSceneManager->Render_UI();
	SAFE_RENDER(m_pMouseCursor);
}

void cMain_admin::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	g_pSceneManager->MsgProc(hWnd, message, wParam, lParam);
}
