#include "stdafx.h"
#include "cMapObject.h"

cMapObject::cMapObject()
{
}

cMapObject::~cMapObject()
{
}

void cMapObject::Setup(int tag, D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl)
{
	m_tag = tag;

	m_floor = pos.y;

	m_pos = pos;
	m_rot = rot;
	m_scl = scl;
}
