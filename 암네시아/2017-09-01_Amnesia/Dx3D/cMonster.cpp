#include "stdafx.h"
#include "cMonster.h"
#include "cSkinnedMesh.h"
#include "cMapLoader.h"
#include "cRay.h"

cMonster::cMonster()
{
	m_pMonAnim = new cMonAnimCtrl();
	m_pMachine = new cStateMachine(this);
	cMapLoader loader;
	m_pos = loader.LoadToMonsterPosition1();
	m_dir = D3DXVECTOR3(0, 0, 0);
	m_move = false;
	m_wallSurface = loader.LoadToWallSurface();
}

cMonster::~cMonster()
{
	SAFE_DELETE(m_pMachine);
	SAFE_DELETE(m_pMonAnim);
}

void cMonster::Update()
{
	SAFE_UPDATE(m_pMachine);

	D3DXMATRIX scale, rotY, tran;
	D3DXMatrixTranslation(&tran, m_pos.x, m_pos.y, m_pos.z);
	D3DXMatrixScaling(&scale, 2.0f, 2.0f, 2.0f);
	D3DXMatrixRotationY(&rotY, D3DX_PI - m_angle + D3DX_PI * 0.5f);
	m_dir = D3DXVECTOR3(cosf(m_angle) * 1, 0, sinf(m_angle) * 1);
	D3DXVec3Normalize(&m_dir, &m_dir);
	m_matWorld = scale * rotY * tran;
	m_pMonAnim->SetWorldMatrix(m_matWorld);
}

void cMonster::Render()
{
	SAFE_RENDER(m_pMonAnim);
	SAFE_RENDER(m_pMachine);
}

void cMonster::SetAnim(MON_ANIM tag)
{
	m_pMonAnim->SetAnimation(tag);
}

void cMonster::SetRoute(list<D3DXVECTOR3> route)
{
	m_route = route;
}

void cMonster::SetState(MONSTER_STATE state)
{
	m_pMachine->SetState(state);
}

void cMonster::MoveRoute(float speed)
{
	if (!m_move) return;

	if (GetDistance(m_route.front(), m_pos) < 0.2f) m_route.pop_front();

	if (m_route.size() > 0)
	{
		D3DXVECTOR3 target = m_route.front();
		D3DXVECTOR3 dir = target - m_pos;
		D3DXVec3Normalize(&dir, &dir);
		m_pos += dir * speed;
		m_angle = GetAngle(m_pos, m_route.front());
	}
	else m_move = false;
}

bool cMonster::IsMeetPlayer()
{
	float distToPlayer = GetDistance(m_pos, *m_pPlayerPos);

	D3DXVECTOR3 dir = *m_pPlayerPos - m_pos;
	D3DXVec3Normalize(&dir, &dir);

	cRay ray;
	ray.SetRayDir(dir);
	ray.SetRayOrg(D3DXVECTOR3(m_pos.x, 1, m_pos.z));
	float dist;
	float nearDist = -1;
	for (size_t i = 0; i < m_wallSurface.size(); i += 3)
	{
		if (D3DXIntersectTri(&m_wallSurface[i], &m_wallSurface[i + 1], &m_wallSurface[i + 2], &ray.GetRayOrg(), &ray.GetRayDir(), NULL, NULL, &dist))
		{
			if (nearDist < 0) nearDist = dist;
			else if (dist < nearDist) nearDist = dist;
		}
	}

	if (nearDist < distToPlayer) return false;
	if (D3DXVec3Dot(&dir, &m_dir) >= 0.75f) return true;
	return false;
}

bool cMonster::IsPlayerAtNear()
{
	float distToPlayer = GetDistance(m_pos, *m_pPlayerPos);

	D3DXVECTOR3 dir = *m_pPlayerPos - m_pos;
	D3DXVec3Normalize(&dir, &dir);

	cRay ray;
	ray.SetRayDir(dir);
	ray.SetRayOrg(D3DXVECTOR3(m_pos.x, 1, m_pos.z));
	float dist;
	float nearDist = -1;
	for (size_t i = 0; i < m_wallSurface.size(); i += 3)
	{
		if (D3DXIntersectTri(&m_wallSurface[i], &m_wallSurface[i + 1], &m_wallSurface[i + 2], &ray.GetRayOrg(), &ray.GetRayDir(), NULL, NULL, &dist))
		{
			if (nearDist < 0) nearDist = dist;
			else if (dist < nearDist) nearDist = dist;
		}
	}

	if (nearDist < distToPlayer) return false;
	return true;
}

float cMonster::GetDistance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
{
	D3DXVECTOR3 dist = pos1 - pos2;
	return sqrt(dist.x * dist.x + dist.y * dist.y + dist.z * dist.z);
}

float cMonster::GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
{
	float nWidth, nHeight;
	float fHypotenuse;
	float fAngle;
	nWidth = pos2.x - pos1.x;
	nHeight = pos2.z - pos1.z;
	fHypotenuse = sqrtf(nWidth * nWidth + nHeight * nHeight);
	fAngle = acosf(nWidth / fHypotenuse);
	if (pos2.z < pos1.z)
	{
		fAngle = 2 * D3DX_PI - fAngle;
		if (fAngle >= 2 * D3DX_PI) fAngle -= 2 * D3DX_PI;
	}
	return fAngle;
}
