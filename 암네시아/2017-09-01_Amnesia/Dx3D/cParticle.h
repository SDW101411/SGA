#pragma once

class cParticle
{
public:
	vector<Particle_Data> m_Particle_Vec;
	//Particle_Data m_Particle_Data;
public:
	DWORD FtoDw(float f);
	cParticle();
	virtual ~cParticle();
	virtual void Update();
	virtual void Render();
};

