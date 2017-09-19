#include "stdafx.h"
#include "cUITool.h"
//#include "cUIGrid.h"
#include "cUIImageView.h"

cUITool::cUITool()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);
	GenericBorder();
	HealthBorder();
	SanityBorder();
}

cUITool::~cUITool()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cUITool::GenericBorder()
{

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetScaling(0.75f, 0.65f);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_border_u.tga");
	pImageView->SetPosition(437.5f, 45.8f);
	pImageView->SetScaling(8.79f, 1.54f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_border_l.tga");
	pImageView->SetPosition(406, 77.4f);
	pImageView->SetScaling(1.5f, 2.86f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_border_r.tga");
	pImageView->SetPosition(1000, 77.4f);
	pImageView->SetScaling(1.5f, 2.86f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_border_d.tga");
	pImageView->SetPosition(437.4f, 419.6f);
	pImageView->SetScaling(8.79f, 1.54f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_corner_ru.tga");
	pImageView->SetPosition(1000, 46);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_corner_rd.tga");
	pImageView->SetPosition(1000, 420.4f);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_corner_lu.tga");
	pImageView->SetPosition(406.0f, 46);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_generic_corner_ld.tga");
	pImageView->SetPosition(406.0f, 420);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::HealthBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_border_u.tga");
	pImageView->SetPosition(252.0f, 76.8f);
	pImageView->SetScaling(1.7f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_border_l.tga");
	pImageView->SetPosition(226.0f, 102.4f);
	pImageView->SetScaling(1.2f, 1.7f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_border_r.tga");
	pImageView->SetPosition(390.0f, 101.4f);
	pImageView->SetScaling(1.2f, 1.63f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_border_d.tga");
	pImageView->SetPosition(252.0f, 287.0f);
	pImageView->SetScaling(1.63f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_corner_ru.tga");
	pImageView->SetPosition(390.0f, 74.6f);
	pImageView->SetScaling(1.2f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_corner_rd.tga");
	pImageView->SetPosition(389.8f, 287.2f);
	pImageView->SetScaling(1.2f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_corner_lu.tga");
	pImageView->SetPosition(227.4f, 77.9f);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_corner_ld.tga");
	pImageView->SetPosition(227.4f, 289);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::SanityBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_sanity_border_u.tga");
	pImageView->SetPosition(255.0f, 350.0f);
	pImageView->SetScaling(1.65f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_sanity_border_l.tga");
	pImageView->SetPosition(227.0f, 379.4f);
	pImageView->SetScaling(1.15f, 1.73f);
	m_pUIRoot->AddChild(pImageView);

	/*pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_border_r.tga");
	pImageView->SetPosition(390.0f, 101.4f);
	pImageView->SetScaling(1.2f, 1.63f);
	m_pUIRoot->AddChild(pImageView);*/

	/*pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_border_d.tga");
	pImageView->SetPosition(252.0f, 287.0f);
	pImageView->SetScaling(1.63f, 1.2f);
	m_pUIRoot->AddChild(pImageView);*/

	/*pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_corner_ru.tga");
	pImageView->SetPosition(390.0f, 74.6f);
	pImageView->SetScaling(1.2f, 1.2f);
	m_pUIRoot->AddChild(pImageView);*/

	/*pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_health_corner_rd.tga");
	pImageView->SetPosition(389.8f, 287.2f);
	pImageView->SetScaling(1.2f, 1.2f);
	m_pUIRoot->AddChild(pImageView);*/

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_sanity_corner_lu.tga");
	pImageView->SetPosition(227.4f, 350.0f);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/inventory_frame_sanity_corner_ld.tga");
	pImageView->SetPosition(227.9f, 601);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::Update()
{
	SAFE_UPDATE(m_pUIRoot);
}

void cUITool::Render()
{
	m_pUIRoot->Render(m_pSprite);
}
