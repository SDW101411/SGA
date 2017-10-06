#pragma once
#include "cScene.h"

class cGridNode;
class cAStar;
class cMonster;

class cAStarScene : public cScene
{
private:
	cMonster*	m_pMonster;
	cAStar*		m_pAStar;
	vector<D3DXVECTOR3> m_surface;
	D3DXVECTOR3 m_pos;
	bool		m_isSafe;

public:
	cAStarScene();
	virtual ~cAStarScene();

	virtual void Setup();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	bool FindPickingPosition(OUT D3DXVECTOR3& pos, vector<D3DXVECTOR3> ground);
};