#pragma once

class cObject_Light;

class cObject_Map
{
private:
	Mesh_Manager_Tag*		cObject;
	LPD3DXEFFECT			m_Normal_Effect;
	SYNTHESIZE(D3DXVECTOR3, m_Pos, Position);
	float					m_ScaleX, m_ScaleY, m_ScaleZ;
	float					m_AngleX, m_AngleY, m_AngleZ;
	vector<cObject_Light*>	m_Light_vec;
public:
	cObject_Map();
	cObject_Map(cMesh_Object_Tag Name,D3DXVECTOR3 Pos, D3DXVECTOR3 Rotate, D3DXVECTOR3 Scare);
	~cObject_Map();
	void Update();
	void Render();
	void m_Light_Vec_Push(cObject_Light* save_Target);
private:
	D3DXMATRIX WorldReturn();
	void AnotherRander_1();
	void AnotherRander_1_4Light_Version();
	void AnotherRander_2();
};

