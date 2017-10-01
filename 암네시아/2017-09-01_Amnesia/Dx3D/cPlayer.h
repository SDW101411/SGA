#pragma once
class cSkinnedMesh;
class cPlayer_Ctrl;

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
private:
	cSkinnedMesh*					m_PTarget_Mesh;
	cSkineed_Mesh_Vec				m_pPlayer_animation_Vec;
	cPlayer_Ctrl*					m_pPlayerCtrl;

	cPlayer_Animation_Index			m_pPlayer_Animation_Index;
	float Save_ANI;

	void*							m_Light_Vector;

public:
	cPlayer();
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
};

