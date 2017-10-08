#pragma once
#include "iState.h"

class cStateLookPlayer : public iState
{
protected:
	float m_lookTime;
public:
	cStateLookPlayer(cMonster* pThis);
	~cStateLookPlayer();

	virtual void Setup() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	float GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
};