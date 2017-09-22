#include "stdafx.h"
#include "cUI_In_Game.h"
#include "cUIImageView.h"
#include "cUITextView.h"
#include "cUITool.h"
#include "cUIGrid.h"

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
	E_TEXT_VIEW_3,
	E_TEXT_MOUSEPOS,
	E_TEXT_PTINRECT,
	E_ROW_COL,
	E_TEXT_ITEM_NUM,
	E_TEXT_TINDER_NUM,
};

cUI_In_Game::cUI_In_Game()
	: m_pSprite(NULL)
	, m_pUIRoot(NULL)
	, m_curClickItem(NULL)
	, m_szHeartState("\0")
	, m_szHeartGlowState("\0")
	, m_szBrainState("\0")
	, m_szTinderNum("\0")
	, m_nHeartHP(100)
	, m_nBrainHP(90)
	, m_fOilValue(0.5f)
	, m_pBorder(NULL)
	, m_nRow(0)
	, m_nCol(0)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI_bg.png");
	pImageView->SetScaling(0.75f, 0.65f);
	pImageView->SetTag(E_BACKGROUND);
	m_pUIRoot = pImageView;

	/*pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI_border.png");
	pImageView->SetScaling(0.75f, 0.65f);
	pImageView->SetTag(E_BORDER);
	m_pUIRoot->AddChild(pImageView);*/

	m_pBorder = new cUITool;

	pImageView = new cUIImageView;		// 인벤 그리드
	pImageView->SetTexture("UI/border.png");
	pImageView->SetPosition(422, 60);
	pImageView->SetScaling(0.76f, 0.66f);
	m_pUIRoot->AddChild(pImageView);

	pImageView = new cUIImageView;		// 기름 이미지
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

	pButton = new cUIButton;			// 랜턴 기름 틀
	pButton->SetTexture("UI/inventory_oil_fg.tga",
		"UI/inventory_oil_fg.tga",
		"UI/inventory_oil_fg.tga");
	pButton->SetPosition(1088, 288);
	pButton->SetScaling(1.0f, 1.0f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_RANTERNSHAPE);
	m_pUIRoot->AddChild(pButton);

	pButton = new cUIButton;			// 아이템 램프
	pButton->SetTexture("UI/Item/lantern.tga",
		"UI/Item/lantern.tga",
		"UI/Item/lantern.tga");
	pButton->SetPosition(440, 94);
	pButton->SetScaling(1.2f, 1.2f);
	pButton->SetDelegate(this);
	pButton->SetTag(ITEM_LAMP);
	m_pUIRoot->AddChild(pButton);
	m_itemList[0][0] = pButton;

	//m_pItemOil = new cUIButton;			// 아이템 기름병
	//m_pItemOil->SetTexture("UI/Item/potion_oil.tga",
	//	"UI/Item/potion_oil.tga",
	//	"UI/Item/potion_oil.tga");
	//m_pItemOil->SetPosition(544, 94);
	//m_pItemOil->SetScaling(1.2f, 1.2f);
	//m_pItemOil->SetDelegate(this);
	//m_pItemOil->SetTag(ITEM_OIL);
	//m_pUIRoot->AddChild(m_pItemOil);
	//m_itemList[0][1] = m_pItemOil;

	CreateItem(ITEM_OIL);
	CreateItem(ITEM_HP);

	cUITextView* pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(566, 494);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);
	
	pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(600, 100));
	pTextView->SetPosition(440, 546);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW_2);
	m_pUIRoot->AddChild(pTextView);

	char HP[20];
	sprintf(HP, "%d %d", m_nHeartHP, m_nBrainHP);
	pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText(HP);
	pTextView->SetSize(ST_SIZE(600, 100));
	pTextView->SetPosition(300, 50);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW_3);
	m_pUIRoot->AddChild(pTextView);

	char Mouse[20];
	GetCursorPos(&_ptMousePos);
	sprintf(Mouse, "%d, %d", _ptMousePos.x, _ptMousePos.y);
	pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText(Mouse);
	pTextView->SetSize(ST_SIZE(600, 100));
	pTextView->SetPosition(50, 200);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_MOUSEPOS);
	m_pUIRoot->AddChild(pTextView);

	pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText("아직");
	pTextView->SetSize(ST_SIZE(600, 100));
	pTextView->SetPosition(50, 240);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_PTINRECT);
	m_pUIRoot->AddChild(pTextView);

	char RowCol[20];
	sprintf(RowCol, "%d, %d", m_nRow, m_nCol);
	pTextView = new cUITextView(cFontManager::E_EXPLANATION);
	pTextView->SetText(RowCol);
	pTextView->SetSize(ST_SIZE(600, 100));
	pTextView->SetPosition(50, 280);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_ROW_COL);
	m_pUIRoot->AddChild(pTextView);

	DATABASE->Insert(ITEM_OIL);
	char OilNum[20];
	sprintf(OilNum, "x%d", DATABASE->Load(ITEM_OIL));
	pTextView = new cUITextView(cFontManager::E_ITEM_VALUE);
	pTextView->SetText(OilNum);
	pTextView->SetSize(ST_SIZE(100, 100));
	pTextView->SetPosition(594, 80);
	pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_ITEM_NUM);
	m_pUIRoot->AddChild(pTextView);

	sprintf(m_szTinderNum, "x %d", DATABASE->Load(ITEM_TINDER));
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
	SAFE_DELETE(m_pBorder);
}

