#include "stdafx.h"
#include "cAStarScene.h"
#include "cAStar.h"
#include "cMapLoader.h"
#include "cGridNode.h"
#include "cRay.h"
#include "cMonster.h"
#include "cAStarBtn.h"

cAStarScene::cAStarScene()
	: m_pAStar(NULL)
{
	cAStarBtn* pBtn = new cAStarBtn;
	m_pIUI = pBtn;
}

cAStarScene::~cAStarScene()
{
	SAFE_DELETE(m_pIUI);
}

void cAStarScene::Setup()
{
	m_pMonster = new cMonster();
	m_pAStar = new cAStar();
	cMapLoader loader;
	m_surface = loader.LoadToGroundSurface();
	m_isSafe = false;
}

void cAStarScene::Release()
{
	SAFE_DELETE(m_pAStar);
	SAFE_DELETE(m_pMonster);
}

void cAStarScene::Update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
	{
		if (FindPickingPosition(m_pos, m_surface))
		{
			m_isSafe = true;
		}
		else m_isSafe = false;
	}
	if (KEYMANAGER->isOnceKeyDown('1'))
	{
		D3DXVECTOR3 pos;
		if (FindPickingPosition(pos, m_surface) && m_isSafe)
		{
			m_pAStar->FindPath(m_pos, pos);
			m_isSafe = false;
		}
	}
	SAFE_UPDATE(m_pMonster);
	SAFE_UPDATE(m_pIUI);
}

void cAStarScene::Render()
{
	SAFE_RENDER(m_pAStar);
	SAFE_RENDER(m_pMonster);
	SAFE_RENDER(m_pIUI);
}

bool cAStarScene::FindPickingPosition(OUT D3DXVECTOR3& pos, vector<D3DXVECTOR3> ground)
{
	cRay ray = cRay::RayAtWorldSpace(_ptMousePos.x, _ptMousePos.y);
	float dist = 0;
	float nearDist = -1;
	for (size_t i = 0; i < ground.size(); i += 3)
	{
		if (D3DXIntersectTri(&ground[i], &ground[i + 1], &ground[i + 2], &ray.GetRayOrg(), &ray.GetRayDir(), NULL, NULL, &dist))
		{
			if (nearDist < 0) nearDist = dist;
			else if (dist < nearDist) nearDist = dist;
		}
	}

	if (nearDist < 0) return false;

	pos = ray.GetRayOrg() + ray.GetRayDir() * nearDist;

	return true;
}