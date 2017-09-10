#pragma once
class cSkinnedMesh;
class cPlayer
{
private:
	cSkinnedMesh			*m_PTarget_Mesh;
	vector<cSkinnedMesh*>	m_pPlayer_animation;
	D3DXVECTOR3* m_pPlayerCameara;
	D3DXVECTOR3*  m_pPlayerPos;

public:
	cPlayer();
	~cPlayer();

public:
	void Update();
	void Render();
};

