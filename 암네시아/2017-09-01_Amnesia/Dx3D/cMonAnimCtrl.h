#pragma once

class cSkinnedMesh;

enum
{
	MON_ANIM_IDLE,
	MON_ANIM_IDLE_EXTRA,
	MON_ANIM_WALK,
	MON_ANIM_RUN,
	MON_ANIM_ATTACK,
};
typedef int MON_ANIM;

class cMonAnimCtrl
{
protected:
	SYNTHESIZE(D3DXMATRIX, m_matWorld, WorldMatrix);
	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);
	cSkinnedMesh* m_pCurMesh;

	map<MON_ANIM, cSkinnedMesh*> m_meshList;
public:
	cMonAnimCtrl();
	~cMonAnimCtrl();
	void SetAnimation(MON_ANIM tag);

	void Render();
};