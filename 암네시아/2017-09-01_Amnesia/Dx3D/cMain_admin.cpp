#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
#include "cMapToolScene.h"	// 테스트 씬 입니다 -영빈-
#include "cUIToolTestScene.h"
/*2017-09-02 오후 1시 25분 메인 게임 입니다. 
이곳에서 부터 게임제작을 시작 하도록 합시다. 
cMain_Game에서 가져온 값들 Update와 Render, MsgProc 
*/

cMain_admin::cMain_admin()
	: m_pNow_Scene(NULL)
	, m_pFont(NULL)
{
	//m_pNow_Scene = new cScene_Test_1; // 1차 테스트 완료 상속에 대한 기본 테스트
	//m_pNow_Scene = new cMapToolScene; // 맵툴 테스트 입니다 - 영빈 -
	m_pNow_Scene = new cUIToolTestScene;

}


cMain_admin::~cMain_admin()
{
	SAFE_DELETE(m_pNow_Scene);
	SAFE_RELEASE(m_pFont);
	g_pTextureManager->Destroy();
}


void cMain_admin::Setup()
{
	m_pNow_Scene->Setup();

	D3DXFONT_DESC fd;
	ZeroMemory(&fd, sizeof(D3DXFONT_DESC));
	fd.Height = 50;
	fd.Width = 25;
	fd.Weight = FW_NORMAL;
	fd.Italic = false;
	fd.CharSet = DEFAULT_CHARSET;
	fd.OutputPrecision = OUT_DEFAULT_PRECIS;
	fd.PitchAndFamily = FF_DONTCARE;
	//AddFontResource("umberto.ttf");
	strcpy_s(fd.FaceName, "궁서체");	//글꼴 스타일
	D3DXCreateFontIndirect(g_pD3DDevice, &fd, &m_pFont);
}

void cMain_admin::Update()
{
	//g_pTimeManager->Update();

	SAFE_UPDATE(m_pNow_Scene);
	m_fps = 1.0f / g_pTimeManager->GetDeltaTime();
}

void cMain_admin::Render()
{
	SAFE_RENDER(m_pNow_Scene);

	RECT rc;
	SetRect(&rc, 50, 20, 1000, 151);
	char str[256];
	sprintf(str, "FPS : %lu", m_fps);
	string s(str);
	m_pFont->DrawTextA(NULL,
		s.c_str(),
		s.length(),
		&rc,
		DT_LEFT | DT_TOP,
		D3DCOLOR_XRGB(255, 255, 255));
}

void cMain_admin::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}
