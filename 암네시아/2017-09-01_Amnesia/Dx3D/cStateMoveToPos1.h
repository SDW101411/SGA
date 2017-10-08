#pragma once
#include "iState.h"

class cStateMoveToPos1 : public iState
{
private:
public:
	cStateMoveToPos1(cMonster* pThis);
	~cStateMoveToPos1();

	virtual void Setup() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};