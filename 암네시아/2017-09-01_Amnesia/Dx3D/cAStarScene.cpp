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
}

void cAStarScene::Render()
{
	SAFE_RENDER(m_pAStar);
}
