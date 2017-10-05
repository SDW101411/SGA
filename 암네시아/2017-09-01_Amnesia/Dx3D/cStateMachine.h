#pragma once

class iState;
class cMonster;

enum
{
	MON_MOVEAROUND,
	MON_RUNTOPLAYER,
	MON_LOOKAROUND,
};
typedef int MONSTER_STATE;

class cStateMachine
{
private:
	map<int, iState*>	m_stateList;
	iState*				m_pCurState;
	cMonster*			m_pMonster;
public:
	cStateMachine(cMonster* pMonster);
	~cStateMachine();

	void AddState(MONSTER_STATE id, iState* pState);
	void SetState();
	void ChanteState(MONSTER_STATE ID);
	void Update();
	void Render();
};