#include "stdafx.h"
#include "cLoadManager.h"
#include "cObject_Map.h"
#include "cMapLoader.h"

cLoadManager::cLoadManager()
{
}

cLoadManager::~cLoadManager()
{
}

vector<cObject_Game*> cLoadManager::LoadToObjectGame()
{

	return cObject_Vec;
}

vector<cObject_Map*> cLoadManager::LoadToObjectMap()
{

	return cObject_Map_Vec;
}
