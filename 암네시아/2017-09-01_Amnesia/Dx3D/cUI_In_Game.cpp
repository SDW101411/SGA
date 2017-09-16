#include "stdafx.h"
#include "cUI_In_Game.h"
#include "cUIImageView.h"
#include "cUITextView.h"

enum
{
	E_BACKGROUND		= 211,
	E_BORDER			= 212,
	E_HEART				= 213,
	E_HEART_UP			= 214,
	E_BRAIN				= 215,
	E_BRAIN_UP			= 216,
	E_TINDER			= 217,
	E_JOURNAL			= 218,
	E_RANTERNSHAPE		= 219,
	E_OIL				= 220,
	E_TEXT_VIEW,
	E_TEXT_VIEW_2,
	E_TEXT_TINDER_NUM,
};

cUI_In_Game::cUI_In_Game()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
	, m_szHeartState("\0")
	, m_szHeartGlowState("\0")
	, m_szBrainState("\0")
	, m_szTinderNum("\0")
	, m_nTinderNum(0)
	, m_nHeartHP(100)
	, m_nBrainHP(100)
	, m_fOilValue(0.5f)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI_bg.png");
	pImageView->SetScaling(0.75f, 0.65f);
	pImageView->SetTag(E_BACKGROUND);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI_border.png");
	pImageView->SetScaling(0.75f, 0.65f);
	pImageView->SetTag(E_BORDER);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;		//기름 이미지로
	pImageView->SetTexture("UI/inventory_oil_liquid.tga");
	pImageView->SetPosition(1138, 390);
	pImageView->SetScaling(0.5f, m_fOilValue);
	pImageView->SetRotationX(D3DX_PI);
	pImageView->SetTag(E_OIL);
	m_pUIRoot->AddChild(pImageView);

	sprintf(m_szHeartState, "UI/inventory_health_%d.tga", m_nHeartHP);
	cUIButton* pButton = new cUIButton;
	pButton->SetTexture(m_szHeartState,
		m_szHeartState,
		m_szHeartState);
	pButton->SetPosition(244, 100);
	//pButton->SetScaling(0.54f, 0.54f);
	pButton->SetScaling(1.1f, 1.1f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_HEART);
	m_pUIRoot->AddChild(pButton);

	sprintf(m_szHeartGlowState, "UI/inventory_health_glow_%d.tga", m_nHeartHP);
	cUIButton* pButton_2 = new cUIButton;
	pButton_2->SetTexture(m_szHeartState,
		m_szHeartGlowState,
		m_szHeartState);
	pButton_2->SetPosition(244, 100);
	pButton_2->SetScaling(1.1f, 1.1f);
	pButton_2->SetDelegate(this);
	pButton_2->SetTag(E_HEART_UP);
	m_pUIRoot->AddChild(pButton_2);

	sprintf(m_szBrainState, "UI/inventory_sanity_%d.tga", m_nBrainHP);
	pButton = new cUIButton;
	pButton->SetTexture(m_szBrainState,
		m_szBrainState,
		m_szBrainState);
	pButton->SetPosition(254, 380);
	pButton->SetScaling(1.1f, 1.1f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_BRAIN);
	m_pUIRoot->AddChild(pButton);

	sprintf(m_szBrainGlowState, "UI/inventory_sanity_glow_%d.tga", m_nBrainHP);
	pButton = new cUIButton;
	pButton->SetTexture(m_szBrainState,
		m_szBrainGlowState,
		m_szBrainState);
	pButton->SetPosition(254, 380);
	pButton->SetScaling(1.1f, 1.1f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_BRAIN_UP);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/inventory_tinderboxes.tga",
		"UI/inventory_tinderboxes.tga",
		"UI/inventory_tinderboxes.tga");
	pButton->SetPosition(1094, 110);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_TINDER);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;
	pButton->SetTexture("UI/inventory_journal.tga",
		"UI/inventory_journal.tga",
		"UI/inventory_journal.tga");
	pButton->SetPosition(1070, 496);
	pButton->SetScaling(1.1f, 1.1f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_JOURNAL);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;			// 마우스 오버 시 노란 테두리 용
	pButton->SetTexture("UI/inventory_journal.tga",
		"UI/inventory_journal_mouse_over.tga",
		"UI/inventory_journal.tga");
	pButton->SetPosition(1070, 496);
	pButton->SetScaling(1.1f, 1.1f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_JOURNAL);
	m_pUIRoot->AddChild(pButton);

	/*pButton = new cUIButton;			// 기름 버튼 화
	pButton->SetTexture("UI/inventory_oil_liquid.tga",
	"UI/inventory_oil_liquid.tga",
	"UI/inventory_oil_liquid.tga");
	pButton->SetPosition(1136, 390);
	pButton->SetScaling(0.5f, m_fOilValue);
	pButton->SetRotationX(D3DX_PI);
	pButton->SetDelegate(this);
	pButton->SetTag(E_OIL);
	m_pUIRoot->AddChild(pButton);*/

	pButton = new cUIButton;			// 랜턴 기름 틀
	pButton->SetTexture("UI/inventory_oil_fg.tga",
		"UI/inventory_oil_fg.tga",
		"UI/inventory_oil_fg.tga");
	pButton->SetPosition(1088, 288);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_RANTERNSHAPE);
	m_pUIRoot->AddChild(pButton);

	cUITextView* pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(566, 494);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);

	pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(450, 100));
	pTextView->SetPosition(440, 546);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW_2);
	m_pUIRoot->AddChild(pTextView);

	sprintf(m_szTinderNum, "x %d", m_nTinderNum);
	pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText(m_szTinderNum);
	pTextView->SetSize(ST_SIZE(40, 20));
	pTextView->SetPosition(1102, 136);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_TINDER_NUM);
	m_pUIRoot->AddChild(pTextView);
}

