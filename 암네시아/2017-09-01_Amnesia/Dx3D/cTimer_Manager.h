#pragma once

#include "singletonbase.h"
#include "cTimer.h"

//==========================================
//======= ## 20170511 timeManager ## ======== 
//==========================================
class cTimer_Manager : public singletonBase <cTimer_Manager>
{
private:
	cTimer* _timer;

public:
	HRESULT init(void);
	void release(void);

	//프레임 적용
	void update(float lock = 0.0f);

	//화면에 타이머 정보 출력
	void render(HDC hdc);

	//전체 시간 얻어온다
	inline float getWorldTime(void) const { return _timer->getWorldTime(); }

	//프레임 사이 경과시간
	inline float getElapsedTime(void) const { return _timer->getElapsedTime(); }

	cTimer_Manager(void);
	~cTimer_Manager(void);
};

