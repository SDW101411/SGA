#pragma once

#define g_pLoadManager cLoadManager::GetInstance

class cObject_Game;
class cObject_Map;

class cLoadManager
{
private:
	SINGLETON(cLoadManager);

public:
	vector<cObject_Game*> cObject_Vec;
	vector<cObject_Map*> cObject_Map_Vec;

public:
	vector<cObject_Game*> LoadToObjectGame();
	vector<cObject_Map*> LoadToObjectMap();

};

