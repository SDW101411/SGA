#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
#include "cMapToolScene.h"   // 테스트 씬 입니다 -영빈-
#include "cUITool_In_Game_Test.h"
/*
		2017-09-02 Main_admin. 
		이곳에서 부터 게임제작을 시작 하도록 합시다. 
		cMain_Game에서 가져온 값들 Update와 Render, MsgProc 
		*/

cMain_admin::cMain_admin()
	:m_pNow_Scene(NULL)
{
	//m_pNow_Scene = new cScene_Test_1; // 1차 테스트 완료 상속에 대한 기본 테스트
	//m_pNow_Scene = new cMapToolScene; // 맵툴 테스트 입니다 - 영빈 -
	m_pNow_Scene = new cUITool_In_Game_Test; // UI 테스트 - LEE
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
