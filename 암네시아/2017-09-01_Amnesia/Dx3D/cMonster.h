#pragma once

class cSkinnedMesh;
class cStateMachine;

class cMonster
{
private:
	D3DXMATRIX		m_matWorld;
	cSkinnedMesh*	m_pMesh;
	cStateMachine*	m_pMachine;
private:
	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);
	SYNTHESIZE(float, m_angle, Angle);

public:
	cMonster();
	~cMonster();

	void Update();
	void Render();
};