#include "StdAfx.h"
#include "cTimer.h"
#include <MMSystem.h>

//timeGetTime �Լ� �̿��ϱ� ���� ���̺귯����.
#pragma comment(lib, "winmm.lib")

//�ʱ�ȭ�Ѵ�
HRESULT cTimer::init(void)
{
	//���� Ÿ�̸Ӱ� �����Ǵ��� Ȯ���Ѵ�.
	//�����Ǹ� _periodFrequency���� �ʴ� Ȯ���� �� �ִ� �ð��� ����
	//�ʴ� �и�����..... (1000)
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);

		_timeScale = 1.0f / _periodFrequency;
	}
	else
	{
		_isHardware = false;

		//�и����������� �ʴ� 1000...
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

//���� �ð� ����Ѵ�
void cTimer::tick(float lockFPS)
{
	if (_isHardware)
	{
		QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	}
	else //���� ������ ����.... 
	{
		_curTime = timeGetTime();
	}

	//������ �ð��� ����ð��� ������� �����Ѵ�
	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	//���� ������ ó�����ش� (�������� '�����ӽ�Ű��'�̶� �Ѵ�)
	if (lockFPS > 0.0f)
	{
		//���������� ���� �����Ҷ����� ���� �����ش�
		while (_timeElapsed < (1.0f / lockFPS))
		{
			if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
			else _curTime = timeGetTime();

			//������ �ð��� ����ð��� ������� �����Ѵ�
			_timeElapsed = (_curTime - _lastTime) * _timeScale;
		}
	}

	//������ �ð��� ����ϰ�...
	_lastTime = _curTime;

	//�ʴ� ������ ī��Ʈ ������...
	_FPSFrameCount++;

	//�ʴ� ������ ����� ������Ų��...
	_FPSTimeElapsed += _timeElapsed;

	//���������� ��ü �ð� ����� ����!!
	_worldTime += _timeElapsed;

	//1�ʸ��� ������ �ʱ�ȭ ���ش� 
	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}
}

//���� FPS �����´�
unsigned long cTimer::getFrameRate(char* str) const
{
	if (str != NULL) sprintf(str, "FPS : %d", _frameRate);
	return _frameRate;
}

