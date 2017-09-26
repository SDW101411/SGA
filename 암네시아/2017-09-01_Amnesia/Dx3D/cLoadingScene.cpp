#include "stdafx.h"
#include "cLoadingScene.h"
#include "cMapLoader.h"
#include "cObject_Map.h"
#include "cUIImageView.h"

CRITICAL_SECTION cs;

void cLoadingScene::ThFunc1(LPVOID pParam)
{
	cLoadingScene* pLoader;
	pLoader = (cLoadingScene*)pParam;
	cMapLoader Loader;
	pLoader->cObject_Map_Vec = Loader.LoadToObject_Map();
	cObject_Map *Save = new cObject_Map(WHITE_TAG, D3DXVECTOR3(0, 1, 0), D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(1, 1, 1));
	pLoader->cObject_Map_Vec.push_back(Save);

	EnterCriticalSection(&cs);
	g_pLoadManager()->cObject_Map_Vec = pLoader->cObject_Map_Vec;
	g_pSceneManager->SceneChange("cScene_Shader_Scene_Test");
	LeaveCriticalSection(&cs);
}

cLoadingScene::cLoadingScene()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/menu_loading_screen.jpg");
	pImageView->SetScaling(0.75f, 0.65f);
	m_pUIRoot = pImageView;
}

cLoadingScene::~cLoadingScene()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cLoadingScene::Setup()
{
	DWORD dwThID;
	InitializeCriticalSection(&cs);
	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThFunc1, this, NULL/*CREATE_SUSPENDED*/, &dwThID));
}

void cLoadingScene::Release()
{
	//for each(auto p in cObject_Map_Vec) SAFE_DELETE(p);
	//cObject_Map_Vec.clear();
	
}

void cLoadingScene::Update()
{
	SAFE_UPDATE(m_pUIRoot);
}

void cLoadingScene::Render()
{
	m_pUIRoot->Render(m_pSprite);
}
