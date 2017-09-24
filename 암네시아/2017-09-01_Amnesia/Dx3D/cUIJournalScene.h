#pragma once

#include "cScene.h"

class IUI;

class cUIJournalScene : public cScene
{
private:
	IUI* m_pUI;

public:
	cUIJournalScene();
	~cUIJournalScene();

	void Setup();
	void Release();
	void Update();
	void Render();
};

