#include "stdafx.h"
#include "cUIToolTestScene.h"
#include "cUITool.h"
#include "cUIImageView.h"
#include "cUITextView.h"

enum
{
	E_HEART		= 213,
	E_BRAIN		= 214,
	E_TINDER	= 215,
	E_TEXT_VIEW,
};

cUIToolTestScene::cUIToolTestScene()
	//: m_pUITool(NULL)
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	//m_pUITool = new cUITool;
	//m_pUITool->Setup();

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI.png");
	pImageView->SetScaling(0.595f, 0.5f);
 	m_pUIRoot = pImageView;

	cUIButton* pButton = new cUIButton;
	/*pButton->SetTexture("UI/heart.png",
		"UI/heart.png",
		"UI/heart.png");*/
	pButton->SetTexture("UI/inventory_health_100.tga",
		"UI/inventory_health_100.tga",
		"UI/inventory_health_100.tga");
	pButton->SetPosition(190, 80);
	//pButton->SetScaling(0.54f, 0.54f);
	pButton->SetScaling(0.9f, 0.9f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_HEART);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/inventory_sanity_100.tga",
		"UI/inventory_sanity_100.tga",
		"UI/inventory_sanity_100.tga");
	pButton->SetPosition(206, 280);
	pButton->SetScaling(0.9f, 0.9f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_BRAIN);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/inventory_tinderboxes.tga",
		"UI/inventory_tinderboxes.tga",
		"UI/inventory_tinderboxes.tga");
	pButton->SetPosition(865, 80);
	pButton->SetScaling(0.9f, 0.9f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_TINDER);
	m_pUIRoot->AddChild(pButton);
	
	cUITextView* pTextView = new cUITextView;
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(420, 380);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);

	pTextView = new cUITextView;
	pTextView->SetText("x 1");
	pTextView->SetSize(ST_SIZE(40, 20));
	pTextView->SetPosition(870, 100);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);
}

cUIToolTestScene::~cUIToolTestScene()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
	//SAFE_DELETE(m_pUITool);
}

void cUIToolTestScene::Update()
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	if (pTextView) pTextView->SetText("");

	if (m_pUIRoot) m_pUIRoot->Update();
}

void cUIToolTestScene::Render()
{
	//SAFE_RENDER(m_pUITool);

	if(KEYMANAGER->isToggleKey(VK_TAB))
	{
		m_pUIRoot->Render(m_pSprite);
	}
}


void cUIToolTestScene::OnClick(cUIButton* pSender)
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	if (pTextView == NULL) return;

	if (pSender->GetTag() == E_HEART)
	{
		pTextView->SetText("체력");
	}
	else if (pSender->GetTag() == E_BRAIN)
	{
		pTextView->SetText("정신력\n\n깔끔하다");
	}
	else if (pSender->GetTag() == E_TINDER)
	{
		pTextView->SetText("틴더");
	}
}