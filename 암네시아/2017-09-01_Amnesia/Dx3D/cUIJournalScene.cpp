#include "stdafx.h"
#include "cUIJournalScene.h"
#include "cUIJournal.h"
#include "IUI.h"

cUIJournalScene::cUIJournalScene()
{
	m_pUI = new cUIJournal;
}

cUIJournalScene::~cUIJournalScene()
{
	SAFE_DELETE(m_pUI);
}

void cUIJournalScene::Setup()
{
}

void cUIJournalScene::Release()
{
}

void cUIJournalScene::Update()
{
	SAFE_UPDATE(m_pUI);
}

void cUIJournalScene::Render()
{
	SAFE_RENDER(m_pUI);
}
