// LinkedList.cpp : 콘솔 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "cLinkedList.h"

int _tmain(int argc, _TCHAR* argv[])
{
	cLinkedList ll;


	char ccc[256];
	FILE* file1 = fopen("data.txt", "r");
	while (!feof(file1))
	{

		fgets(ccc, 256, file1);

		if (ccc[0] == 'i')
		{
			int i = 0;
			while (true)
			{
				if (ccc[i] == ':')
				{
					ccc[i] = '0';
					break;
				}
				ccc[i] = '0';
				i++;
			}
			if (ccc[2] == '-')
			{
				ccc[0] = '-';
				ccc[2] = '0';
			}
			ll.Insert(atoi(ccc));
		}
		else if (ccc[0] == 'd')
		{
			int i = 0;
			while (true)
			{
				if (ccc[i] == ':')
				{
					ccc[i] = '0';
					break;
				}
				ccc[i] = '0';
				i++;
			}
			if (ccc[2] == '-')
			{
				ccc[0] = '-';
				ccc[2] = '0';
			}
			ll.Delete(atoi(ccc));
		}

		else if (ccc[0] == 'd')
		{
			int i = 0;
			while (true)
			{
				if (ccc[i] == ':')
				{
					ccc[i] = '0';
					break;
				}
				ccc[i] = '0';
				i++;
			}
			if (ccc[2] == '-')
			{
				ccc[0] = '-';
				ccc[2] = '0';
			}
			ll.Delete(atoi(ccc));
		}

		else if (ccc[0] == 'p')
		{
			ll.Print();
		}

		else if (ccc[0] == 'r')
		{
			ll.Reverse();
		}

	}

	fclose(file1);
	return 0;
}

