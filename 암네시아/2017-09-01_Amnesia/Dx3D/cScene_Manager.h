#pragma once

#include "singletonbase.h"

#define g_pSceneManager cScene_Manager::GetInstance()

class cScene;
class cScene_Manager
{
private:
	SINGLETON(cScene_Manager);
	map<string, cScene*>	cScene_database;
	cScene*					m_pCurrentScene;

public:
	void INSERT(char * szName, cScene* pScene);
	cScene *FIND(char * szName);
	void SceneChange(char * szName);
	void Destroy();

	void Update();
	void Render();

	void Render_UI();

	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

