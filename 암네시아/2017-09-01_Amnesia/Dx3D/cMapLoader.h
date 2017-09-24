#pragma once

class cObject_Game;
class cMapObject;

class cMapLoader
{
	vector<cObject_Game*> LoadToObject_Game();
	map<int, map<int, vector<cMapObject*>>> LoadToMapObject();
};