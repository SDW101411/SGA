#pragma once
#include "cMonAnimCtrl.h"
#include "cStateMachine.h"

//#define MON_MOVESPEED 0.006f
#define MON_MOVESPEED 0.018f

class cSkinnedMesh;

class cMonster
{
protected:
	D3DXMATRIX			m_matWorld;
	cStateMachine*		m_pMachine;
	cMonAnimCtrl*		m_pMonAnim;
	D3DXVECTOR3*		m_pPlayerPos;
	list<D3DXVECTOR3>	m_route;
	vector<D3DXVECTOR3> m_wallSurface;

protected:
	SYNTHESIZE(D3DXVECTOR3, m_dir, Direction);
	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);
	SYNTHESIZE(float, m_angle, Angle);
	SYNTHESIZE(bool, m_move, Move);

public:
	cMonster();
	~cMonster();

	void Update();
	void Render();

	void SetAnim(MON_ANIM tag);
	void SetRoute(list<D3DXVECTOR3> route);
	void SetState(MONSTER_STATE state);
	void MoveRoute(float speed);

	bool IsMeetPlayer();
	bool IsPlayerAtNear();

	inline int GetRouteSize() { return m_route.size(); }

	inline D3DXVECTOR3 GetPlayerPos() { return *m_pPlayerPos; }
	inline void SetPlayerPos(D3DXVECTOR3* pos) { m_pPlayerPos = pos; }
	inline float GetAnimationTime() { return m_pMonAnim->GetAnimationTime(); }

protected:
	float GetDistance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
	float GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
};