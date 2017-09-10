#include "stdafx.h"
#include "cScene_Test_1.h"
#include "cPlayer.h"


cScene_Test_1::cScene_Test_1()
{
}


cScene_Test_1::~cScene_Test_1()
{
}

void cScene_Test_1::Update()
{
	//int D = 0;
	m_pPlayer->Update();
}

void cScene_Test_1::Render()
{
	m_pPlayer->Render();
}

void cScene_Test_1::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}
