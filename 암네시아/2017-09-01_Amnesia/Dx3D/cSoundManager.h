#pragma once

#define g_pSoundManager cSoundManager::GetInstance()

class cSoundManager
{
private:
	SINGLETON(cSoundManager)

public:
	cSoundManager();
	~cSoundManager();

	void Update();
};

