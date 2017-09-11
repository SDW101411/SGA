#include "StdAfx.h"
#include "cTimer_Manager.h"

cTimer_Manager::cTimer_Manager(void)
{
}

cTimer_Manager::~cTimer_Manager(void)
{
}

HRESULT cTimer_Manager::init(void)
{
	//타이머 생성해준다
	_timer = new cTimer;
	_timer->init();

	return S_OK;
}

void cTimer_Manager::release(void)
{
	if (_timer != NULL) SAFE_DELETE(_timer);
}

void cTimer_Manager::update(float lock)
{
	if (_timer != NULL) _timer->tick(lock);
}

void cTimer_Manager::render(HDC hdc)
{
	char str[256];
	std::string strFrame;

	SetBkMode(hdc, TRANSPARENT);
	SetTextColor(hdc, RGB(255, 255, 255));

#ifdef _DEBUG
	if (_timer != NULL)
	{
		//프레임 찍어준다
		sprintf_s(str, "framePerSec : %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));

		//월드 타임 찍어준다
		sprintf_s(str, "worldTime : %f", _timer->getWorldTime());
		TextOut(hdc, 0, 20, str, strlen(str));

		//갱신시간 찍어준다
		sprintf_s(str, "elapsedTime : %f", _timer->getElapsedTime());
		TextOut(hdc, 0, 40, str, strlen(str));
	}
#else
	if (_timer != NULL)
	{
		//프레임 찍어준다
		sprintf_s(str, "framePerSec : %d", _timer->getFrameRate());
		TextOut(hdc, 0, 0, str, strlen(str));
	}
#endif
}
