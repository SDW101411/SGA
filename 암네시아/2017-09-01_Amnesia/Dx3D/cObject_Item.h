#pragma once
class cObject_Item
{
public:
	D3DXVECTOR3						m_Pos;
	LPD3DXEFFECT					m_Normal_Effect;
	float							m_ScaleX, m_ScaleY, m_ScaleZ;
	float							m_AngleX, m_AngleY, m_AngleZ;
	bool							m_OutLine_On;
	Mesh_Manager_Tag*				cObject;
	vector<cObject_Light*>			m_Light_vec;
	cMesh_Object_Tag				Item_Tag;
	bool							m_Render_On;
	//cMesh_Object_Tag			Item_Tag;
public:
	cObject_Item();
	cObject_Item(cMesh_Object_Tag Name, D3DXVECTOR3 Pos, D3DXVECTOR3 Rotate, D3DXVECTOR3 Scare);
	~cObject_Item();


	void Update();
	void Render();
	D3DXMATRIX WorldReturn();
	void AnotherRander_1_4Light_Version_Out_Line();
	void AnotherRander();
};

