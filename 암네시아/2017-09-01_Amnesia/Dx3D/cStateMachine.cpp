#include "stdafx.h"
#include "cStateMachine.h"
#include "iState.h"
#include "cMonster.h"

#include "cStateWait.h"
#include "cStateMoveToPos1.h"
#include "cStateMoveToPos2.h"
#include "cStateLookPlayer.h"
#include "cStateRunToPlayer.h"
#include "cStateMissedPlayer.h"
#include "cStateAttack.h"

cStateMachine::cStateMachine(cMonster* pMonster)
	: m_pMonster(NULL)
	, m_pCurState(NULL)
{
	m_pMonster = pMonster;
	AddState(MON_STATE_WAIT, new cStateWait(pMonster));
	AddState(MON_STATE_MOVE_MONPOS1, new cStateMoveToPos1(pMonster));
	AddState(MON_STATE_MOVE_MONPOS2, new cStateMoveToPos2(pMonster));
	AddState(MON_STATE_LOOKPLAYER, new cStateLookPlayer(pMonster));
	AddState(MON_STATE_RUNTOPLAYER, new cStateRunToPlayer(pMonster));
	AddState(MON_STATE_MISSEDPLAYER, new cStateMissedPlayer(pMonster));
	AddState(MON_STATE_ATTACK, new cStateAttack(pMonster));

	SetState(MON_STATE_WAIT);
}

cStateMachine::~cStateMachine()
{
	m_pCurState = NULL;
	for each(auto p in m_stateList)
	{
		SAFE_DELETE(p.second);
	}
}

void cStateMachine::AddState(MONSTER_STATE id, iState* pState)
{
	m_stateList[id] = pState;
}

void cStateMachine::SetState(MONSTER_STATE state)
{
	assert(m_stateList.find(state)->second && "해당 상태가 Add되지 않았습니다 (cStateMachine)");
	if(m_pCurState) m_pCurState->Release();
	m_pCurState = m_stateList[state];
	m_pCurState->Setup();
}

void cStateMachine::ChanteState(MONSTER_STATE ID)
{
	if (m_pCurState) m_pCurState->Release();
	m_pCurState = m_stateList[ID];
	assert(m_pCurState);
	m_pCurState->Setup();
}

void cStateMachine::Update()
{
	if (m_pCurState) m_pCurState->Update();
}

void cStateMachine::Render()
{
	if (m_pCurState) m_pCurState->Render();
}