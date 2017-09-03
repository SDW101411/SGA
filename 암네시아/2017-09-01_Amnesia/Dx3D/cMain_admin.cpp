#include "stdafx.h"
#include "cMain_admin.h"
#include "cScene.h"
/*2017-09-02 ���� 1�� 25�� ���� ���� �Դϴ�. 
�̰����� ���� ���������� ���� �ϵ��� �սô�. 
cMain_Game���� ������ ���� Update�� Render, MsgProc 
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
