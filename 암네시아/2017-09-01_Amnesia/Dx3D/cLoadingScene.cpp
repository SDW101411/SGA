#include "stdafx.h"
#include "cLoadingScene.h"
#include "cMapLoader.h"
#include "cObject_Map.h"
#include "cUIImageView.h"
#include "cUITextView.h"

CRITICAL_SECTION cs;

void cLoadingScene::ThFunc1(LPVOID pParam)
{
	//EnterCriticalSection(&cs);
	cLoadingScene* pLoader = (cLoadingScene*)pParam;
	cMapLoader Loader;
	g_pLoadManager()->SetObject_Map_Vec(Loader.LoadToObject_Map());
	g_pLoadManager()->SetObject_Light_Vec(Loader.LoadToObject_Light());
	pLoader->m_bClear = true;
	//LeaveCriticalSection(&cs);
}

cLoadingScene::cLoadingScene()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	m_bClear = FALSE;
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/menu_gamma.tga");
	pImageView->SetScaling(6.48f, 5.1f);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/menu_loading_screen.jpg");
	pImageView->SetPosition(460, 92);
	pImageView->SetScaling(1.0f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	cUITextView* pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText("불러오는 중..");
	pTextView->SetSize(ST_SIZE(600, 100));
	pTextView->SetPosition(646, 580);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	m_pUIRoot->AddChild(pTextView);
}

cLoadingScene::~cLoadingScene()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cLoadingScene::Setup()
{
	SOUNDMANAGER->play("dan_brute");
	DWORD dwThID;
	InitializeCriticalSection(&cs);
	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)ThFunc1, this, NULL/*CREATE_SUSPENDED*/, &dwThID));
}

void cLoadingScene::Release()
{
	//for each(auto p in cObject_Map_Vec) SAFE_DELETE(p);
	//cObject_Map_Vec.clear();
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
	SOUNDMANAGER->pause("dan_brute");
}

void cLoadingScene::Update()
{
	SAFE_UPDATE(m_pUIRoot);

	if (m_bClear)
	{
		g_pSceneManager->SceneChange("cScene_Shader_Scene_Test");
	}
}

void cLoadingScene::Render()
{
	
}

void cLoadingScene::RenderUI()
{
	if(m_pUIRoot) m_pUIRoot->Render(m_pSprite);
}
