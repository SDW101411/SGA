#pragma once
#include "cScene.h"

/*2017-09-04 2시 16분
cScene 상속 관계를 위한 테스트 중입니다.*/ 

class cScene_Test_1:public cScene
{
public:
	cScene_Test_1();
	~cScene_Test_1();

	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

