#pragma once

class cMapMesh
{
private:
	LPD3DXMESH			m_pMesh;
	LPDIRECT3DTEXTURE9	m_pTexture;
public:
	cMapMesh();
	~cMapMesh();

	void Setup(int tag);
	void Render(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl);
private:
	LPD3DXMESH LoadMesh(string fileName);
	LPDIRECT3DTEXTURE9 LoadTexture(string fileName);
};