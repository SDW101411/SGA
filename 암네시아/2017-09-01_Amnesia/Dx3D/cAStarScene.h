#pragma once
#include "cScene.h"

class cGridNode;
class cMonster;
class cSkinnedMesh;

class cAStarScene : public cScene
{
private:
	cMonster*	m_pMonster;
	vector<D3DXVECTOR3> m_surface;
	vector<D3DXVECTOR3> m_wallSurface;

	D3DXVECTOR3 m_pos;
	cSkinnedMesh* m_pMesh;

public:
	cAStarScene();
	virtual ~cAStarScene();

	virtual void Setup();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	bool FindPickingPosition(OUT D3DXVECTOR3& pos, vector<D3DXVECTOR3> ground);
};