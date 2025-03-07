#include "stdafx.h"
#include "c_Gaussian.h"


c_Gaussian::c_Gaussian()
{
}


c_Gaussian::~c_Gaussian()
{
}

float c_Gaussian::ComputeGaussianValue(float x, float mean, float std_deviation)
{
	return (1.0f / sqrt(2.0f * D3DX_PI * std_deviation * std_deviation))
		* expf((-((x - mean) * (x - mean))) / (2.0f * std_deviation * std_deviation));
}

void c_Gaussian::c_Gaussian_setup()
{
	// 렌더타깃을 만든다.
	RECT rc;
	GetClientRect(g_hWnd, &rc);

	g_pD3DDevice->CreateTexture(
		rc.right,
		rc.bottom,
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&m_pTempRenderTarget,
		NULL);

	// 그림자 맵과 동일한 크기의 깊이버퍼도 만들어줘야 한다.
	g_pD3DDevice->CreateDepthStencilSurface(
		rc.right,
		rc.bottom,
		D3DFMT_D24S8,
		D3DMULTISAMPLE_NONE,
		0,
		TRUE,
		&m_pTempDepthStencil,
		NULL);

	g_pD3DDevice->CreateTexture(
		rc.right,
		rc.bottom,
		1,
		D3DUSAGE_RENDERTARGET,
		D3DFMT_A8R8G8B8,
		D3DPOOL_DEFAULT,
		&m_pTempRenderTarget_Wave,
		NULL);

	// 그림자 맵과 동일한 크기의 깊이버퍼도 만들어줘야 한다.
	g_pD3DDevice->CreateDepthStencilSurface(
		rc.right,
		rc.bottom,
		D3DFMT_D24S8,
		D3DMULTISAMPLE_NONE,
		0,
		TRUE,
		&m_pTempDepthStencil_Wave,
		NULL);

	m_pEffect = cUtil::LoadEffect("Test/blur.fx");

	m_vecVertex.resize(6);
	m_vecVertex[0].p = D3DXVECTOR4(0, 0, 0, 1);
	m_vecVertex[0].t = D3DXVECTOR2(0, 0);

	m_vecVertex[1].p = D3DXVECTOR4(rc.right, 0, 0, 1);
	m_vecVertex[1].t = D3DXVECTOR2(1, 0);

	m_vecVertex[2].p = D3DXVECTOR4(rc.right, rc.bottom, 0, 1);
	m_vecVertex[2].t = D3DXVECTOR2(1, 1);

	m_vecVertex[3].p = D3DXVECTOR4(0, 0, 0, 1);
	m_vecVertex[3].t = D3DXVECTOR2(0, 0);

	m_vecVertex[4].p = D3DXVECTOR4(rc.right, rc.bottom, 0, 1);
	m_vecVertex[4].t = D3DXVECTOR2(1, 1);

	m_vecVertex[5].p = D3DXVECTOR4(0, rc.bottom, 0, 1);
	m_vecVertex[5].t = D3DXVECTOR2(0, 1);



	m_pEffect_Wave = cUtil::LoadEffect("Test/Wave.fx");

	m_vecVertex_Wave.resize(6);
	m_vecVertex_Wave[0].p = D3DXVECTOR4(0, 0, 0, 1);
	m_vecVertex_Wave[0].t = D3DXVECTOR2(0, 0);

	m_vecVertex_Wave[1].p = D3DXVECTOR4(rc.right, 0, 0, 1);
	m_vecVertex_Wave[1].t = D3DXVECTOR2(1, 0);

	m_vecVertex_Wave[2].p = D3DXVECTOR4(rc.right, rc.bottom, 0, 1);
	m_vecVertex_Wave[2].t = D3DXVECTOR2(1, 1);

	m_vecVertex_Wave[3].p = D3DXVECTOR4(0, 0, 0, 1);
	m_vecVertex_Wave[3].t = D3DXVECTOR2(0, 0);

	m_vecVertex_Wave[4].p = D3DXVECTOR4(rc.right, rc.bottom, 0, 1);
	m_vecVertex_Wave[4].t = D3DXVECTOR2(1, 1);

	m_vecVertex_Wave[5].p = D3DXVECTOR4(0, rc.bottom, 0, 1);
	m_vecVertex_Wave[5].t = D3DXVECTOR2(0, 1);

	g_pD3DDevice->SetRenderState(D3DRS_NORMALIZENORMALS, true);
}

