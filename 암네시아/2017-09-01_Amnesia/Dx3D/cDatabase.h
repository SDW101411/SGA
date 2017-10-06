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
	SYNTHESIZE(int, m_nHP, Hp);
	SYNTHESIZE(int, m_nMental, Mental);
	//float m_nOilValue;
	//int m_nHP;
	//int m_nMental;

public:
	cDatabase();
	~cDatabase();

public:
	void Insert(int key);
	void Delete(int key);
	int Load(int key);
	bool isHave(int key);

	//int* GetHp() { return &m_nHP; }
	//int* GetMental() { return &m_nMental; }

	void AddOilValue(float add) { m_fOilValue += add; }
};

