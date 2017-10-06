#pragma once
class cSkinnedMesh;
class cPlayer_Ctrl;
class cObject_Light;
class cScene;
class cScene_Shader_Scene_Test;
class ST_BONE;

struct Lantern
{
	D3DXMATRIXA16				World;
	Mesh_Manager_Tag*			cObject;
	LPD3DXEFFECT				m_Normal_Effect;
	float x, y, z, k, l;
};

enum cPlayer_Animation_Index
{
	//스킨드 메시 종류
	cPlayer_Animation_HAND = 0,
	cPlayer_Animation_HAND_UP = 1,
	cPlayer_Animation_HAND_STAY = 2,
	cPlayer_Animation_HAND_DOWN = 3
};

class cPlayer
{
	typedef vector<cSkinnedMesh*> cSkineed_Mesh_Vec;
	typedef vector<cObject_Light*> cLight_Vec;
private:
	cSkinnedMesh*					m_PTarget_Mesh;
	cSkineed_Mesh_Vec				m_pPlayer_animation_Vec;
	cPlayer_Ctrl*					m_pPlayerCtrl;

	cPlayer_Animation_Index			m_pPlayer_Animation_Index;
	float Save_ANI;

	void*							m_Light_Vector;


	vector<cObject_Light*>			m_Light_Vec;
	cLight_Vec						*m_Light_Vec_f;
	vector<D3DXMATRIXA16*>			m_Mat_vec;
	vector<ST_BONE*>				m_Mat_vec2;

	cSkinnedMesh*					m_PTarget_Test;

	cScene_Shader_Scene_Test		*m_pMy_Scene;


	Mesh_Manager_Tag*				cObject;

	cSkinnedMesh*					m_pLantern;

	float x, y, z, k, l;


	Lantern							m_Lantern;
public:
	cPlayer();
	cPlayer(vector<cObject_Light*>* Light_Object);
	cPlayer(void * Light_Object);
	cPlayer(cScene * Save);
	~cPlayer();

public:
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void Animation_Change();
	void Animation_Change_Set(cPlayer_Animation_Index Set_Type);
	void Animation_Change_Set(cPlayer_Animation_Index Set_Type, float *SaveTarget);

public:
	void set_m_Light_Vector(void* Vector);

	void cLight_Object_Picking_Update();
	void cObject_Item_OutLine_Update();
	void cFind_Hand(cSkinnedMesh * Insert, D3DXMATRIXA16 * out);
private:
	
	void Return_Name(ST_BONE* Insert,LPSTR NAME, D3DXMATRIXA16 **Out);
	void Return_Name(ST_BONE * Insert, LPSTR NAME, ST_BONE ** Out);

private:
	void Lantern_Rander();

};

