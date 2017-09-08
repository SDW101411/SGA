#include "stdafx.h"
#include "cUIManager.h"

cUIManager::cUIManager()
{
}

cUIManager::~cUIManager()
{
}

cUIObject* cUIManager::GetUI(char* szFolder, char* szFileName)
{
	string sFullPath(szFolder);
	sFullPath += string(szFileName);

	if (m_mapUI.find(sFullPath) == m_mapUI.end())
	{
		cUIObject* pUI = new cUIObject();
		
		m_mapUI[sFullPath] = pUI;
	}

	return m_mapUI[sFullPath];
}
