#include "stdafx.h"
#include "cBST.h"
#include <iostream>
#include <assert.h>

std::set<cNode*> g_setPool;

int _tmain(int argc, _TCHAR* argv[])
{
	cBST bst;
#ifdef DEBUG

#endif 

	int arr[100];

	for (int k = 0; k < 100; ++k)
	{
		for (int i = 0; i < 100; ++i)
		{
			arr[i] = rand() % 100;
			bst.Insert(arr[i]);
		}

		for (int i = 0; i < 1000; ++i)
		{
			int n1 = rand() % 100;
			int n2 = rand() % 100;
			int n = arr[n1];
			arr[n1] = arr[n2];
			arr[n2] = n;
		}

		for (int i = 0; i < 100; ++i)
		{
			bst.Delete(arr[i]);
		}
	}

	for (int i = 0; i < 10; ++i)
	{
		arr[i] = rand() % 10;
		bst.Insert(arr[i]);
	}
	bst.Print();
	for (int i = 0; i < 10; ++i)
	{
		bst.Delete(arr[i]);
	}

	assert(g_setPool.empty() && "삭제되지 않은 노드가 있음.");

	return 0;
}
