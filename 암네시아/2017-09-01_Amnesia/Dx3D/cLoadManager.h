#pragma once

#define g_pLoadManager cLoadManager::GetInstance

class cObject_Game;
class cObject_Map;
class cObject_Light;

class cLoadManager
{
private:
	SINGLETON(cLoadManager);
	SYNTHESIZE(vector<cObject_Game*>, cObject_Vec, Object_Vec);
	SYNTHESIZE(vector<cObject_Map*>, cObject_Map_Vec, Object_Map_Vec);
	SYNTHESIZE(vector<cObject_Light*>, cObject_Light_vec, Object_Light_Vec);

public:
	vector<cObject_Game*> LoadToObjectGame();
	vector<cObject_Map*> LoadToObjectMap();

};

