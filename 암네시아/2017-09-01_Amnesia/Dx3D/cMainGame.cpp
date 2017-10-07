#include "StdAfx.h"
#include "cMainGame.h"
#include "cCamera.h"
#include "cGrid.h"
#include "cCrtCtrl.h"
#include "cMain_admin.h"
#include "c_Gaussian.h"

cMainGame::cMainGame(void)
	: m_pGrid(NULL)
	, m_pCamera(NULL)
	, m_pCrtCtrl(NULL)
{
	SOUNDMANAGER->init();
}

cMainGame::~cMainGame(void)
{
	SAFE_DELETE(m_pGrid);
	SAFE_DELETE(m_pCamera);
	SAFE_DELETE(m_pCrtCtrl);
	SAFE_DELETE(m_pMain_admin);
	g_pSceneManager->Destroy(); 
	cMESH_MANAGER->Destroy();
	g_pFontManager->Destroy();
	g_pObjectPool->Destroy();
	g_pTextureManager->Destroy();
	g_pSkinnedMeshManager->Destroy();
	g_pDeviceManager->Destroy();
}

void cMainGame::Setup()
{

	m_pCrtCtrl = new cCrtCtrl;
	m_pCamera = new cCamera;
	m_pCamera->Setup(m_pCrtCtrl->GetPosition());


	m_pGrid = new cGrid;
	m_pGrid->Setup(100,1.0f);
	
	m_pMain_admin = new cMain_admin;

	
	m_pGaussian = new c_Gaussian();
	m_pGaussian->c_Gaussian_setup();
	SetLight();
}

void cMainGame::Update()
{
	g_pTimeManager->Update();
	SOUNDMANAGER->update();

	SAFE_UPDATE(m_pCrtCtrl);
	cLight_Seting = *m_pCrtCtrl->GetPosition();
	SAFE_UPDATE(m_pCamera);
	cCameara_seting = *m_pCamera->get_pvPostion();
	SAFE_UPDATE(m_pMain_admin);

	g_pAutoReleasePool->Drain();
}

void cMainGame::Render()
{
	/*g_pD3DDevice->BeginScene();

	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(100, 100, 100),
		1.0f, 0);*/
	LPDIRECT3DSURFACE9 pHWBackBuffer;
	LPDIRECT3DSURFACE9 pHWDepthStencilBuffer;
	LPDIRECT3DSURFACE9 pTempSurface;
	m_pGaussian->Render_Start(pHWBackBuffer, pHWDepthStencilBuffer, pTempSurface);


	SAFE_RENDER(m_pGrid);
	SAFE_RENDER(m_pMain_admin);

	m_pGaussian->Render_End(pHWBackBuffer, pHWDepthStencilBuffer, pTempSurface);
	g_pTimeManager->Render();
	if (m_pMain_admin)m_pMain_admin->Render_UI_Render();

	g_pD3DDevice->EndScene();

	g_pD3DDevice->Present(NULL, NULL, NULL, NULL);

	SAFE_RELEASE(pTempSurface);
	SAFE_RELEASE(pHWBackBuffer);
	SAFE_RELEASE(pHWDepthStencilBuffer);
}


void cMainGame::MsgProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam )
{
	if (m_pCamera)
	{
		m_pCamera->MsgProc(hWnd, message, wParam, lParam);
	}
	switch (message)
	{
	case WM_LBUTTONDOWN:
		{
		}
		break;
	case WM_KEYDOWN:
		switch(wParam) 
		{
		case VK_SPACE:
			{
				//static int n = 0;
				//m_pSkinnedMesh->SetAnimationIndex(++n);
			}
			break;
		case VK_ESCAPE:	//esc키로 종료한다
			PostMessage(hWnd, WM_DESTROY, 0, 0);
			break;
		}
		break;
	case WM_DESTROY:	//종료 메시지
		PostQuitMessage(0);
		//return 0;
		break;
	}
	if (m_pMain_admin)
		m_pMain_admin->MsgProc(hWnd, message, wParam, lParam);
}

void cMainGame::SetLight()
{
	D3DLIGHT9 stLight;
	ZeroMemory(&stLight, sizeof(D3DLIGHT9));
	stLight.Type = D3DLIGHT_DIRECTIONAL;
	D3DXVECTOR3 vDir( 1,-1, 1);
	D3DXVec3Normalize(&vDir, &vDir);
	stLight.Direction = vDir;
	stLight.Ambient = stLight.Diffuse = stLight.Specular = D3DXCOLOR(0.75f, 0.75f, 0.75f, 1.0f);
	g_pD3DDevice->SetLight(0, &stLight);
	g_pD3DDevice->LightEnable(0, true);
}

void cMainGame::OnMouse(cUIButton* pSender)
{
}


void cMainGame::OnClick( cUIButton* pSender )
{
}

void cMainGame::OnRightClick(cUIButton* pSender)
{
}

