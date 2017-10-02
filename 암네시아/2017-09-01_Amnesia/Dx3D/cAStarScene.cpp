#include "stdafx.h"
#include "cAStarScene.h"
#include "cAStar.h"
#include "cGridNode.h"

cAStarScene::cAStarScene()
	: m_pAStar(NULL)
{
}

cAStarScene::~cAStarScene()
{
}

void cAStarScene::Setup()
{
	m_pAStar = new cAStar();
}

void cAStarScene::Release()
{
	SAFE_DELETE(m_pAStar);
}

void cAStarScene::Update()
{
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		m_pAStar->FindPath(D3DXVECTOR3(0, 0, 0), D3DXVECTOR3(5, 0, 0));
	}
}

void cAStarScene::Render()
{
	SAFE_RENDER(m_pAStar);
}
