#pragma once

#include "singletonbase.h"

#include <string>
#include <map>

//fmod hpp�߰�!!
#include "inc/fmod.hpp"

//lib��ũ...
#pragma comment (lib, "lib/fmodex_vc.lib")

using namespace FMOD;

#define EXTRACHANNELBUFFER 5
#define SOUNDBUFFER 10

#define TOTALSOUNDBUFFER (EXTRACHANNELBUFFER + SOUNDBUFFER)

class cSoundManager : public singletonBase <cSoundManager>
{
private:
	typedef map<string, Sound**> arrSounds;
	typedef map<string, Sound**>::iterator arrSoundsIter;
	typedef map<string, Channel**> arrChannels;
	typedef map<string, Channel**>::iterator arrChannelsIter;

private:
	System* _system;
	Sound** _sound;
	Channel** _channel;

	arrSounds _mTotalSounds;

public:
	HRESULT init(void);
	void release(void);

	//flac, mp3, wave, midi, ogg, m4a, aac, aif, aiff, wma
	void addSound(string keyName, string soundName, bool background, bool loop);
	void play(string keyName);

	//���ϴ� ����...
	void play(string keyName, float volume);
	void pause(string keyName);
	void resume(string keyName);
	void stop(string keyName);

	//�Ͻ� ���� �Ǿ��°�?
	bool isPauseSound(string keyName);

	//���� ������̳�?
	bool isPlaySound(string keyName);

	//������ ���� �� �����´� (�и��겫 : 1000 == 1��)
	unsigned int getLength(string keyName);

	//������ �������� �����Ѵ�
	void setPosition(string keyName, unsigned int ms);

	//������� ������ ���� ��ġ�� �����´�
	unsigned int getPosition(string keyName);

	//fmod �ý��� ����...
	void update(void);

	cSoundManager(void);
	~cSoundManager(void);
};