cUI_In_Game::~cUI_In_Game()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cUI_In_Game::Update()
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	cUITextView* pTextView_2 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW_2);
	if (pTextView) pTextView->SetText("");
	if (pTextView_2) pTextView_2->SetText("");

	pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_TINDER_NUM);
	sprintf(m_szTinderNum, "x %d", m_nTinderNum);
	pTextView->SetText(m_szTinderNum);
	if (m_nTinderNum <= 0) m_nTinderNum = 0;

	sprintf(m_szHeartState, "UI/inventory_health_%d.tga", m_nHeartHP);
	cUIButton* pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_HEART);
	if (pButton) pButton->SetTexture(m_szHeartState,
		m_szHeartState,
		m_szHeartState);

	sprintf(m_szHeartGlowState, "UI/inventory_health_glow_%d.tga", m_nHeartHP);
	cUIButton* pButton_2 = (cUIButton*)m_pUIRoot->GetChildByTag(E_HEART_UP);
	if (pButton_2) pButton_2->SetTexture(m_szHeartState,
		m_szHeartGlowState,
		m_szHeartState);

	sprintf(m_szBrainState, "UI/inventory_sanity_%d.tga", m_nBrainHP);
	pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_BRAIN);
	if (pButton) pButton->SetTexture(m_szBrainState,
		m_szBrainState,
		m_szBrainState);

	sprintf(m_szBrainGlowState, "UI/inventory_sanity_glow_%d.tga", m_nBrainHP);
	pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_BRAIN_UP);
	if (pButton) pButton->SetTexture(m_szBrainState,
		m_szBrainGlowState,
		m_szBrainState);

	pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_OIL);
	if (pButton)
	{
		if (m_fOilValue >= 0.5f) m_fOilValue = 0.5f;
		else if (m_fOilValue <= 0.0f) m_fOilValue = 0.0f;
		pButton->SetScaling(0.5f, m_fOilValue);
	}

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		m_nHeartHP -= 25;
		m_nBrainHP -= 25;
		m_nTinderNum--;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		m_nHeartHP += 25;
		m_nBrainHP += 25;
		m_nTinderNum++;
	}
	if (KEYMANAGER->isStayKeyDown('F'))
	{
		m_fOilValue += 0.0001f;
	}
	if (KEYMANAGER->isStayKeyDown('V'))
	{
		m_fOilValue -= 0.0001f;
	}

	SAFE_UPDATE(m_pUIRoot);
}

void cUI_In_Game::Render()
{
	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
	}
	else
	{
		m_pUIRoot->Render(m_pSprite);
	}
}

void cUI_In_Game::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
}

void cUI_In_Game::OnMouse(cUIButton* pSender)
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	cUITextView* pTextView_2 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW_2);
	if (pTextView == NULL) return;

	if (pSender->GetTag() == E_HEART || pSender->GetTag() == E_HEART_UP)
	{
		pTextView->SetText("체력");
		switch (m_nHeartHP)
		{
		case 100: pTextView_2->SetText("전체적으로 좋다.");				break;
		case  75: pTextView_2->SetText("약간의 타박상이 있다.");			break;
		case  50: pTextView_2->SetText("상처에서 출혈이 너무 심해.");		break;
		case  25: pTextView_2->SetText("간신히 살아있다.");				break;
		}
	}
	else if (pSender->GetTag() == E_BRAIN || pSender->GetTag() == E_BRAIN_UP)
	{
		pTextView->SetText("정신도");
		switch (m_nBrainHP)
		{
		case 100: pTextView_2->SetText("깔끔하다.");						break;
		case  75: pTextView_2->SetText("약간의 투통이 있다.");			break;
		case  50: pTextView_2->SetText("제정신이 아니야, 손이 떨려.");	break;
		case  25: pTextView_2->SetText("...");							break;
		}
	}
	else if (pSender->GetTag() == E_TINDER)
	{
		pTextView->SetText("Tinderboxes");
		pTextView_2->SetText("주변에 불이 붙는 곳에 점화 할 수 있다.");
	}
	else if (pSender->GetTag() == E_JOURNAL)
	{
		pTextView->SetText("저널");
		pTextView_2->SetText("주운 모든 메모가 들어있어, 클릭하면 열린다.");
	}
	else if (pSender->GetTag() == E_RANTERNSHAPE)
	{
		pTextView->SetText("기름");
		pTextView_2->SetText("기름이 남아있는 한, 랜턴을 켤 수 있다. 하지만 다 쓰면 못 쓰게 돼버린다.");
	}
}

void cUI_In_Game::OnClick(cUIButton* pSender)
{
	/*cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
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
	}*/
}
