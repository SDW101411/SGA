#pragma once

class cSkinnedMesh;
class cStateMachine;
class cMonAnimCtrl;

class cMonster
{
private:
	D3DXMATRIX		m_matWorld;
	cStateMachine*	m_pMachine;
	cMonAnimCtrl*	m_pMonAnim;
private:
	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);
	SYNTHESIZE(float, m_angle, Angle);

public:
	cMonster();
	~cMonster();

	void Update();
	void Render();

	void SetAnim(int tag);
};