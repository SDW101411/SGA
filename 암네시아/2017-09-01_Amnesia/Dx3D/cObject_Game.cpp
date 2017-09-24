#include "stdafx.h"
#include "cObject_Game.h"


cObject_Game::cObject_Game()
{
}


cObject_Game::~cObject_Game()
{
}

void cObject_Game::Update()
{
}

void cObject_Game::Render()
{
}

void cObject_Game::SetPos(D3DXVECTOR3 Save)
{
	m_Pos = Save;
}

void cObject_Game::SetScale(float x, float y, float z)
{
	m_ScaleX = x; m_ScaleY = y; m_ScaleZ = z;
}

void cObject_Game::SetAngle(float x, float y, float z)
{
	m_AngleX = x; m_AngleY = y; m_AngleZ = z;
}

void cObject_Game::Set_Anit1hing(D3DXVECTOR3 Save, float Ax, float Ay, float Az, float Sx, float Sy, float Sz)
{
	SetPos(Save);
	SetAngle(Ax,Ay,Az);
	SetScale(Sx,Sy,Sz);
}

void cObject_Game::Set_Anit1hing_Test(D3DXVECTOR3 Save, float Ax, float Ay, float Az, float Sx, float Sy, float Sz)
{
	SetPos(Save);
	SetAngle(Ax, Ay, Az);
	SetScale(Sx, Sy, Sz);
	m_AngleY = (rand() % 700) * 0.01;
}

D3DXMATRIX cObject_Game::WorldReturn()
{
	D3DXMATRIX Worldmat, Transmat, Anglemat, Scalemat;
	D3DXMATRIX xMat, yMat, zMat;
	D3DXMatrixIdentity(&Worldmat);
	D3DXMatrixIdentity(&Transmat);
	D3DXMatrixIdentity(&Anglemat);
	D3DXMatrixIdentity(&Scalemat);
	D3DXMatrixIdentity(&xMat);
	D3DXMatrixIdentity(&yMat);
	D3DXMatrixIdentity(&zMat);
	D3DXMatrixTranslation(&Transmat, m_Pos.x, m_Pos.y, m_Pos.z);
	D3DXMatrixRotationX(&xMat, m_AngleX);
	D3DXMatrixRotationY(&yMat, m_AngleY);
	D3DXMatrixRotationZ(&zMat, m_AngleZ);
	Anglemat = xMat * yMat * zMat;
	D3DXMatrixScaling(&Scalemat, m_ScaleX, m_ScaleY, m_ScaleZ);

	
	return Worldmat = Scalemat * Anglemat * Transmat;
}

void cObject_Game::AnotherRander()
{
	UINT numPasses = 0;
	m_Efffect->Begin(&numPasses, NULL);

	for (UINT i = 0; i < numPasses; ++i)
	{
		m_Efffect->BeginPass(i);

		m_Mesh->DrawSubset(0);

		m_Efffect->EndPass();
	}

	m_Efffect->End();
}

void cObject_Game::Shadow_Render()
{
	UINT numPasses = 0;
	m_Efffect->Begin(&numPasses, NULL);
	{
		m_Efffect->BeginPass(0);
		{
			m_Mesh->DrawSubset(0);
		}
		m_Efffect->EndPass();

		//g_pD3DDevice->SetRenderTarget(0, pHWBackBuffer);
		//g_pD3DDevice->SetDepthStencilSurface(pHWDepthStencilBuffer);

		//SAFE_RELEASE(pHWBackBuffer);
		//SAFE_RELEASE(pHWDepthStencilBuffer);

		m_Efffect->CommitChanges();

		m_Efffect->BeginPass(1);

		m_Mesh->DrawSubset(0);

		m_Efffect->EndPass();
	}
	m_Efffect->End();

}

LPDIRECT3DTEXTURE9 cObject_Game::LoadTexture(const char * filename)
{
	LPDIRECT3DTEXTURE9 ret = NULL;
	if (FAILED(D3DXCreateTextureFromFile(g_pD3DDevice, filename, &ret)))
	{
		OutputDebugString("텍스쳐 파일없다 이자식아 : ");
		OutputDebugString(filename);
		OutputDebugString("\n");
	}

	return ret;
}

LPD3DXMESH cObject_Game::LoadModel(const char * filename)
{
	LPD3DXMESH ret = NULL;
	if (FAILED(D3DXLoadMeshFromX(filename, D3DXMESH_SYSTEMMEM, g_pD3DDevice,
		NULL, NULL, NULL, NULL, &ret)))
	{
		OutputDebugString("메쉬 파일 없다 이자식아: ");
		OutputDebugString(filename);
		OutputDebugString("\n");
	};

	return ret;
}

LPD3DXEFFECT cObject_Game::LoadShader(const char * filename)
{
	LPD3DXEFFECT ret = NULL;
	LPD3DXBUFFER pError = NULL;
	DWORD dwShaderFlags = 0;

#if _DEBUG
	dwShaderFlags |= D3DXSHADER_DEBUG;
#endif

	D3DXCreateEffectFromFile(g_pD3DDevice, filename,
		NULL, NULL, dwShaderFlags, NULL, &ret, &pError);

	// 쉐이더 로딩에 실패한 경우 output창에 쉐이더
	// 컴파일 에러를 출력한다.
	if (!ret && pError)
	{
		int size = pError->GetBufferSize();
		void *ack = pError->GetBufferPointer();

		if (ack)
		{
			char* str = new char[size];
			sprintf(str, (const char*)ack, size);
			OutputDebugString(str);
			delete[] str;
		}
	}

	return ret;
}
