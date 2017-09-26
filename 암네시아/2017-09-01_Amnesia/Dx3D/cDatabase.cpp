#include "stdafx.h"
#include "cDatabase.h"

cDatabase::cDatabase()
	: m_nHP(100)
	, m_nMental(100)
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
	if (m_mapData[key] > 0)
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
