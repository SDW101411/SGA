#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
<<<<<<< HEAD
#include "cMapToolScene.h"   // �׽�Ʈ �� �Դϴ� -����-
#include "cUIToolTestScene.h"
#include "cScene_Shader_Scene_Test.h"
=======
#include "cMapToolScene.h"			// �׽�Ʈ �� �Դϴ� -����-
#include "cUITool_In_Game_Test.h"	// ���� UI - LEE
#include "cMainMenuScene.h"			// ���� UI - LEE
>>>>>>> f923c5e352ebbc4beae924924972ac54f127d0fe
/*
		2017-09-02 Main_admin. 
		�̰����� ���� ���������� ���� �ϵ��� �սô�. 
		cMain_Game���� ������ ���� Update�� Render, MsgProc 
		*/

cMain_admin::cMain_admin()
	:m_pNow_Scene(NULL)
{
	//m_pNow_Scene = new cScene_Test_1; // 1�� �׽�Ʈ �Ϸ� ��ӿ� ���� �⺻ �׽�Ʈ

	//m_pNow_Scene = new cMapToolScene; // ���� �׽�Ʈ �Դϴ� - ���� -
<<<<<<< HEAD

	//m_pNow_Scene = new cUIToolTestScene; // UI �׽�Ʈ - LEE

	m_pNow_Scene = new cScene_Shader_Scene_Test;
=======
	m_pNow_Scene = new cUITool_In_Game_Test;	// UI �׽�Ʈ - LEE
	//m_pNow_Scene = new cMainMenuScene;			// ���� UI - LEE
>>>>>>> f923c5e352ebbc4beae924924972ac54f127d0fe
}


cMain_admin::~cMain_admin()
{
	SAFE_DELETE(m_pNow_Scene);
}


void cMain_admin::Update()
{
	SAFE_UPDATE(m_pNow_Scene);
}

void cMain_admin::Render()
{
	SAFE_RENDER(m_pNow_Scene);
}

void cMain_admin::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pNow_Scene)
	m_pNow_Scene->MsgProc(hWnd, message, wParam, lParam);
}
