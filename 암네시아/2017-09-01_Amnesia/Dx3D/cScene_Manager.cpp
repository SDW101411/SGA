#include "stdafx.h"
#include "cScene_Manager.h"
#include "cScene.h"

//2017-09-04 추가된 씬 매니져 입니다. Map STL을 활용하여 정리합니다.

cScene_Manager::cScene_Manager(void)
{
}

cScene_Manager::~cScene_Manager(void)
{
}

void cScene_Manager::INSERT(char* szName, cScene* pScene)
{
	cScene_database[szName] = pScene;
}

cScene *cScene_Manager::FIND(char * szName)
{
	return cScene_database.find(szName)->second;
}

void cScene_Manager::SceneChange(char * szName)
{
	if(m_pCurrentScene) m_pCurrentScene->Release();
	m_pCurrentScene = FIND(szName);
	assert(m_pCurrentScene);
	m_pCurrentScene->Setup();
}

void cScene_Manager::Destroy()
{
	for each(auto p in cScene_database)
	{
		SAFE_DELETE(p.second);
	}
}

void cScene_Manager::Update()
{
	if (m_pCurrentScene) m_pCurrentScene->Update();
}

void cScene_Manager::Render()
{
	if (m_pCurrentScene) m_pCurrentScene->Render();
}

void cScene_Manager::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (m_pCurrentScene) m_pCurrentScene->MsgProc(hWnd, message, wParam, lParam);
}