void cUI_In_Game::Update()
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	cUITextView* pTextView_2 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW_2);
	cUITextView* pTextView_3 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW_3);
	cUITextView* pTextView_4 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_MOUSEPOS);
	cUITextView* pTextView_5 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_PTINRECT);
	cUITextView* pTextView_6 = (cUITextView*)m_pUIRoot->GetChildByTag(E_ROW_COL);
	cUITextView* pTextView_7 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_ITEM_NUM);

	if (pTextView) pTextView->SetText("");
	if (pTextView_2) pTextView_2->SetText("");
	
	char HP[20];
	sprintf(HP, "%d %d", m_nHeartHP, m_nBrainHP);
	if (pTextView_3) pTextView_3->SetText(HP);

	char Mouse[20];
	sprintf(Mouse, "%d, %d", _ptMousePos.x, _ptMousePos.y);
	if (pTextView_4) pTextView_4->SetText(Mouse);

	if (pTextView_5) pTextView_5->SetText("아직");

	char RowCol[20];
	sprintf(RowCol, "%d, %d", m_nRow, m_nCol);
	if (pTextView_6) pTextView_6->SetText(RowCol);

	char OilValue[20];
	pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_ITEM_NUM);
	sprintf(OilValue, "x %d", DATABASE->Load(ITEM_OIL));
	if (pTextView_7) pTextView_7->SetText(OilValue);

	pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_TINDER_NUM);
	sprintf(m_szTinderNum, "x %d", DATABASE->Load(ITEM_TINDER));
	pTextView->SetText(m_szTinderNum);

	HeartState(m_nHeartHP);
	BrainState(m_nBrainHP);

	SetRect(&m_InventoryRc, 430, 66, 1011, 432);
	SetRect(&m_OilRc, 1046, 261, 1188, 425);

	cUIButton* pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_OIL);
	if (pButton)
	{
		if (m_fOilValue >= 0.5f) m_fOilValue = 0.5f;
		else if (m_fOilValue <= 0.0f) m_fOilValue = 0.0f;
		pButton->SetScaling(0.5f, m_fOilValue);
	}

	ValueCtr();


	if (PtInRect(&m_InventoryRc, _ptMousePos))
	{
		pTextView_5->SetText("인벤 위");
		FindRowCol(m_nRow, m_nCol);
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{
		if (PtInRect(&m_InventoryRc, _ptMousePos))
		{
			if (FindRowCol(m_curItemRow, m_curItemCol))
			{
				if (m_itemList[m_curItemRow][m_curItemCol])
				{
					m_curClickItem = m_itemList[m_curItemRow][m_curItemCol];
				}
			}
		}
	}
	if (m_curClickItem)
	{
		m_curClickItem->SetPosition(_ptMousePos.x, _ptMousePos.y);
		if (pTextView_7) pTextView_7->SetText("");
		if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
		{
			if (PtInRect(&m_OilRc, _ptMousePos) && m_curClickItem->GetTag() == ITEM_OIL)
			{
				m_fOilValue += 0.1f;
				int x, y;
				FindPostion(m_curItemRow, m_curItemCol, x, y);
				m_curClickItem->SetPosition(x, y);
				m_curClickItem = NULL;
			}
			else
			{
				int x, y;
				FindPostion(m_curItemRow, m_curItemCol, x, y);
				m_curClickItem->SetPosition(x, y);
				m_curClickItem = NULL;
			}
		}
	}

 	if (PtInRect(&m_OilRc, _ptMousePos))
	{
		pTextView_5->SetText("기름 위");
	}

	SAFE_UPDATE(m_pBorder);
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
		SAFE_RENDER(m_pBorder);
	}
}

