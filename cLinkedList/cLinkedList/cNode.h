#pragma once

class cNode
{
public:
	cNode(void); //�����̴� ���õ� ���� ���ϴ�
	~cNode(void); //�ѳ��� �Ӹ��� ���� �ʾҴ�.

	int		m_nValue;
	cNode*	m_pNext;
};

