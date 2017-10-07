#pragma once

class cMonster;

class iState
{
protected:
	cMonster* m_pThis;
public:
	virtual void Setup() = 0;
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};