void cUI_In_Game::MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_LBUTTONDOWN:
	{
	}
	break;
	case WM_LBUTTONUP:
	{
	}
	break;
	case WM_MOUSEMOVE:
	{	
	}
	break;
	case WM_MOUSEWHEEL:
	{
	}
	break;
	}
}

void cUI_In_Game::OnMouse(cUIButton* pSender)
{
	cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW);
	cUITextView* pTextView_2 = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_VIEW_2);
	if (pTextView == NULL) return;

	if (pSender->GetTag() == E_HEART || pSender->GetTag() == E_HEART_UP)
	{
		pTextView->SetText("체력");
		switch (HeartSate)
		{
		case PLAYER_HEART_100: pTextView_2->SetText("전체적으로 좋다.");				break;
		case PLAYER_HEART_75 : pTextView_2->SetText("약간의 타박상이 있다.");			break;
		case PLAYER_HEART_50 : pTextView_2->SetText("상처에서 출혈이 너무 심해.");	break;
		case PLAYER_HEART_25 : pTextView_2->SetText("간신히 살아있다.");				break;
		}
	}
	else if (pSender->GetTag() == E_BRAIN || pSender->GetTag() == E_BRAIN_UP)
	{
		pTextView->SetText("정신도");
		switch (BrainSate)
		{
		case PLAYER_BRAIN_100: pTextView_2->SetText("깔끔하다.");					break;
		case PLAYER_BRAIN_75 : pTextView_2->SetText("약간의 투통이 있다.");			break;
		case PLAYER_BRAIN_50 : pTextView_2->SetText("제정신이 아니야, 손이 떨려.");	break;
		case PLAYER_BRAIN_25 : pTextView_2->SetText("...");							break;
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
	else if (pSender->GetTag() == ITEM_LAMP)
	{
		pTextView->SetText("랜턴 (소화)");
		pTextView_2->SetText("랜턴은 어둠을 비춰줘, 게임에서 F / 을 누루면 켜진다.");
	}
	else if (pSender->GetTag() == ITEM_OIL)
	{
		pTextView->SetText("기름");
		pTextView_2->SetText("랜턴 연료.");
	}
}

void cUI_In_Game::OnClick(cUIButton* pSender)
{
	//cUITextView* pTextView = (cUITextView*)m_pUIRoot->GetChildByTag(E_TEXT_PTINRECT);
	//if (pTextView == NULL) return;

	/*if (pSender->GetTag() == ITEM_OIL)
	{
		m_fOilValue += 0.1f;
	}*/
	/*else if (pSender->GetTag() == E_BRAIN)
	{
	pTextView->SetText("정신력\n\n깔끔하다");
	}
	else if (pSender->GetTag() == E_TINDER)
	{
	pTextView->SetText("틴더");
	}*/
}

void cUI_In_Game::CreateItem(int tag)
{
	for each(auto row in m_itemList)
	{
		for each(auto col in row.second)
		{
			if (col.second->GetTag() == tag)
			{
				cUITextView* pObj = (cUITextView*)col.second->GetChildByTag(E_TEXT_ITEM_NUM);
				int nCount = 0;
				
				switch (tag)
				{
				case ITEM_TINDER:
					DATABASE->Insert(ITEM_TINDER);
					nCount = DATABASE->Load(ITEM_TINDER);
					break;
				case ITEM_LAMP:
					break;
				case ITEM_OIL:
					RECT rc;
					DATABASE->Insert(ITEM_OIL);
					nCount = DATABASE->Load(ITEM_OIL);
					m_pItemOil->GetRect(&rc);
					break;
				case ITEM_HP:
					DATABASE->Insert(ITEM_HP);
					nCount = DATABASE->Load(ITEM_HP);
					break;
				}
				char str[30];
				sprintf(str, "%d", nCount);
				pObj->SetText(str);
				return;
			}
		}
	}

	int row, col, x = -1, y;

	for (int r = 0; r < 3; r++)
	{
		for (int c = 0; c < 6; c++)
		{
			if (m_itemList[r][c]) continue;
			row = r;
			col = c;
			FindPostion(row, col, x, y);
			break;
		}
		if (x > 0) break;
	}

	cUIButton* pObj = new cUIButton;

	switch (tag)
	{
	case ITEM_TINDER:
		break;
	case ITEM_LAMP:
		break;
	case ITEM_OIL:
		pObj->SetTexture("UI/Item/potion_oil.tga",
			"UI/Item/potion_oil.tga",
			"UI/Item/potion_oil.tga");
		pObj->SetPosition(x, y);
		pObj->SetScaling(1.2f, 1.2f);
		pObj->SetDelegate(this);
		pObj->SetTag(ITEM_OIL);
		m_pUIRoot->AddChild(pObj);
		m_itemList[row][col] = pObj;
		break;
	case ITEM_HP:
		pObj->SetTexture("UI/Item/potion_health.tga",
			"UI/Item/potion_health.tga",
			"UI/Item/potion_health.tga");
		pObj->SetPosition(x, y);
		pObj->SetScaling(1.2f, 1.2f);
		pObj->SetDelegate(this);
		pObj->SetTag(ITEM_HP);
		m_pUIRoot->AddChild(pObj);
		m_itemList[row][col] = pObj;
		break;
	default:
		break;
	}
	
}

void cUI_In_Game::HeartState(int heart)
{
	m_nHeartHP = heart;
	if (m_nHeartHP >= 100) HeartSate = PLAYER_HEART_100;
	else if (m_nHeartHP >= 75 && m_nHeartHP <= 99) HeartSate = PLAYER_HEART_75;
	else if (m_nHeartHP >= 50 && m_nHeartHP <= 74) HeartSate = PLAYER_HEART_50;
	else if (m_nHeartHP >   0 && m_nHeartHP <= 49) HeartSate = PLAYER_HEART_25;
	else if (m_nHeartHP <= 0) HeartSate = PLAYER_DEATH;

	switch (HeartSate)
	{
	case PLAYER_HEART_100:
		m_nHeartHP = 100;
		sprintf(m_szHeartState, "UI/inventory_health_100.tga");
		sprintf(m_szHeartGlowState, "UI/inventory_health_glow_100.tga");
		break;
	case PLAYER_HEART_75:
		sprintf(m_szHeartState, "UI/inventory_health_75.tga");
		sprintf(m_szHeartGlowState, "UI/inventory_health_glow_75.tga");
		break;
	case PLAYER_HEART_50:
		sprintf(m_szHeartState, "UI/inventory_health_50.tga");
		sprintf(m_szHeartGlowState, "UI/inventory_health_glow_50.tga");
		break;
	case PLAYER_HEART_25:
		sprintf(m_szHeartState, "UI/inventory_health_25.tga");
		sprintf(m_szHeartGlowState, "UI/inventory_health_glow_25.tga");
		break;
	case PLAYER_DEATH: m_nHeartHP = 0; break;
	}

	cUIButton* pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_HEART);
	if (pButton) pButton->SetTexture(m_szHeartState, m_szHeartState, m_szHeartState);
	pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_HEART_UP);
	if (pButton) pButton->SetTexture(m_szHeartState, m_szHeartGlowState, m_szHeartState);
}

