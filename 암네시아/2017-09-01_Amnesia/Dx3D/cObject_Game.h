#pragma once
class cObject_Game
{
public:
	D3DXVECTOR3			m_Pos;
	float				m_ScaleX, m_ScaleY, m_ScaleZ;
	float				m_AngleX, m_AngleY, m_AngleZ;
	LPDIRECT3DTEXTURE9	m_Texture;
	LPDIRECT3DTEXTURE9	m_Normal;
	LPDIRECT3DTEXTURE9	m_Specqural;
	LPD3DXMESH			m_Mesh;
	LPD3DXEFFECT		m_Efffect;

	LPDIRECT3DTEXTURE9		gpShadowRenderTarget;
	LPDIRECT3DSURFACE9		m_pShadowDepthStencil;
	
	//LPDIRECT3DSURFACE9 pHWBackBuffer = NULL;
	//LPDIRECT3DSURFACE9 pHWDepthStencilBuffer = NULL;
	//LPDIRECT3DSURFACE9 pShadowSurface = NULL;

public:
	cObject_Game();
	virtual ~cObject_Game();

public:
	virtual void Update();
	virtual void Render();

public:
	void SetPos(D3DXVECTOR3 Save);
	void SetScale(float x, float y, float z);
	void SetAngle(float x, float y, float z);
	void Set_Anit1hing(D3DXVECTOR3 Save, float Ax, float Ay, float Az, float Sx, float Sy, float Sz);
	void Set_Anit1hing_Test(D3DXVECTOR3 Save, float Ax, float Ay, float Az, float Sx, float Sy, float Sz);
	D3DXMATRIX WorldReturn();
	void AnotherRander();

	void Shadow_Render();

public:
	LPDIRECT3DTEXTURE9 LoadTexture(const char * filename);
	LPD3DXMESH LoadModel(const char * filename);
	LPD3DXEFFECT LoadShader(const char * filename);
};

