#include "stdafx.h"
#include "cAStarScene.h"
#include "cAStar.h"
#include "cMapLoader.h"
#include "cGridNode.h"
#include "cRay.h"
#include "cMonster.h"
#include "cAStarBtn.h"
#include "cSkinnedMesh.h"

cAStarScene::cAStarScene()
{
	cAStarBtn* pBtn = new cAStarBtn;
	m_pIUI = pBtn;
	m_pMesh = new cSkinnedMesh("Monster/", "idle.X");
}

cAStarScene::~cAStarScene()
{
	SAFE_DELETE(m_pIUI);
	SAFE_DELETE(m_pMesh);
}

void cAStarScene::Setup()
{
	m_pMonster = new cMonster();
	m_pMonster->SetPlayerPos(&m_pos);
	cMapLoader loader;
	m_surface = loader.LoadToGroundSurface();
	m_pos = loader.LoadToPlayerPosition();
	m_pMesh->SetPosition(D3DXVECTOR3(0, 0, 0));
}

void cAStarScene::Release()
{
	SAFE_DELETE(m_pMonster);
}

void cAStarScene::Update()
{
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) m_pos.x -= 0.05f;
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) m_pos.x += 0.05f;
	if (KEYMANAGER->isStayKeyDown(VK_UP)) m_pos.z += 0.05f;
	if (KEYMANAGER->isStayKeyDown(VK_DOWN)) m_pos.z -= 0.05f;
	SAFE_UPDATE(m_pMonster);
	SAFE_UPDATE(m_pIUI);
}

void cAStarScene::Render()
{
	SAFE_RENDER(g_pASTAR);
	SAFE_RENDER(m_pMonster);
	SAFE_RENDER(m_pIUI);
	D3DXMATRIX tran;
	D3DXMatrixTranslation(&tran, m_pos.x, m_pos.y, m_pos.z);
	if (m_pMesh) m_pMesh->UpdateAndRender(tran);
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