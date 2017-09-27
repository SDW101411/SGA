#pragma once

#include "singletonBase.h"

enum ITEM
{
	ITEM_TINDER,
	ITEM_LAMP,
	ITEM_OIL,
	ITEM_HP,
	ITEM_MENTAL,
};

class cDatabase : public singletonBase<cDatabase>
{
private:
	map<int, int> m_mapData;

public:
	int m_nHP;
	int m_nMental;

	//vector<cObject_Light*> m_vecLight;

public:
	cDatabase();
	~cDatabase();

public:
	void Insert(int key);
	void Delete(int key);
	int Load(int key);
	bool isHave(int key);

	int* GetHp() { return &m_nHP; }
	int* GetMental() { return &m_nMental; }
};

