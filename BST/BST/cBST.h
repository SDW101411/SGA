#pragma once

class cNode;

struct tag_cNode_box
{
	cNode *parent;
	cNode *Target;
};

class cBST
{
private:
	cNode* m_pRoot;
public:
	cBST(void);
	~cBST(void);

	void Insert(int n);
	void Insert_2(cNode *Target, int n);
	void Insert_2_2(cNode **Target, int n);
	cNode *find(cNode *_cNode,int n);
	tag_cNode_box *find_ver_02(cNode *_cNode, cNode*_pNode, int n);
	cNode *left_find(cNode *_cNode);
	tag_cNode_box *left_find_ver_2(cNode * _cNode, cNode * _pNode);



	void Delete(int n);
	void Print();
	void Print_Left(cNode *_cNode);
	void Print_Right(cNode _cNode);
	bool findNumber(cNode *_cNode, int n);

	void D(void);
};

