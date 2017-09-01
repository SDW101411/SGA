#include "StdAfx.h"
#include "cBST.h"
#include "cNode.h"


cBST::cBST(void)
	:m_pRoot(NULL)
{
	
}


cBST::~cBST(void)
{
	
}

void cBST::Insert(int n)
{
	//cNode *_cNode = new cNode;
	//Insert_2(m_pRoot, n);
	/*if (m_pRoot == NULL)
	{
		cNode *_cNode = new cNode;
		_cNode->m_nData = n;
		_cNode->m_pLChild = NULL;
		_cNode->m_pRChild = NULL;

		m_pRoot = _cNode;
	}
	else
	{
		
	}*/
	Insert_2_2(&m_pRoot, n);
}

void cBST::Insert_2(cNode *Target, int n)
{
	/*;*/
	
	//int data = Target->m_nData;

	//if (n < data)            // 값이 더 작으면
	//{
	//	if (Target->m_pLChild) Insert_2(Target->m_pLChild, n);
	//	else Target->m_pLChild = new cNode(n);
	//}
	//else if (n > data)         // 값이 더 크면
	//{
	//	if (Target->m_pRChild) Insert_2(Target->m_pRChild, n);
	//	else Target->m_pRChild = new cNode(n);
	//}
	
	/**/
}

void cBST::Insert_2_2(cNode ** Target, int n)
{
	if (*Target == NULL)
	{
		cNode *_cNode = new cNode;
		_cNode->m_nData = n;
		_cNode->m_pLChild = NULL;
		_cNode->m_pRChild = NULL;

		*Target = _cNode;
	}
	else if ((*Target)->m_nData == n)
	{
		return;
	}
	else if ((*Target)->m_nData < n)
	{
		Insert_2_2(&(*Target)->m_pRChild, n);
	}
	else if ((*Target)->m_nData > n)
	{
		Insert_2_2(&(*Target)->m_pLChild, n);
	}
}

cNode * cBST::find(cNode * _cNode, int n)
{
	if (_cNode == NULL)
	{
		return NULL;
	}
	else if (_cNode->m_nData == n)
	{
		return _cNode;
	}
	else if (_cNode->m_nData < n)
	{
		find(_cNode->m_pRChild, n);
	}
	else if (_cNode->m_nData > n)
	{
		find(_cNode->m_pLChild, n);
	}
}

tag_cNode_box * cBST::find_ver_02(cNode * _cNode, cNode * _pNode, int n)
{
	

	if (_cNode == NULL)
	{
		return NULL;
	}
	else if (_cNode->m_nData == n)
	{
		tag_cNode_box return_Item;
		return_Item.parent = _pNode;
		return_Item.Target = _cNode;
		return &return_Item;
	}
	else if (_cNode->m_nData < n)
	{
		find_ver_02(_cNode->m_pRChild, _cNode, n);
	}
	else if (_cNode->m_nData > n)
	{
		find_ver_02(_cNode->m_pLChild, _cNode, n);
	}
}

cNode * cBST::left_find(cNode * _cNode)
{
	if (_cNode->m_pLChild == NULL)
	{
		return _cNode;
	}
	else
	{
		return left_find(_cNode->m_pLChild);
	}
	
}

tag_cNode_box * cBST::left_find_ver_2(cNode * _cNode, cNode * _pNode)
{
	if (_cNode == NULL)
	{
		return NULL;
	}
	else if (_cNode->m_pLChild == NULL)
	{
		tag_cNode_box return_Item;
		return_Item.Target = _cNode;
		return_Item.parent = _pNode;
		return &return_Item;
	}
	else
	{
		return left_find_ver_2(_cNode->m_pLChild, _cNode);
	}
}





