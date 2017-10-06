#include "stdafx.h"
#include "cStateMachine.h"
#include "iState.h"
#include "cMonster.h"

cStateMachine::cStateMachine(cMonster* pMonster)
	: m_pMonster(NULL)
	, m_pCurState(NULL)
{
	m_pMonster = pMonster;
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

void cStateMachine::SetState()
{

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