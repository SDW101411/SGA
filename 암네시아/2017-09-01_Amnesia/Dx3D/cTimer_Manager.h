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

	//������ ����
	void update(float lock = 0.0f);

	//ȭ�鿡 Ÿ�̸� ���� ���
	void render(HDC hdc);

	//��ü �ð� ���´�
	inline float getWorldTime(void) const { return _timer->getWorldTime(); }

	//������ ���� ����ð�
	inline float getElapsedTime(void) const { return _timer->getElapsedTime(); }

	cTimer_Manager(void);
	~cTimer_Manager(void);
};

