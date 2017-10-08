#pragma once
#include "iState.h"

#define MAX_WAITTIME 1.0f

class cStateWait : public iState
{
protected:
	float m_waitTime;
public:
	cStateWait(cMonster* pThis);
	~cStateWait();

	virtual void Setup() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};