#pragma once
class cSkinnedMesh;
class cPlayer_Ctrl;

class cPlayer
{
	typedef vector<cSkinnedMesh*> cSkineed_Mesh_Vec;
private:
	cSkinnedMesh*			m_PTarget_Mesh;
	cSkineed_Mesh_Vec		m_pPlayer_animation;
	cPlayer_Ctrl*			m_pPlayerCtrl;
	

public:
	cPlayer();
	~cPlayer();

public:
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

