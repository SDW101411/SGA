#pragma once

class cParticle;
class cObject_Light
{
public:
	D3DXVECTOR3			m_Pos;
	D3DXVECTOR3			m_lightPos;
	D3DXVECTOR3			m_lightPos_Light;


	D3DXVECTOR3			m_LightPosition;
	D3DXVECTOR3			m_ParticlePosition;
	bool				m_Fire_On;
private:
	Mesh_Manager_Tag*	cObject;
	LPD3DXEFFECT		m_Normal_Effect;
	float				m_ScaleX, m_ScaleY, m_ScaleZ;
	float				m_AngleX, m_AngleY, m_AngleZ;
	cObject_Light*		ItMe;

	cParticle*			m_pParticle_Fire;
public:
	cObject_Light();
	cObject_Light(cMesh_Object_Tag Name, D3DXVECTOR3 Pos, D3DXVECTOR3 Rotate, D3DXVECTOR3 Scare, D3DXVECTOR3 lightPos);
	cObject_Light(cMesh_Object_Tag Name, D3DXVECTOR3 Pos, D3DXVECTOR3 Rotate, D3DXVECTOR3 Scare, D3DXVECTOR3 particle_position, D3DXVECTOR3 Light_Position);
	~cObject_Light();

	void Update();
	void Render();
	D3DXMATRIX WorldReturn();
	void AnotherRander_1_4Light_Version();
	void AnotherRander();
	void SetFire(bool Save);
};

