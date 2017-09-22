#pragma once

#define g_pTimeManager cTimeManager::GetInstance()

class cTimeManager
{
private:
	SYNTHESIZE(char, m_sText[20], Text);
	SYNTHESIZE(char, m_sText2[30], Text2);
	SYNTHESIZE(char, m_sText3[30], Text3);
	//SYNTHESIZE(cFontManager::eFontType, m_eFontType, FontType);
	SYNTHESIZE(DWORD, m_dwDT, DrawTextFormat);
	SYNTHESIZE(D3DCOLOR, m_dwColor, Color);
	
	SINGLETON(cTimeManager)

private:
	DWORD m_dwPrevTimeStamp;
	DWORD m_dwDeltaTime;

private:
	bool	_isHardware;
	float	_timeElapsed;
	float	_timeScale;

	__int64	_curTime;
	__int64 _lastTime;
	__int64 _periodFrequency;

	unsigned long _frameRate;
	unsigned long _FPSFrameCount;
	float _FPSTimeElapsed;
	float _worldTime;
	float _lockFPS;

public:
	void Update();
	float GetDeltaTime();

public:
	//virtual void Setup(void);
	//virtual void Destroy(void);
	//virtual void Update(void);
	virtual void Render(void);

	virtual void SetLockFPS(float lockFPS) final { _lockFPS = lockFPS; }
	virtual float GetElapsedTime(void) final { return _timeElapsed; } // 게임속도 조절
	virtual float GetWorldTime(void) final { return _worldTime; } // 게임시간
	virtual float GetWorldCheck(void) final;
	virtual int GetFPS(void) { return _frameRate; }

//	static cTimeManager* GetInstance() { static cTimeManager instance; return &instance; }

};

