#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
#include "cScene_Test_1.h"
#include "cMapToolScene.h"	// �׽�Ʈ �� �Դϴ� -����-
#include "cUIToolTestScene.h"
/*2017-09-02 ���� 1�� 25�� ���� ���� �Դϴ�. 
�̰����� ���� ���������� ���� �ϵ��� �սô�. 
cMain_Game���� ������ ���� Update�� Render, MsgProc 
*/

cMain_admin::cMain_admin()
	: m_pNow_Scene(NULL)
	, m_pFont(NULL)
{
	//m_pNow_Scene = new cScene_Test_1; // 1�� �׽�Ʈ �Ϸ� ��ӿ� ���� �⺻ �׽�Ʈ
	//m_pNow_Scene = new cMapToolScene; // ���� �׽�Ʈ �Դϴ� - ���� -
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
	strcpy_s(fd.FaceName, "�ü�ü");	//�۲� ��Ÿ��
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
