#pragma once
class c_Gaussian
{
protected:
	vector<ST_RHWT_VERTEX>	m_vecVertex;
	LPD3DXEFFECT			m_pEffect;
	LPDIRECT3DTEXTURE9		m_pTempRenderTarget;
	LPDIRECT3DSURFACE9		m_pTempDepthStencil;
public:
	c_Gaussian();
	~c_Gaussian();

public:
	float ComputeGaussianValue(float x, float mean, float std_deviation);

public:
	void c_Gaussian_setup();
	void Render_Start(LPDIRECT3DSURFACE9 & pHWBackBuffer, LPDIRECT3DSURFACE9 & pHWDepthStencilBuffer, LPDIRECT3DSURFACE9 & pTempSurface);
	
	void Render_End(LPDIRECT3DSURFACE9 & pHWBackBuffer, LPDIRECT3DSURFACE9 & pHWDepthStencilBuffer, LPDIRECT3DSURFACE9 &pTempSurface);
};

