#include "stdafx.h"
#include "cScene_Manager.h"
#include "cScene.h"

//2017-09-04 �߰��� �� �Ŵ��� �Դϴ�. Map STL�� Ȱ���Ͽ� �����մϴ�.
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
