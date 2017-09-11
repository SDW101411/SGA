#pragma once

class cTimer
{
private:
	bool	_isHardware;		//타이머(고성능) 지원 되냐?
	float	_timeElapsed;		//마지막 시간과 현재 시간의 경과량
	float	_timeScale;			//시간 경과량 조절

	__int64	_curTime;			//현재시간
	__int64 _lastTime;			//이전시간
	__int64 _periodFrequency;	//시간주기

	unsigned long _frameRate;		//FPS
	unsigned long _FPSFrameCount;	//FPS 카운트
	float _FPSTimeElapsed;			//프레임 사이의 경과량
	float _worldTime;				//게임이 시작한 후 지나간 전체 시간

public:
	HRESULT init(void);
	void release(void);

	//현재 시간 계산한다
	void tick(float lockFPS = 0.0f);

	//현재 FPS
	unsigned long getFrameRate(char* str = NULL) const;

	//마지막 시간과 현재 시간의 경과량
	inline float getElapsedTime(void) const { return _timeElapsed; }

	//전체 경과시간임
	inline float getWorldTime(void) const { return _worldTime; }

	cTimer(void) {};
	~cTimer(void) {};
};

