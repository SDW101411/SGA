#pragma once
#include "cScene.h"

class cMapTool;

class cMapToolTestScene : public cScene
{
private:
	cMapTool*			m_pMapTool;
	vector<D3DXVECTOR3> m_ground;
	ID3DXMesh*			m_pPickingArea;
	D3DMATERIAL9		m_material;
	D3DXMATRIX			m_matWorld;
public:
	cMapToolTestScene();
	virtual ~cMapToolTestScene();
	virtual void Update();
	virtual void Render();

	void SetupPickingArea();
	void RenderPickingArea();
};