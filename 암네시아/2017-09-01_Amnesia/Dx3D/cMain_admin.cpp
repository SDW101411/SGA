#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
/*2017-09-02 오후 1시 25분 메인 게임 입니다. 
이곳에서 부터 게임제작을 시작 하도록 합시다. 
cMain_Game에서 가져온 값들 Update와 Render, MsgProc 
*/


cMain_admin::cMain_admin()
	:m_pNow_Scene(NULL)
{
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
}
