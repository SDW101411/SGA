#pragma once
#include "cScene.h"

/*2017-09-04 2�� 16��
cScene ��� ���踦 ���� �׽�Ʈ ���Դϴ�.*/ 

class cScene_Test_1:public cScene
{
public:
	cScene_Test_1();
	~cScene_Test_1();

	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

