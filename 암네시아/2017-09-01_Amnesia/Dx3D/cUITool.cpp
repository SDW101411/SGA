#include "stdafx.h"
#include "cUITool.h"
#include "cUIImageView.h"

cUITool::cUITool()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);
	InventoryBorder();
	HealthBorder();
	SanityBorder();
	ExplanationBorder();
	TinderBoxBorder();
	OilBorder();
	JournalBorder();
}

cUITool::~cUITool()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cUITool::InventoryBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetScaling(0.75f, 0.65f);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_u.tga");
	pImageView->SetPosition(437.5f, 45.8f);
	pImageView->SetScaling(8.79f, 1.54f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_l.tga");
	pImageView->SetPosition(406, 77.4f);
	pImageView->SetScaling(1.5f, 2.86f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_r.tga");
	pImageView->SetPosition(1000, 77.4f);
	pImageView->SetScaling(1.5f, 2.86f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_d.tga");
	pImageView->SetPosition(437.4f, 419.6f);
	pImageView->SetScaling(8.79f, 1.54f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ru.tga");
	pImageView->SetPosition(1000, 46);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_rd.tga");
	pImageView->SetPosition(1000, 420.4f);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_lu.tga");
	pImageView->SetPosition(406.0f, 46);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ld.tga");
	pImageView->SetPosition(406.0f, 420);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::HealthBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_border_u.tga");
	pImageView->SetPosition(252.0f, 76.8f);
	pImageView->SetScaling(1.7f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_border_l.tga");
	pImageView->SetPosition(226.0f, 102.4f);
	pImageView->SetScaling(1.2f, 1.7f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_border_r.tga");
	pImageView->SetPosition(390.0f, 101.4f);
	pImageView->SetScaling(1.2f, 1.63f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_border_d.tga");
	pImageView->SetPosition(252.0f, 287.0f);
	pImageView->SetScaling(1.63f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_corner_ru.tga");
	pImageView->SetPosition(390.0f, 74.6f);
	pImageView->SetScaling(1.2f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_corner_rd.tga");
	pImageView->SetPosition(389.8f, 287.2f);
	pImageView->SetScaling(1.2f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_corner_lu.tga");
	pImageView->SetPosition(227.4f, 77.9f);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_health_corner_ld.tga");
	pImageView->SetPosition(227.4f, 289);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::SanityBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_border_u.tga");
	pImageView->SetPosition(255.0f, 350.0f);
	pImageView->SetScaling(1.65f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_border_l.tga");
	pImageView->SetPosition(227.0f, 379.4f);
	pImageView->SetScaling(1.15f, 1.73f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_border_r.tga");
	pImageView->SetPosition(384.4f, 379.4f);
	pImageView->SetScaling(1.1f, 1.72f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_border_d.tga");
	pImageView->SetPosition(256.0f, 600.0f);
	pImageView->SetScaling(1.64f, 1.2f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_corner_ru.tga");
	pImageView->SetPosition(384.4f, 350.0f);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_corner_rd.tga");
	pImageView->SetPosition(384.4f, 601.0f);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_corner_lu.tga");
	pImageView->SetPosition(227.4f, 350.0f);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_sanity_corner_ld.tga");
	pImageView->SetPosition(227.9f, 601);
	pImageView->SetScaling(1.1f, 1.1f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::ExplanationBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_u.tga");
	pImageView->SetPosition(436.5f, 467.4f);
	pImageView->SetScaling(8.86f, 1.30f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_l.tga");
	pImageView->SetPosition(410, 494.5f);
	pImageView->SetScaling(1.25f, 1.08f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_r.tga");
	pImageView->SetPosition(1004, 496.5f);
	pImageView->SetScaling(1.25f, 1.06f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_d.tga");
	pImageView->SetPosition(436.2f, 624.2f);
	pImageView->SetScaling(8.87f, 1.25f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ru.tga");
	pImageView->SetPosition(1004, 467.0f);
	pImageView->SetScaling(1.25f, 1.36f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_rd.tga");
	pImageView->SetPosition(1004, 624.0f);
	pImageView->SetScaling(1.25f, 1.25f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_lu.tga");
	pImageView->SetPosition(410.0f, 468);
	pImageView->SetScaling(1.25f, 1.25f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ld.tga");
	pImageView->SetPosition(410.0f, 624);
	pImageView->SetScaling(1.25f, 1.25f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::TinderBoxBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_u.tga");
	pImageView->SetPosition(1052.5f, 69.0f);
	pImageView->SetScaling(1.97f, 1.12f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_l.tga");
	pImageView->SetPosition(1028, 91.2f);
	pImageView->SetScaling(1.15f, 0.91f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_r.tga");
	pImageView->SetPosition(1179.0f, 95.5f);
	pImageView->SetScaling(1.15f, 0.86f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_d.tga");
	pImageView->SetPosition(1052.5f, 198.0f);
	pImageView->SetScaling(1.97f, 1.15f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ru.tga");
	pImageView->SetPosition(1179.0f, 68.4f);
	pImageView->SetScaling(1.15f, 1.25f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_rd.tga");
	pImageView->SetPosition(1179.0f, 198.6f);
	pImageView->SetScaling(1.15f, 1.12f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_lu.tga");
	pImageView->SetPosition(1028.0f, 70);
	pImageView->SetScaling(1.15f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ld.tga");
	pImageView->SetPosition(1028.0f, 200);
	pImageView->SetScaling(1.15f, 1.0f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::OilBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_u.tga");
	pImageView->SetPosition(1052.5f, 247.0f);
	pImageView->SetScaling(1.97f, 1.12f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_l.tga");
	pImageView->SetPosition(1028, 269.5f);
	pImageView->SetScaling(1.15f, 1.25f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_r.tga");
	pImageView->SetPosition(1179.0f, 272.5f);
	pImageView->SetScaling(1.15f, 1.21f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_d.tga");
	pImageView->SetPosition(1052.5f, 417.0f);
	pImageView->SetScaling(1.97f, 1.15f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ru.tga");
	pImageView->SetPosition(1179.0f, 246.2f);
	pImageView->SetScaling(1.15f, 1.25f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_rd.tga");
	pImageView->SetPosition(1179.0f, 417.2f);
	pImageView->SetScaling(1.15f, 1.12f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_lu.tga");
	pImageView->SetPosition(1028.0f, 247.8f);
	pImageView->SetScaling(1.15f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ld.tga");
	pImageView->SetPosition(1028.0f, 419);
	pImageView->SetScaling(1.15f, 1.0f);
	m_pUIRoot->AddChild(pImageView);
}

void cUITool::JournalBorder()
{
	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_u.tga");
	pImageView->SetPosition(1055.5f, 472.0f);
	pImageView->SetScaling(1.97f, 1.12f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_l.tga");
	pImageView->SetPosition(1031, 494.5f);
	pImageView->SetScaling(1.15f, 0.98f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_r.tga");
	pImageView->SetPosition(1182.6f, 498.5f);
	pImageView->SetScaling(1.15f, 0.93f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_border_d.tga");
	pImageView->SetPosition(1055.5f, 610.0f);
	pImageView->SetScaling(1.97f, 1.15f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ru.tga");
	pImageView->SetPosition(1182.5f, 471.4f);
	pImageView->SetScaling(1.15f, 1.25f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_rd.tga");
	pImageView->SetPosition(1182.5f, 610.4f);
	pImageView->SetScaling(1.15f, 1.12f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_lu.tga");
	pImageView->SetPosition(1031.0f, 472.6f);
	pImageView->SetScaling(1.15f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/border/inventory_frame_generic_corner_ld.tga");
	pImageView->SetPosition(1031.0f, 612);
	pImageView->SetScaling(1.15f, 1.0f);
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
