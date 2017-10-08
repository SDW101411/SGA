#pragma once
#include "iState.h"

class cStateMoveToPos2 : public iState
{
public:
	cStateMoveToPos2(cMonster* pThis);
	~cStateMoveToPos2();

	virtual void Setup() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;
};