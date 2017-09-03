#include "stdafx.h"
#include "cScene_Manager.h"
#include "cScene.h"

//2017-09-04 추가된 씬 매니져 입니다. Map STL을 활용하여 정리합니다.
cScene_Manager::cScene_Manager()
{
}


cScene_Manager::~cScene_Manager()
{
}

void cScene_Manager::INSERT(char* szName, cScene * Insert_cScene)
{
	cScene *Save;
	Save = new cScene();
	cScene_database.insert(map<string, cScene*>::value_type(szName, Save));
}
