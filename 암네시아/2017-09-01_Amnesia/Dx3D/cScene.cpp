#include "stdafx.h"
#include "cScene.h"
#include "cPlayer.h"

//Scene
cScene::cScene()
{
	m_pPlayer = new cPlayer;
}


cScene::~cScene()
{
	SAFE_DELETE(m_pPlayer);
}

void cScene::Update()
{
	m_pPlayer->Update();
}

void cScene::Render()
{
	m_pPlayer->Render();
}

void cScene::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}