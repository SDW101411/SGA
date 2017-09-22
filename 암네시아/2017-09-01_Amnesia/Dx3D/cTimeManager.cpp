#include "StdAfx.h"
#include "cTimeManager.h"


cTimeManager::cTimeManager(void)
	: m_dwPrevTimeStamp(GetTickCount())
	, m_dwDeltaTime(0)
//	, m_eFontType(cFontManager::E_NORMAL)
	, m_dwDT(DT_LEFT | DT_TOP | DT_NOCLIP)
	, m_dwColor(D3DCOLOR_XRGB(255, 255, 255))
{
	if (QueryPerformanceFrequency((LARGE_INTEGER*)&_periodFrequency))
	{
		_isHardware = true;
		QueryPerformanceCounter((LARGE_INTEGER*)&_lastTime);
		_timeScale = 1.0f / _periodFrequency;
	}
	else
	{
		_isHardware = false;
		_lastTime = GetTickCount();
		_timeScale = 0.001f;
	}

	_frameRate = 0;
	_FPSFrameCount = 0;
	_FPSTimeElapsed = 0.0f;
	_worldTime = 0.0f;
	_lockFPS = 60.0f;
}


cTimeManager::~cTimeManager(void)
{
}

void cTimeManager::Update()
{
	DWORD dwCurrTimeStamp = GetTickCount();
	m_dwDeltaTime = dwCurrTimeStamp - m_dwPrevTimeStamp;
	m_dwPrevTimeStamp = dwCurrTimeStamp;


	if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	else _curTime = GetTickCount();

	_timeElapsed = (_curTime - _lastTime) * _timeScale;

	if (_lockFPS > 0.0f) while (_timeElapsed < (1.0f / _lockFPS))
	{
		if (_isHardware) QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
		else _curTime = GetTickCount();

		_timeElapsed = (_curTime - _lastTime) * _timeScale;
	}

	_lastTime = _curTime;
	_FPSFrameCount++;
	_FPSTimeElapsed += _timeElapsed;
	_worldTime += _timeElapsed;

	if (_FPSTimeElapsed > 1.0f)
	{
		_frameRate = _FPSFrameCount;
		_FPSFrameCount = 0;
		_FPSTimeElapsed = 0.0f;
	}

	//프레임 찍어준다
	sprintf_s(m_sText, TEXT("framePerSec : %d"), _frameRate);
#ifdef _DEBUG
	//월드 타임 찍어준다
	sprintf_s(m_sText2, TEXT("worldTime : %f"), _worldTime);

	//갱신시간 찍어준다
	sprintf_s(m_sText3, TEXT("elapsedTime : %f"), _timeElapsed);
#endif
}

float cTimeManager::GetDeltaTime()
{
	return (float)m_dwDeltaTime / 1000.f;
}

float cTimeManager::GetWorldCheck(void)
{
	if (_isHardware) return QueryPerformanceCounter((LARGE_INTEGER*)&_curTime);
	else _curTime = GetTickCount();
	return _curTime * _timeScale;
}

void cTimeManager::Render(void)
{
	RECT rc;
	SetRect(&rc, 0, 0, 20, 20);
	LPD3DXFONT pFont = g_pFontManager->GetFont(cFontManager::E_NORMAL);
	pFont->DrawTextA(NULL,
		m_sText,
		16,
		&rc,
		m_dwDT,
		m_dwColor);

#ifdef _DEBUG
	RECT rc2;
	SetRect(&rc2, 0, 20, 20, 20);
	LPD3DXFONT pFont2 = g_pFontManager->GetFont(cFontManager::E_NORMAL);
	pFont2->DrawTextA(NULL,
		m_sText2,
		20,
		&rc2,
		m_dwDT,
		m_dwColor);

	RECT rc3;
	SetRect(&rc3, 0, 40, 20, 20);
	LPD3DXFONT pFont3 = g_pFontManager->GetFont(cFontManager::E_NORMAL);
	pFont3->DrawTextA(NULL,
		m_sText3,
		22,
		&rc3,
		m_dwDT,
		m_dwColor);
#endif
}