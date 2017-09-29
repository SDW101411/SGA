#pragma once
#include "cScene.h"

class cGridNode;
class cAStar;

class cAStarScene : public cScene
{
private:
	cAStar*		m_pAStar;

public:
	cAStarScene();
	virtual ~cAStarScene();

	virtual void Setup();
	virtual void Release();
	virtual void Update();
	virtual void Render();

	static void CleanNodeFunc(LPCVOID param);
};