void cBST::Delete(int n)
{
	if (m_pRoot == NULL)return;
	if (!findNumber(m_pRoot, n))return;
	cNode *Delete_Node;
	cNode *PNode_Node;
	


	Delete_Node = find_ver_02(m_pRoot, NULL, n)->Target;
	PNode_Node = find_ver_02(m_pRoot, NULL, n)->parent;



	if (Delete_Node == m_pRoot)
	{

		if (Delete_Node->m_pLChild == NULL && Delete_Node->m_pRChild == NULL)
		{
			delete(Delete_Node);
			m_pRoot = NULL;
		}
		else if (Delete_Node->m_pRChild != NULL)
		{
			if (Delete_Node->m_pRChild->m_pLChild == NULL)
			{

				cNode *first;
				first = Delete_Node->m_pRChild;
				first->m_pLChild = Delete_Node->m_pLChild;

				m_pRoot = first;
				delete(Delete_Node);
			}
			else if (left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->Target != NULL)
			{
				cNode *first;

				first = left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->Target;
				left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->parent->m_pLChild = NULL;
				Delete_Node->m_nData = first->m_nData;
				delete(first);
			}
			else
			{
				cNode *first = Delete_Node->m_pLChild;
				m_pRoot = Delete_Node->m_pRChild;
				m_pRoot->m_pLChild = first;
				delete(Delete_Node);
			}
			
		}
		else if(Delete_Node->m_pRChild == NULL)
		{
			cNode *first;
			first = Delete_Node->m_pLChild;
			m_pRoot = first;
			delete(Delete_Node);
		}
	}
	else if (Delete_Node->m_pLChild == NULL && Delete_Node->m_pRChild == NULL)
	{
		if (PNode_Node->m_pLChild == Delete_Node)
		{
			PNode_Node->m_pLChild = NULL;
			delete(Delete_Node);
		}
		else
		{
			PNode_Node->m_pRChild = NULL;
			delete(Delete_Node);
		}
	}
	else if (Delete_Node->m_pLChild != NULL && Delete_Node->m_pRChild == NULL)
	{
		PNode_Node->m_pRChild = Delete_Node->m_pLChild;
		delete(Delete_Node);
	}
	else if (Delete_Node->m_pLChild == NULL && Delete_Node->m_pRChild != NULL)
	{
		if (Delete_Node->m_pRChild->m_pLChild == NULL)
		{

			cNode *first;
			first = Delete_Node->m_pRChild;
			first->m_pLChild = Delete_Node->m_pLChild;

			if (PNode_Node->m_pRChild == Delete_Node)
			{
				PNode_Node->m_pRChild = first;
			}
			else
			{
				PNode_Node->m_pLChild = first;
			}
			delete(Delete_Node);
		}
		else if (left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->Target != NULL)
		{
			cNode *first;
			first = left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->Target;
			left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->parent->m_pLChild = NULL;
			Delete_Node->m_nData = first->m_nData;
			delete(first);
		}
		else
		{
			cNode *first = Delete_Node;
			if (PNode_Node->m_pLChild == Delete_Node)
			{
				Delete_Node = Delete_Node->m_pRChild;
				PNode_Node->m_pLChild = Delete_Node;
			}
			else if (PNode_Node->m_pRChild == Delete_Node)
			{

				Delete_Node = Delete_Node->m_pRChild;
				PNode_Node->m_pRChild = Delete_Node;
			}
			
			delete(first);
		}
	}
	else if(Delete_Node->m_pLChild != NULL && Delete_Node->m_pRChild != NULL)
	{
		if (Delete_Node->m_pRChild->m_pLChild == NULL)
		{

			cNode *first;
			first = Delete_Node->m_pRChild;
			first->m_pLChild = Delete_Node->m_pLChild;
			if (PNode_Node->m_pLChild == Delete_Node)
			{
				Delete_Node->m_pRChild->m_pLChild = Delete_Node->m_pLChild;
				Delete_Node = Delete_Node->m_pRChild;
				PNode_Node->m_pLChild = first;
			}
			else if (PNode_Node->m_pRChild == Delete_Node)
			{
				Delete_Node->m_pRChild->m_pLChild = Delete_Node->m_pLChild;
				Delete_Node = Delete_Node->m_pRChild;
				PNode_Node->m_pRChild = first;
			}
			delete(Delete_Node);
		}
		else
		if (left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->Target != NULL)
		{
			cNode *first;
			first = left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->Target;
			left_find_ver_2(Delete_Node->m_pRChild->m_pLChild, Delete_Node->m_pRChild)->parent->m_pLChild = NULL;
			Delete_Node->m_nData = first->m_nData;
			delete(first);
		}
		else
		{
			cNode *first = Delete_Node;
			if (PNode_Node->m_pLChild == Delete_Node)
			{
				Delete_Node->m_pRChild->m_pLChild = Delete_Node->m_pLChild;
				Delete_Node = Delete_Node->m_pRChild;
				PNode_Node->m_pLChild = Delete_Node;
			}
			else if (PNode_Node->m_pRChild == Delete_Node)
			{
				Delete_Node->m_pRChild->m_pLChild = Delete_Node->m_pLChild;
				Delete_Node = Delete_Node->m_pRChild;
				PNode_Node->m_pRChild = Delete_Node;
			}
			delete(first);
		}
	}
}

void cBST::Print()
{
	Print_Left(m_pRoot);

}

void cBST::Print_Left(cNode *_cNode)
{
	if (m_pRoot == NULL)return;
	if (_cNode->m_pLChild != NULL)
	{
		Print_Left(_cNode->m_pLChild);
	}
	std::cout << _cNode->m_nData << std::endl;
	if (_cNode->m_pRChild != NULL)
	{
		Print_Left(_cNode->m_pRChild);
	}
}

void cBST::Print_Right(cNode _cNode)
{
}

bool cBST::findNumber(cNode * _cNode, int n)
{
	if (_cNode == NULL)
	{
		return false;
	}
	else if (_cNode->m_nData == n)
	{
		return true;
	}
	else
	{
		if (_cNode->m_nData < n)
		{
			return findNumber(_cNode->m_pRChild, n);
		}
		if (_cNode->m_nData > n)
		{
			return findNumber(_cNode->m_pLChild, n);
		}
	}
	return false;

}

void cBST::D(void)
{
	while (m_pRoot)
	{
		int data = m_pRoot->m_nData;
		Delete(data);
	}
}
