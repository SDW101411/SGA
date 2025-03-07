#pragma once
#include "cAction.h"

class cActionMove : public cAction
{
protected:
	SYNTHESIZE_PASS_BY_REF(D3DXVECTOR3, m_vFrom, From);
	SYNTHESIZE_PASS_BY_REF(D3DXVECTOR3, m_vTo, To);

public:
	cActionMove(void);
	virtual ~cActionMove(void);

	virtual void Start() override; 
	virtual void Update() override;
};


