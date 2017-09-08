#pragma once

#define g_pSceneManager cUIManager::GetInstance

class cUIObject;

class cUIManager
{
private:
	map<string, cUIObject*> m_mapUI;

public:
	SINGLETON(cUIManager);
	cUIObject* GetUI(char* szFolder, char* szFileName);

};

