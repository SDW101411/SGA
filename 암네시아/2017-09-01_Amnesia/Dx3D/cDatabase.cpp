#include "stdafx.h"
#include "cDatabase.h"

cDatabase::cDatabase()
{
}

cDatabase::~cDatabase()
{
}

void cDatabase::Insert(int key)
{
	m_mapData[key] += 1;
}

void cDatabase::Delete(int key)
{
	if(m_mapData[key] > 0)
		m_mapData[key] -= 1;
}

int cDatabase::Load(int key)
{
	return m_mapData[key];
}

bool cDatabase::isHave(int key)
{
	if (m_mapData[key] > 0) return true;
	return false;
}

ITEM cDatabase::GetTag(int key)
{
	switch (key)
	{
	case 0:
		return ITEM_TINDER;
		break;
	case 1:
		return ITEM_LAMP;
		break;
	case 2:
		return ITEM_OIL;
		break;
	case 3:
		return ITEM_HP;
		break;
	}
	return ITEM_TINDER;
}
