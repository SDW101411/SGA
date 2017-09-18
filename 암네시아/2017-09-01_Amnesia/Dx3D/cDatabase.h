#pragma once

#include "singletonBase.h"

enum ITEM
{
	ITEM_TINDER,
	ITEM_LAMP,
	ITEM_OIL,
	ITEM_HP,
};

class cDatabase : public singletonBase<cDatabase>
{
private:
	map<int, int> m_mapData;

public:
	cDatabase();
	~cDatabase();

public:
	void Insert(int key);
	void Delete(int key);
	int Load(int key);
	bool isHave(int key);

};

