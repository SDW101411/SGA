#pragma once
#include "cCamera.h"

class cMenuCamera : public cCamera
{
public:
	cMenuCamera();
	virtual ~cMenuCamera();

	virtual void Update();
};