#include "stdafx.h"
#include "cAStar.h"
#include "cGridNode.h"
#include "cMapLoader.h"
#include "cMapTool.h"

cAStar::cAStar()
{
	cMapLoader loader;
	
	m_leftTop = loader.LoadToLeftTop();

	m_nodeList = loader.LoadToGridNode();
	InitializeCriticalSection(&m_cs);

	m_dirList.push_back(GRIDNODE_DIR_LEFT);
	m_dirList.push_back(GRIDNODE_DIR_RIGHT);
	m_dirList.push_back(GRIDNODE_DIR_UP);
	m_dirList.push_back(GRIDNODE_DIR_DOWN);
	m_dirList.push_back(GRIDNODE_DIR_LEFT	 | GRIDNODE_DIR_UP);
	m_dirList.push_back(GRIDNODE_DIR_LEFT	 | GRIDNODE_DIR_DOWN);
	m_dirList.push_back(GRIDNODE_DIR_RIGHT	 | GRIDNODE_DIR_UP);
	m_dirList.push_back(GRIDNODE_DIR_RIGHT	 | GRIDNODE_DIR_DOWN);

	m_distList[GRIDNODE_DIR_LEFT]	= 1.0f;
	m_distList[GRIDNODE_DIR_RIGHT]	= 1.0f;
	m_distList[GRIDNODE_DIR_UP]		= 1.0f;
	m_distList[GRIDNODE_DIR_DOWN]	= 1.0f;
	m_distList[GRIDNODE_DIR_LEFT	| GRIDNODE_DIR_UP] = sqrt(2.0f);
	m_distList[GRIDNODE_DIR_LEFT	| GRIDNODE_DIR_DOWN] = sqrt(2.0f);
	m_distList[GRIDNODE_DIR_RIGHT	| GRIDNODE_DIR_UP] = sqrt(2.0f);
	m_distList[GRIDNODE_DIR_RIGHT	| GRIDNODE_DIR_DOWN] = sqrt(2.0f);

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

	cGridNode* pStartNode = FindNode(start);
	cGridNode* pDestNode = FindNode(end);

	pStartNode->SetG(0.0f);
	pStartNode->SetH(CalcHeuristic(pStartNode, pDestNode));
	pStartNode->SetF(pStartNode->GetG() + pStartNode->GetH());

	AddOpenList(pStartNode);

	while (true)
	{
		cGridNode* pMinFNode = MinFNodeAtOpenList();
		if (pMinFNode == NULL)
		{
			return rtnPath;
		}

		AddCloseList(pMinFNode);

		Extend(pMinFNode, pDestNode);

		if (pMinFNode == pDestNode)
			break;
	}

	cGridNode* pCurNode = pDestNode;

	while (pCurNode != pStartNode)
	{
		rtnPath.push_front(pCurNode->GetPosition());
		pCurNode->SetColorYellow();
		pCurNode = pCurNode->GetParent();
	}

	CloseHandle(CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SetNodeCleanFunc, this, NULL/*CREATE_SUSPENDED*/, &m_dwThID));

	return rtnPath;
}

void cAStar::AddOpenList(cGridNode* pNode)
{
	pNode->SetIsOpen(true);
	m_openList.insert(pNode);
}

void cAStar::AddCloseList(cGridNode* pNode)
{
	m_openList.erase(pNode);
	pNode->SetIsOpen(false);
	pNode->SetIsClose(true);
}

void cAStar::ClearOpenList()
{
	m_openList.clear();
}

cGridNode* cAStar::MinFNodeAtOpenList()
{
	cGridNode* rtnNode = NULL;
	float fMinF = FLT_MAX;
	for each(auto p in m_openList)
	{
		if (p->GetF() < fMinF)
		{
			rtnNode = p;
			fMinF = p->GetF();
		}
	}

	return rtnNode;
}

cGridNode* cAStar::GetAdjNode(cGridNode* pExtNode, GRIDNODE_DIR e)
{
	int nAdjRow = pExtNode->GetRow();
	int nAdjCol = pExtNode->GetCol();

	if (e & GRIDNODE_DIR_LEFT)
	{
		if (pExtNode->GetRow() - 1 < 0) return NULL;
		if (m_nodeList.find(pExtNode->GetRow() - 1)->second.find(pExtNode->GetCol())->second) nAdjRow -= 1;
		else return NULL;
	}
	else if (e & GRIDNODE_DIR_RIGHT)
	{
		if (m_nodeList.find(pExtNode->GetRow() + 1)->second.find(pExtNode->GetCol())->second) nAdjRow += 1;
		else return NULL;
	}

	if (e & GRIDNODE_DIR_UP)
	{
		if (pExtNode->GetCol() - 1 < 0) return NULL;
		if (m_nodeList.find(pExtNode->GetRow())->second.find(pExtNode->GetCol() - 1)->second) nAdjCol -= 1;
		else return NULL;
	}
	else if (e & GRIDNODE_DIR_DOWN)
	{
		if (m_nodeList.find(pExtNode->GetRow())->second.find(pExtNode->GetCol() + 1)->second) nAdjCol += 1;
		else return NULL;
	}

	if (m_nodeList[nAdjRow][nAdjCol]->GetIsClose()) return NULL;

	return m_nodeList[nAdjRow][nAdjCol];
}

void cAStar::Extend(cGridNode* pCurrNode, cGridNode* pDestNode)
{
	for each(GRIDNODE_DIR e in m_dirList)
	{
		cGridNode* pAdjNode = GetAdjNode(pCurrNode, e);

		if (pAdjNode == NULL) continue;

		if (pAdjNode->GetIsOpen())
		{
			if (pAdjNode->GetG() > pCurrNode->GetG() + m_distList[e])
			{
				pAdjNode->SetG(pCurrNode->GetG() + m_distList[e]);
				pAdjNode->SetF(pAdjNode->GetG() + pAdjNode->GetH());
				pAdjNode->SetParent(pCurrNode);
			}
		}
		else
		{
			pAdjNode->SetG(pCurrNode->GetG() + m_distList[e]);
			pAdjNode->SetH(CalcHeuristic(pAdjNode, pDestNode));
			pAdjNode->SetF(pAdjNode->GetG() + pAdjNode->GetH());
			pAdjNode->SetParent(pCurrNode);
			AddOpenList(pAdjNode);
		}
	}
}

float cAStar::CalcHeuristic(cGridNode * pCurrentNode, cGridNode * pDestNode)
{
	return fabs((float)pCurrentNode->GetRow() - pDestNode->GetRow()) +
		fabs((float)pCurrentNode->GetCol() - pDestNode->GetCol());
}

cGridNode* cAStar::FindNode(D3DXVECTOR3 pos)
{
	int row, col;
	if (FindRowCol(pos, row, col))
	{
		if(m_nodeList.find(row)->second.find(col)->second) 
		return m_nodeList[row][col];
	}
	return NULL;
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

	pThis->ClearOpenList();

	for each(auto p in pThis->GetNodeData())
	{
		p->SetClean();
	}

	pThis->SetIsClear(true);
}
