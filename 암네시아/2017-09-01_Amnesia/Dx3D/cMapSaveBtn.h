#pragma once

#include "cMultiBtn.h"

class cMapTool;

class cMapSaveBtn : public cMultiBtn
{
protected:
	cMapTool* m_pMapTool;

public:
	void SetMapToolPointer(cMapTool* pMapTool);
	virtual void OnClick(cUIButton* pSender);
};