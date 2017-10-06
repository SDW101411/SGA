#pragma once

#define g_pSoundTrack cSoundTrack::GetInstance()

class cSoundTrack
{
private:
	SINGLETON(cSoundTrack);

public:
	void Insert();

};

