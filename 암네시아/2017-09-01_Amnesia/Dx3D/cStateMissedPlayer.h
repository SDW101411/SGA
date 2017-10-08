#pragma once
#include "iState.h"

class cStateMissedPlayer : public iState
{
private:
	float m_waitTime;
public:
	cStateMissedPlayer(cMonster* pThis);
	~cStateMissedPlayer();

	virtual void Setup() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};