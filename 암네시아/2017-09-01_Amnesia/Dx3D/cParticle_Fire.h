#pragma once
#include "cParticle.h"
class cParticle_Fire : public cParticle
{
public:
	vector<Particle_Data> m_Particle_Smoke_Vec;
public:
	cParticle_Fire();
	~cParticle_Fire();
	void Update();
	void Render();
private:
	void Seting_Fire_Ver();
	void Seting_Smoke_Ver();
};

