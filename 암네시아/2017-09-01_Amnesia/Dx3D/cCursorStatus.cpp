#include "stdafx.h"
#include "cCursorStatus.h"
#include "cUIImageView.h"

enum
{
	E_STATUS,
};

cCursorStatus::cCursorStatus()
	: m_pUIRoot(NULL)
	, m_pSprite(NULL)
	, cursorStatus(CUR_NORMAL)
	//, m_nStatus(0)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetScaling(0.75f, 0.65f);
	m_pUIRoot = pImageView;
}

cCursorStatus::~cCursorStatus()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cCursorStatus::Update()
{
	/*switch (m_nStatus)
	{
	case 0:
		CursorStatus(CUR_NORMAL);
		break;
	case 1:
		CursorStatus(CUR_PICKUP);
		break;
	case 2:
		CursorStatus(CUR_OPEN);
		break;
	case 3:
		CursorStatus(CUR_IGNITE);
		break;
	}

	if (KEYMANAGER->isOnceKeyDown('T')) m_nStatus--;
	if (KEYMANAGER->isOnceKeyDown('Y')) m_nStatus++;*/

	SAFE_UPDATE(m_pUIRoot);
}

void cCursorStatus::Render()
{
	m_pUIRoot->Render(m_pSprite);
}

void cCursorStatus::CursorStatus(int tag)
{
	cUIImageView* pImageView = (cUIImageView*)m_pUIRoot->GetChildByTag(E_STATUS);
	
	switch (tag)
	{
	case CUR_NORMAL:
		pImageView->SetTexture("UI/hud/normal.png");
		pImageView->SetScaling(1.0f, 1.0f);
		pImageView->SetPosition(708, 346);
		break;
	case CUR_PICKUP:
		pImageView->SetTexture("UI/hud/hud_crosshair_over_pick.tga");
		pImageView->SetScaling(1.0f, 1.0f);
		pImageView->SetPosition(704, 324);
		break;
	case CUR_OPEN:
		pImageView->SetTexture("UI/hud/hud_crosshair_over_push.tga");
		pImageView->SetScaling(1.0f, 1.0f);
		pImageView->SetPosition(704, 324);
		break;
	case CUR_IGNITE:
		pImageView->SetTexture("UI/hud/hud_crosshair_over_ignite.tga");
		pImageView->SetScaling(1.0f, 1.0f);
		pImageView->SetPosition(704, 324);
		break;
	}
}