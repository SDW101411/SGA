#include "stdafx.h"
#include "cScene_Test_1.h"
#include "cPlayer.h"


cScene_Test_1::cScene_Test_1()
{
	m_pPlayer = new cPlayer;
}


cScene_Test_1::~cScene_Test_1()
{
	SAFE_DELETE(m_pPlayer);
}

void cScene_Test_1::Update()
{
	SAFE_UPDATE(m_pPlayer);
}

void cScene_Test_1::Render()
{
	SAFE_RENDER(m_pPlayer);
}

void cScene_Test_1::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if(m_pPlayer)
	m_pPlayer->MsgProc(hWnd, message, wParam, lParam);
}
