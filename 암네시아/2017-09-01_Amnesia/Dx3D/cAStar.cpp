#include "stdafx.h"
#include "cAStar.h"
#include "cGridNode.h"
#include "cMapLoader.h"
#include "cMapTool.h"

cAStar::cAStar()
{
	cMapLoader loader;
	m_nodeList = loader.LoadToGridNode();
	InitializeCriticalSection(&m_cs);

	for each(auto f in m_nodeList)
	{
		for each(auto s in f.second)
		{
			m_nodeData.push_back(s.second);
		}
	}
}

cAStar::~cAStar()
{
	map<int, map<int, cGridNode*>>::iterator row = m_nodeList.begin();
	for (; row != m_nodeList.end(); row++)
	{
		map<int, cGridNode*>::iterator col = (*row).second.begin();
		for (; col != (*row).second.end(); col++)
		{
			SAFE_DELETE((*col).second);
		}
	}

	DeleteCriticalSection(&m_cs);
}

void cAStar::Render()
{
	map<int, map<int, cGridNode*>>::iterator first = m_nodeList.begin();
	for (; first != m_nodeList.end(); first++)
	{
		map<int, cGridNode*>::iterator second = (*first).second.begin();
		for (; second != (*first).second.end(); second++)
		{
			SAFE_RENDER((*second).second);
		}
	}
}

list<D3DXVECTOR3> cAStar::FindPath(D3DXVECTOR3 start, D3DXVECTOR3 end)
{
	list<D3DXVECTOR3> rtnPath;
	if (!m_isClear) return rtnPath;
	vector<cGridNode*> OpenList;
	vector<cGridNode*> CloseList;
	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SetNodeCleanFunc, this, NULL/*CREATE_SUSPENDED*/, &m_dwThID));

	return list<D3DXVECTOR3>();
}

bool cAStar::FindRowCol(IN D3DXVECTOR3 pos, OUT int & row, OUT int & col)
{
	row = abs((pos.x - m_leftTop.x + GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	col = abs((pos.z - m_leftTop.z - GRIDNODE_HALFSIZE) / GRIDNODE_SIZE);
	if (row < 0 || col < 0) return false;
	return true;
}

void cAStar::SetNodeCleanFunc(LPVOID param)
{
	cAStar* pThis = (cAStar*)param;

	for each(auto p in pThis->GetNodeData())
	{
		p->SetClean();
	}

	pThis->SetIsClear(true);
}
