#pragma once
#include "iState.h"

class cDamegeImpact;

class cStateAttack : public iState
{
private:
	cDamegeImpact* m_pImpact;
	float m_attackTime;
	bool m_isAttack;
public:
	cStateAttack(cMonster* pThis);
	~cStateAttack();

	virtual void Setup() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	float GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
};