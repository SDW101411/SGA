#include "stdafx.h"
#include "cMapLoader.h"
#include "cObject_Game.h"
#include "cMapObject.h"

vector<cObject_Game*> cMapLoader::LoadToObject_Game()
{
	vector<cObject_Game*> rtnObjList;

	FILE* fp = fopen("Data/MapData.txt", "r");

	fclose(fp);

	return rtnObjList;
}

map<int, map<int, vector<cMapObject*>>> cMapLoader::LoadToMapObject()
{
	map<int, map<int, vector<cMapObject*>>> rtnObjList;

	FILE* fp = fopen("Data/MapData.txt", "r");

	fclose(fp);

	return rtnObjList;
}