void cUI_In_Game::BrainState(int brain)
{
	m_nBrainHP = brain;
	if (m_nBrainHP >= 100) BrainSate = PLAYER_BRAIN_100;
	else if (m_nBrainHP >= 75 && m_nBrainHP <= 99) BrainSate = PLAYER_BRAIN_75;
	else if (m_nBrainHP >= 50 && m_nBrainHP <= 74) BrainSate = PLAYER_BRAIN_50;
	else if (m_nBrainHP >   0 && m_nBrainHP <= 49) BrainSate = PLAYER_BRAIN_25;
	else if (m_nBrainHP <= 0) BrainSate = PLAYER_DEATH;

	switch (BrainSate)
	{
	case PLAYER_BRAIN_100:
		m_nBrainHP = 100;
		sprintf(m_szBrainState, "UI/inventory_sanity_100.tga");
		sprintf(m_szBrainGlowState, "UI/inventory_sanity_glow_100.tga");
		break;
	case PLAYER_BRAIN_75:
		sprintf(m_szBrainState, "UI/inventory_sanity_75.tga");
		sprintf(m_szBrainGlowState, "UI/inventory_sanity_glow_75.tga");
		break;
	case PLAYER_BRAIN_50:
		sprintf(m_szBrainState, "UI/inventory_sanity_50.tga");
		sprintf(m_szBrainGlowState, "UI/inventory_sanity_glow_50.tga");
		break;
	case PLAYER_BRAIN_25:
		sprintf(m_szBrainState, "UI/inventory_sanity_25.tga");
		sprintf(m_szBrainGlowState, "UI/inventory_sanity_glow_25.tga");
		break;
	case PLAYER_DEATH: m_nBrainHP = 0; break;
	}

	cUIButton* pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_BRAIN);
	if (pButton) pButton->SetTexture(m_szBrainState, m_szBrainState, m_szBrainState);
	pButton = (cUIButton*)m_pUIRoot->GetChildByTag(E_BRAIN_UP);
	if (pButton) pButton->SetTexture(m_szBrainState, m_szBrainGlowState, m_szBrainState);
}