void c_Gaussian::Render_Start(LPDIRECT3DSURFACE9 &pHWBackBuffer, LPDIRECT3DSURFACE9 &pHWDepthStencilBuffer, LPDIRECT3DSURFACE9 &pTempSurface)
{
	g_pD3DDevice->BeginScene();

	// 현재 하드웨어 벡버퍼와 깊이버퍼
	pHWBackBuffer = NULL;
	pHWDepthStencilBuffer = NULL;

	g_pD3DDevice->GetRenderTarget(0, &pHWBackBuffer);
	g_pD3DDevice->GetDepthStencilSurface(&pHWDepthStencilBuffer);

	pTempSurface = NULL;
	m_pTempRenderTarget->GetSurfaceLevel(0, &pTempSurface);

	g_pD3DDevice->SetRenderTarget(0, pTempSurface);
	g_pD3DDevice->SetDepthStencilSurface(m_pTempDepthStencil);

	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(10, 10, 10),
		1.0f, 0);

}

void c_Gaussian::Render_End(LPDIRECT3DSURFACE9 &pHWBackBuffer, LPDIRECT3DSURFACE9 &pHWDepthStencilBuffer, LPDIRECT3DSURFACE9 &pTempSurface,
	LPDIRECT3DSURFACE9 & pHWBackBuffer_2, LPDIRECT3DSURFACE9 & pHWDepthStencilBuffer_2, LPDIRECT3DSURFACE9 &pTempSurface_2)
{
	pTempSurface_2 = NULL;

	m_pTempRenderTarget_Wave->GetSurfaceLevel(0, &pTempSurface_2);


	// 하드웨어 백버퍼/깊이버퍼를 사용한다.
	g_pD3DDevice->SetRenderTarget(0, pTempSurface_2);
	g_pD3DDevice->SetDepthStencilSurface(m_pTempDepthStencil_Wave);

	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(255, 0, 0),
		1.0f, 0);

	D3DSURFACE_DESC destDesc;
	pTempSurface->GetDesc(&destDesc);


	float VBloomWeights[9];
	float VBloomOffsets[9];

	for (int i = 0; i < 9; i++)
	{
		VBloomOffsets[i] = (static_cast< float >(i) - 4.0f) * (1.0f / static_cast< float >(destDesc.Height));
		float x = (static_cast< float >(i) - 4.0f) / 4.0f;

		VBloomWeights[i] = 0.4f * ComputeGaussianValue(x, 0.0f, 0.8f);
	}

	// Commit both arrays to the device:
	m_pEffect->SetFloatArray("VBloomWeights", VBloomWeights, 9);
	m_pEffect->SetFloatArray("VBloomOffsets", VBloomOffsets, 9);


	// Configure the sampling offsets and their weights
	float HBloomWeights[9];
	float HBloomOffsets[9];

	for (int i = 0; i < 9; i++)
	{
		HBloomOffsets[i] = (static_cast< float >(i) - 4.0f) * (1.0f / static_cast< float >(destDesc.Width));

		float x = (static_cast< float >(i) - 4.0f) / 4.0f;

		HBloomWeights[i] = 0.4f * ComputeGaussianValue(x, 0.0f, 0.8f);
	}

	// Commit both arrays to the device:
	m_pEffect->SetFloatArray("HBloomWeights", HBloomWeights, 9);
	m_pEffect->SetFloatArray("HBloomOffsets", HBloomOffsets, 9);

	m_pEffect->SetTexture("TempRenderTargetTexture", m_pTempRenderTarget);

	UINT uiPasses = 0;
	m_pEffect->Begin(&uiPasses, 0);
	for (UINT i = 0; i < uiPasses; ++i)
	{
		m_pEffect->BeginPass(i);

		g_pD3DDevice->SetTexture(0, m_pTempRenderTarget);
		g_pD3DDevice->SetFVF(ST_RHWT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
			m_vecVertex.size() / 3,
			&m_vecVertex[0],
			sizeof(ST_RHWT_VERTEX));

		m_pEffect->EndPass();
	}

	m_pEffect->End();



	g_pD3DDevice->SetRenderTarget(0, pHWBackBuffer);
	g_pD3DDevice->SetDepthStencilSurface(pHWDepthStencilBuffer);

	g_pD3DDevice->Clear(NULL,
		NULL,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(0, 0, 0),
		1.0f, 0);

	m_pEffect_Wave->SetTexture("Earth_Tex", m_pTempRenderTarget_Wave);

	m_pEffect_Wave->SetFloat("Move_Legth", Wave_float);

	m_pEffect_Wave->SetFloat("fCosTime", GetTickCount64() * 0.001f);
	

	 uiPasses = 0;
	m_pEffect_Wave->Begin(&uiPasses, 0);
	for (UINT i = 0; i < uiPasses; ++i)
	{
		m_pEffect_Wave->BeginPass(i);

		g_pD3DDevice->SetTexture(0, m_pTempRenderTarget_Wave);
		g_pD3DDevice->SetFVF(ST_RHWT_VERTEX::FVF);
		g_pD3DDevice->DrawPrimitiveUP(D3DPT_TRIANGLELIST,
			m_vecVertex.size() / 3,
			&m_vecVertex[0],
			sizeof(ST_RHWT_VERTEX));

		m_pEffect_Wave->EndPass();
	}

	m_pEffect_Wave->End();
	
}
