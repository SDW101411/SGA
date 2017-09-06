#pragma once

#include "singletonbase.h"

class cScene;
class cScene_Manager : public singletonBase <cScene_Manager>
{
private:
	map<string, cScene*> cScene_database;
public:
	cScene_Manager();
	~cScene_Manager();

	void INSERT(char * szName, cScene * Insert_cScene);
	cScene *FIND(char * szName);
};

