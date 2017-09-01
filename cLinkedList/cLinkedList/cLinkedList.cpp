#include "StdAfx.h"
#include "cLinkedList.h"
#include "cNode.h"

cLinkedList::cLinkedList(void)
	: m_pHead(NULL)
{
}


cLinkedList::~cLinkedList(void)
{

}

void cLinkedList::Insert( int n )
{
	cNode *l_cNode;
	l_cNode = m_pHead;

	cNode *l_pTail;

	l_pTail = new cNode;
	l_pTail->m_nValue = n;
	l_pTail->m_pNext = NULL;

	if (m_pHead == NULL)
	{
		m_pHead = l_pTail;
	}
	else
	{
		while (l_cNode->m_pNext != NULL)
		{
			l_cNode = l_cNode->m_pNext;
		}
		l_cNode->m_pNext = l_pTail;
	}


}

void cLinkedList::Delete(int n)
{
	if (m_pHead == NULL)return;
	cNode *l_cNode;
	l_cNode = m_pHead;

	cNode *l_pSaveNode;
	l_pSaveNode = m_pHead;
	if (l_cNode->m_nValue == n)
	{
		m_pHead = l_cNode->m_pNext;
		delete(l_cNode);
	}
	else 
	{
		while (l_cNode->m_pNext != NULL)
		{
			l_cNode = l_cNode->m_pNext;
			if (l_cNode->m_nValue == n)
			{
				l_pSaveNode->m_pNext = l_cNode->m_pNext;
				delete(l_cNode);
				break;
			}
			l_pSaveNode = l_cNode;
		}
	}


}



void cLinkedList::Print()
{
	if (m_pHead == NULL)return;
	cNode *l_cNode;
	l_cNode = m_pHead;
	std::cout << l_cNode->m_nValue << std::endl;
	while (l_cNode->m_pNext != NULL)
	{
		l_cNode = l_cNode->m_pNext;
		std::cout << l_cNode->m_nValue << std::endl;
	}	
}
void cLinkedList::Reverse()
{
	if (m_pHead == NULL)return;

	cNode *l_cNode;
	l_cNode = m_pHead;
	cNode *Change;
	cNode *Next;

	Change = NULL;

	while (l_cNode->m_pNext != NULL)
	{
		Next = l_cNode->m_pNext;
		l_cNode->m_pNext = Change;
		Change = l_cNode;
		l_cNode = Next;
	}
	l_cNode->m_pNext = Change;

	m_pHead = l_cNode;

}

void cLinkedList::fileInsert(void)
{

}
