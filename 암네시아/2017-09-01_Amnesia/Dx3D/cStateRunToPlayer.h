#pragma once
#include "iState.h"

class cStateRunToPlayer : public iState
{
protected:
	bool m_isMissedPlayer;
public:
	cStateRunToPlayer(cMonster* pThis);
	~cStateRunToPlayer();

	virtual void Setup() override;
	virtual void Release() override;
	virtual void Update() override;
	virtual void Render() override;

	float GetDistance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
	float GetAngle(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2);
};