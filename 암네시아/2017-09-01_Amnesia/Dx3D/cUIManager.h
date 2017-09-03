#pragma once

#define g_pUIManager cUIManager::GetInstance()

class cUIManager
{
private:
	SINGLETON(cUIManager)

public:
};

