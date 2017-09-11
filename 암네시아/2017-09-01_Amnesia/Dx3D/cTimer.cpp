#include "StdAfx.h"
#include "cTimer.h"
#include <MMSystem.h>

//timeGetTime 함수 이용하기 위한 라이브러리임.
#pragma comment(lib, "winmm.lib")

//초기화한다
HRESULT cTimer::init(void)
{
	//고성능 타이머가 지원되는지 확인한다.
	//지원되면 _periodFrequency값에 초당 확인할 수 있는 시간이 들어간다
	//초당 밀리쎄컨..... (1000)
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		_timeScale = 1.0f / _periodFrequency;
	}
	else
	{
		_isHardware = false;

		//밀리쎄컨단위로 초당 1000...
		_lastTime = timeGetTime();
		_timeScale = 0.001f;
	}

	_frameRate = 0;
	_FPSFrameCount = 0;
	_FPSTimeElapsed = 0.0f;
	_worldTime = 0.0f;

	return S_OK;
}

void cTimer::release(void)
{
}

//현재 시간 계산한다
void cTimer::tick(float lockFPS)
{
	if (_isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else //여기 들어오면 똥컴.... 
	{
		_curTime = timeGetTime();
	}

	//마지막 시간과 현재시간의 경과량을 측정한다
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	//고정 프레임 처리해준다 (전문용어로 '프레임스키핑'이라 한다)
	if (lockFPS > 0.0f)
	{
		//고정프레임 값이 만족할때까지 루프 돌아준다
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			//마지막 시간과 현재시간의 경과량을 측정한다
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	//마지막 시간을 기록하고...
	_lastTime = _curTime;

	//초당 프레임 카운트 증가후...
	_FPSFrameCount++;

	//초당 프레임 경과량 증가시킨다...
	_FPSTimeElapsed += _timeElapsed;

	//마지막으로 전체 시간 경과량 증가!!
	_worldTime += _timeElapsed;

	//1초마다 프레임 초기화 해준다 
	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}
}

//현재 FPS 가져온다
unsigned long cTimer::getFrameRate(char* str) const
{
	if (str != NULL) sprintf(str, "FPS : %d", _frameRate);
	return _frameRate;
}

