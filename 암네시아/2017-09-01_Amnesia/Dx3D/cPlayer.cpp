#include "stdafx.h"
#include "cPlayer.h"
#include "cSkinnedMesh.h"


cPlayer::cPlayer()
{
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands.X"));
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_draw.X"));
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_holster.X"));
	m_pPlayer_animation.push_back(new cSkinnedMesh("cPlayer_Hand_X_file/", "hands_lantern_idle.X"));

	m_PTarget_Mesh = m_pPlayer_animation[0];
}


cPlayer::~cPlayer()
{
	for each(auto p in m_pPlayer_animation)
		SAFE_DELETE(p);
	SAFE_DELETE(m_PTarget_Mesh);
}

void cPlayer::Update()
{
	static int NUMBER = 0;
	if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
	{
		NUMBER++;
		if (NUMBER == 4)
		{
			NUMBER = 0;
		}
		m_PTarget_Mesh = m_pPlayer_animation[NUMBER];
	}
}

void cPlayer::Render()
{
	m_PTarget_Mesh->UpdateAndRender();
}
