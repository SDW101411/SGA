#include "stdafx.h"
#include "cMouseCursor.h"
#include "cUIImageView.h"

enum
{
	E_CURSOR
};

cMouseCursor::cMouseCursor()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/hud/gui_amn_mm_pointer_normal.tga");
	pImageView->SetPosition(_ptMousePos.x, _ptMousePos.y);
	pImageView->SetScaling(1.0f, 1.0f);
	pImageView->SetTag(E_CURSOR);
	m_pUIRoot = pImageView;
}

cMouseCursor::~cMouseCursor()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cMouseCursor::Update()
{
	cUIImageView* pImageView = (cUIImageView*)m_pUIRoot->GetChildByTag(E_CURSOR);
	pImageView->SetPosition(_ptMousePos.x, _ptMousePos.y);

	SAFE_UPDATE(m_pUIRoot);
}

void cMouseCursor::Render()
{
	m_pUIRoot->Render(m_pSprite);
}
