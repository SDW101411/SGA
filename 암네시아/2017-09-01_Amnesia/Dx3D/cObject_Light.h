#pragma once
class cObject_Light
{
public:
	D3DXVECTOR3			m_Pos;
	bool				m_Fire_On;
private:
	Mesh_Manager_Tag*	cObject;
	LPD3DXEFFECT		m_Normal_Effect;
	float				m_ScaleX, m_ScaleY, m_ScaleZ;
	float				m_AngleX, m_AngleY, m_AngleZ;
	cObject_Light*		ItMe;
public:
	cObject_Light();
	cObject_Light(cMesh_Object_Tag Name, D3DXVECTOR3 Pos, D3DXVECTOR3 Rotate, D3DXVECTOR3 Scare);
	~cObject_Light();

	void Update();
	void Render();
	D3DXMATRIX WorldReturn();
	void AnotherRander_1_4Light_Version();
	void AnotherRander();
	void SetFire(bool Save);
};

