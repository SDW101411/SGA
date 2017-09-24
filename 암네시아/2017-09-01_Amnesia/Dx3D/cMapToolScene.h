#pragma once
#include "cScene.h"

class cMapTool;

enum MAPTOOL_STATE
{
	MAPTOOL_STATE_DRAW_GRID,
	MAPTOOL_STATE_DRAW_CUBE,
	MAPTOOL_STATE_DELETE_MESH,
};

class cMapToolScene : public cScene
{
private:
	int m_state;

	cMapTool*			m_pMapTool;
	vector<D3DXVECTOR3> m_ground;
	ID3DXMesh*			m_pPickingArea;
	D3DMATERIAL9		m_material;
	D3DXMATRIX			m_matWorld;
	D3DXVECTOR3			m_curRotation;
	D3DXVECTOR3			m_curScale;
	D3DXVECTOR3			m_curWallPos;
public:
	cMapToolScene();
	virtual ~cMapToolScene();
	virtual void Update();
	virtual void Render();

	void SetupPickingArea();
	void RenderPickingArea();
};