#include "stdafx.h"
#include "cCloseOption.h"
#include "cUIImageView.h"
#include "cUITextView.h"

enum
{
	E_BG,
	E_CLOSE,
	E_CANCEL,
	E_TEXT_EXPLANATION,
};

cCloseOption::cCloseOption()
	: m_pUIRoot(NULL)
	, m_pSprite(NULL)
	, m_bOn(false)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetScaling(0.1f, 0.1f);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;	// "예" 버튼
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_bg.tga");
	pImageView->SetPosition(470, 250);
	pImageView->SetScaling(1.0f, 0.5f);
	pImageView->SetTag(E_BG);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_border_l.tga");
	pImageView->SetPosition(455.8f, 250);
	pImageView->SetScaling(1.0f, 0.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_border_r.tga");
	pImageView->SetPosition(939.4f, 250);
	pImageView->SetScaling(1.0f, 0.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_border_u.tga");
	pImageView->SetPosition(470, 236);
	pImageView->SetScaling(1.0f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_border_d.tga");
	pImageView->SetPosition(470, 420);
	pImageView->SetScaling(1.0f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_corner_lu.tga");
	pImageView->SetPosition(455.8f, 236);
	pImageView->SetScaling(1.0f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_corner_ld.tga");
	pImageView->SetPosition(455.8f, 420);
	pImageView->SetScaling(1.0f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_corner_ru.tga");
	pImageView->SetPosition(939.4f, 236);
	pImageView->SetScaling(1.0f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_window_corner_rd.tga");
	pImageView->SetPosition(939.4f, 420);
	pImageView->SetScaling(1.0f, 1.0f);
	m_pUIRoot->AddChild(pImageView);

	//////////////////////////////////////////////////////////////////////

	pImageView = new cUIImageView;	// "아니오" 버튼
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_l.tga");
	pImageView->SetPosition(546, 362);
	pImageView->SetScaling(1.5f, 9.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_r.tga");
	pImageView->SetPosition(670, 362);
	pImageView->SetScaling(1.5f, 9.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_u.tga");
	pImageView->SetPosition(552, 356);
	pImageView->SetScaling(30.0f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_d.tga");
	pImageView->SetPosition(552, 396);
	pImageView->SetScaling(30.0f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_lu.tga");
	pImageView->SetPosition(546, 356);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_ld.tga");
	pImageView->SetPosition(546, 396);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_ru.tga");
	pImageView->SetPosition(670, 356);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_rd.tga");
	pImageView->SetPosition(670, 396);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_l.tga");
	pImageView->SetPosition(734, 362);
	pImageView->SetScaling(1.5f, 9.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_r.tga");
	pImageView->SetPosition(858, 362);
	pImageView->SetScaling(1.5f, 9.0f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_u.tga");
	pImageView->SetPosition(740, 356);
	pImageView->SetScaling(30.0f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_border_d.tga");
	pImageView->SetPosition(740, 396);
	pImageView->SetScaling(30.0f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_lu.tga");
	pImageView->SetPosition(734, 356);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_ld.tga");
	pImageView->SetPosition(734, 396);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_ru.tga");
	pImageView->SetPosition(858, 356);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/Option/gui_amn_mm_button_up_corner_rd.tga");
	pImageView->SetPosition(858, 396);
	pImageView->SetScaling(1.5f, 1.5f);
	m_pUIRoot->AddChild(pImageView);

	cUIButton* pButton = new cUIButton;
	pButton->SetTexture("UI/Option/gui_amn_mm_button_up_bg.tga",
		"UI/Option/gui_amn_mm_button_up_bg.tga",
		"UI/Option/gui_amn_mm_button_up_bg.tga");
	pButton->SetPosition(550, 359);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_CLOSE);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/Option/gui_amn_mm_button_up_bg.tga",
		"UI/Option/gui_amn_mm_button_up_bg.tga",
		"UI/Option/gui_amn_mm_button_up_bg.tga");
	pButton->SetPosition(738, 359);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_CANCEL);
	m_pUIRoot->AddChild(pButton);

	cUITextView* pTextView = new cUITextView(cFontManager::E_OPTIONEXPLANATION);
	pTextView->SetText("메인메뉴로 돌아가시겠습니까? 저장되지 않은 데이터는 손실됩니다!");
	pTextView->SetSize(ST_SIZE(1000, 100));
	pTextView->SetPosition(200, 300);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_EXPLANATION);
	m_pUIRoot->AddChild(pTextView);

	pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("예");
	pTextView->SetSize(ST_SIZE(200, 100));
	pTextView->SetPosition(510, 370);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_EXPLANATION);
	m_pUIRoot->AddChild(pTextView);

	pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("아니오");
	pTextView->SetSize(ST_SIZE(200, 100));
	pTextView->SetPosition(698, 370);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_EXPLANATION);
	m_pUIRoot->AddChild(pTextView);
}

cCloseOption::~cCloseOption()
{
	SAFE_RELEASE(m_pUIRoot);
	SAFE_RELEASE(m_pSprite);
}

void cCloseOption::Update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_ESCAPE)) m_bOn = !m_bOn;
		
	if(m_bOn) SAFE_UPDATE(m_pUIRoot);
}

void cCloseOption::Render()
{
	if (m_bOn) if (m_pUIRoot) m_pUIRoot->Render(m_pSprite);
}

void cCloseOption::OnMouse(cUIButton* pSender)
{
}

void cCloseOption::OnClick(cUIButton* pSender)
{
	if (pSender->GetTag() == E_CLOSE)
	{
		// 처음 화면으로
		m_bOn = false;
		g_pSceneManager->SceneChange("cMainMenuScene");
		//PostQuitMessage(0);
	}
	else if (pSender->GetTag() == E_CANCEL)
	{
		m_bOn = false;
	}
}

void cCloseOption::OnRightClick(cUIButton* pSender)
{
}
