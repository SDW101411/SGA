#pragma once
class cScene;
class cScene_Manager
{
private:
	map<string, cScene*> cScene_database;
public:
	cScene_Manager();
	~cScene_Manager();

	void INSERT(char * szName, cScene * Insert_cScene);

};

