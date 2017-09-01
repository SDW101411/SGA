#pragma once
class cNode
{
public:
	cNode(void);
	~cNode(void);

	int		m_nData;
	cNode*	m_pLChild;
	cNode*	m_pRChild;

	cNode(int n) : m_nData(n), m_pLChild(NULL), m_pRChild(NULL) {}
};