void cUI_In_Game::ValueCtr()
{
	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		m_nHeartHP -= 5;
		m_nBrainHP -= 5;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		m_nHeartHP += 5;
		m_nBrainHP += 5;
	}
	if (KEYMANAGER->isOnceKeyDown('R')) DATABASE->Delete(ITEM_TINDER);
	if (KEYMANAGER->isOnceKeyDown('T')) DATABASE->Insert(ITEM_TINDER);
	if (KEYMANAGER->isStayKeyDown('F')) m_fOilValue += 0.0001f;
	if (KEYMANAGER->isStayKeyDown('V')) m_fOilValue -= 0.0001f;
}

void cUI_In_Game::FindPostion(IN int row, IN int col, OUT int & x, OUT int & y)
{
	POINT distToZero = { 445, 90 };
	POINT rtnPos = { col * (130 * 0.76f), row * (190 * 0.66f) };
	x = rtnPos.x + distToZero.x;
	y = rtnPos.y + distToZero.y;
}

bool cUI_In_Game::FindRowCol(OUT int & row, OUT int & col)
{
	col = (_ptMousePos.x - m_InventoryRc.left) / (130 * 0.76f);
	row = (_ptMousePos.y - m_InventoryRc.top) / (190 * 0.66f);

	if (row < 0 || col < 0 || row > 5 || col > 2) return false;
	return true;
}
