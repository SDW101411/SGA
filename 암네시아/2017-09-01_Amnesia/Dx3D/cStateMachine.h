#pragma once

class iState;
class cMonster;

enum
{
	MON_STATE_WAIT,
	MON_STATE_MOVE_MONPOS1,
	MON_STATE_MOVE_MONPOS2,
	MON_STATE_LOOKPLAYER,
	MON_STATE_RUNTOPLAYER,
	MON_STATE_ATTACK,
	MON_STATE_MISSEDPLAYER,
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
	void SetState(MONSTER_STATE state);
	void ChanteState(MONSTER_STATE ID);
	void Update();
	void Render();
};