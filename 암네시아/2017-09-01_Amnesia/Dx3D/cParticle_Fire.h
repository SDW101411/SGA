#pragma once
#include "cParticle.h"
class cParticle_Fire : public cParticle
{
public:
	vector<Particle_Data>	m_Particle_Smoke_Vec;
	D3DXVECTOR3*			pos_xyz;
	Particle_Data			m_Light;
public:
	cParticle_Fire();
	cParticle_Fire(D3DXVECTOR3 * Target);
	~cParticle_Fire();
	void Update();
	void Render();
	void Fire_Start_OnOff();
private:
	void Seting_Fire_Ver();
	void Seting_Smoke_Ver();
	void Seting_Fire_Ver_2();
	void Seting_Smoke_Ver_2();
};

