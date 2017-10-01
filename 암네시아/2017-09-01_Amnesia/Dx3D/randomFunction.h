#pragma once

//=================================================
//======= ## 20170413 randomFunciton ## =========== 
//=================================================

#include "singletonBase.h"
#include "stdafx.h"
//#include <time.h>

class randomFunction : public singletonBase <randomFunction>
{
public:
	randomFunction(void)
	{
		//		srand((unsigned int)time(NULL)); //1�ʿ� �ѹ��� ����
		srand((unsigned int)GetTickCount()); //20���� 1�ʿ� �ѹ��� ����..
											 //�и�����...!!!! ��ǻ�Ͱ� �������ڸ��� ��� �����ϴ� �ð�..
	}
	~randomFunction(void)
	{
	}

	//getInt
	int getInt(int num) { return rand() % num; }
	int getFromIntTo(int fromNum, int toNum)
	{
		return rand() % (toNum - fromNum + 1) + fromNum;
	}

	//���� 1��!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	//getFloat ���� : 0.0 ~ 1.0 �Ǽ�
	float getFloat(void)
	{
		return ((float)rand() / (float)RAND_MAX);
	}

	//���� : �� 100 -> 0 ~ 100.0 �Ǽ�
	float getFloat(float num)
	{
		return ((float)rand() / (float)RAND_MAX) * num;
	}

	float getFromFloatTo(float fromFloat, float toFloat)
	{
		float rnd = (float)rand() / (float)RAND_MAX;
		return (rnd * (toFloat - fromFloat) + fromFloat);
	}
};
