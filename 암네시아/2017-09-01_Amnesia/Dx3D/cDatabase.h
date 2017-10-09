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
	SYNTHESIZE(float, m_fOilValue, OilValue);
	SYNTHESIZE(float, m_fHP, Hp);
	SYNTHESIZE(float, m_fMental, Mental);

public:
	cDatabase();
	~cDatabase();

public:
	void Insert(int key);
	void Delete(int key);
	int Load(int key);
	bool isHave(int key);

	void AddOilValue(float add) { m_fOilValue += add; }
};

