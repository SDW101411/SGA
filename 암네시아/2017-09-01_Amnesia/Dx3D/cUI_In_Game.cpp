#include "stdafx.h"
#include "cUI_In_Game.h"
#include "cUIImageView.h"
#include "cUITextView.h"
#include "cUITool.h"
#include "cUIGrid.h"

enum
{
	E_BACKGROUND = 211,
	E_BORDER = 212,
	E_HEART = 213,
	E_HEART_UP = 214,
	E_BRAIN = 215,
	E_BRAIN_UP = 216,
	E_TINDER = 217,
	E_JOURNAL = 218,
	E_RANTERNSHAPE = 219,
	E_OIL = 220,
	E_TEXT_VIEW,
	E_TEXT_VIEW_2,
	E_TEXT_VIEW_3,
	E_TEXT_MOUSEPOS,
	E_TEXT_ITEM,
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
	pButton->SetTexture(m_szHeartState, m_szHeartState, m_szHeartState);
	pButton->SetPosition(244, 100);
	pButton->SetScaling(1.1f, 1.1f);
	pButton->SetDelegate(this);
	pButton->SetTag(E_HEART);
	m_pUIRoot->AddChild(pButton);

	sprintf(m_szHeartGlowState, "UI/inventory_health_glow_%d.tga", m_nHeartHP);
	BtnFunc(pButton, m_szHeartState, m_szHeartGlowState, 244, 100, 1.1f, 1.1f, E_HEART_UP);

	sprintf(m_szBrainState, "UI/inventory_sanity_%d.tga", m_nBrainHP);
	BtnFunc(pButton, m_szBrainState, m_szBrainState, 254, 380, 1.1f, 1.1f, E_BRAIN);

	sprintf(m_szBrainGlowState, "UI/inventory_sanity_glow_%d.tga", m_nBrainHP);
	BtnFunc(pButton, m_szBrainState, m_szBrainGlowState, 254, 380, 1.1f, 1.1f, E_BRAIN_UP);

	BtnFunc(pButton, "inventory_tinderboxes", "inventory_tinderboxes", 1094, 110, 1.0f, 1.0f, ITEM_TINDER);
	BtnFunc(pButton, "inventory_journal", "inventory_journal", 1070, 496, 1.1f, 1.1f, E_JOURNAL);
	BtnFunc(pButton, "inventory_journal", "inventory_journal_mouse_over", 1070, 496, 1.1f, 1.1f, E_JOURNAL); // 마우스 오버 시 노란 테두리 용
	BtnFunc(pButton, "inventory_oil_fg", "inventory_oil_fg", 1088, 288, 1.0f, 1.0f, E_RANTERNSHAPE); // 랜턴 기름 틀

	cUITextView* pTextView = new cUITextView(cFontManager::E_NORMAL);
	pTextView->SetText("");
	pTextView->SetSize(ST_SIZE(312, 100));
	pTextView->SetPosition(566, 494);
	pTextView->SetDrawTextFormat(DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK);
	pTextView->SetTag(E_TEXT_VIEW);
	m_pUIRoot->AddChild(pTextView);

	TextViewFunc(pTextView, cFontManager::E_EXPLANATION, "", 600, 100, 440, 546, /*DT_CENTER | DT_VCENTER | */DT_WORDBREAK, E_TEXT_VIEW_2);

	char HP[20];
	sprintf(HP, "%d %d", m_nHeartHP, m_nBrainHP);
	TextViewFunc(pTextView, cFontManager::E_EXPLANATION, HP, 600, 100, 284, 50, /*DT_CENTER | DT_VCENTER | */DT_WORDBREAK, E_TEXT_VIEW_3);

	char Mouse[20];
	sprintf(Mouse, "%d, %d", _ptMousePos.x, _ptMousePos.y);
	TextViewFunc(pTextView, cFontManager::E_EXPLANATION, Mouse, 600, 100, 50, 300, /*DT_CENTER | DT_VCENTER | */DT_WORDBREAK, E_TEXT_MOUSEPOS);

	sprintf(m_szTinderNum, "x %d", DATABASE->Load(ITEM_TINDER));
	TextViewFunc(pTextView, cFontManager::E_NORMAL, m_szTinderNum, 40, 20, 1102, 136, DT_CENTER/* | DT_VCENTER*/ | DT_WORDBREAK, E_TEXT_TINDER_NUM);
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

	if (pTextView) pTextView->SetText("");
	if (pTextView_2) pTextView_2->SetText("");

	char HP[20];
	sprintf(HP, "%d %d", m_nHeartHP, m_nBrainHP);
	if (pTextView_3) pTextView_3->SetText(HP);

	char Mouse[20];
	sprintf(Mouse, "%d, %d", _ptMousePos.x, _ptMousePos.y);
	if (pTextView_4) pTextView_4->SetText(Mouse);

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
	UpdateItemState();

	if (KEYMANAGER->isToggleKey(VK_TAB))
	{
	}
	else
	{
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
			m_curClickItem->SetPosition(_ptMousePos.x - 38, _ptMousePos.y - 30);
			cUITextView* pText = (cUITextView*)m_curClickItem->GetChildByTag(E_TEXT_ITEM);
			pText->SetText("");
			if (KEYMANAGER->isOnceKeyUp(VK_LBUTTON))
			{
				if (PtInRect(&m_OilRc, _ptMousePos) && m_curClickItem->GetTag() == ITEM_OIL)
				{
					if (!(m_fOilValue >= 0.5f))
					{
						DATABASE->Delete(ITEM_OIL);
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
				else
				{
					int x, y;
					FindPostion(m_curItemRow, m_curItemCol, x, y);
					m_curClickItem->SetPosition(x, y);
					m_curClickItem = NULL;
				}
			}
		}

		SAFE_UPDATE(m_pBorder);
		SAFE_UPDATE(m_pUIRoot);
	}
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

void cUI_In_Game::BtnFunc(cUIButton* pButton, char* szStr, char* szStrGlow, float x, float y, float width, float height, int tag)
{
	char str[40], strGlow[50];
	sprintf(str, "UI/%s.tga", szStr);
	sprintf(strGlow, "UI/%s.tga", szStrGlow);
	pButton = new cUIButton;
	pButton->SetTexture(str,
		strGlow,
		str);
	pButton->SetPosition(x, y);
	pButton->SetScaling(width, height);
	pButton->SetDelegate(this);
	pButton->SetTag(tag);
	m_pUIRoot->AddChild(pButton);
}

void cUI_In_Game::TextViewFunc(cUITextView* pTextView, cFontManager::eFontType type, string szStr, float szWidth, float szHeight, float x, float y, DWORD var, int tag)
{
	pTextView = new cUITextView(type);
	pTextView->SetText(szStr);
	pTextView->SetSize(ST_SIZE(szWidth, szHeight));
	pTextView->SetPosition(x, y);
	pTextView->SetDrawTextFormat(var);
	pTextView->SetTag(tag);
	m_pUIRoot->AddChild(pTextView);
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
		case PLAYER_HEART_75: pTextView_2->SetText("약간의 타박상이 있다.");			break;
		case PLAYER_HEART_50: pTextView_2->SetText("상처에서 출혈이 너무 심해.");	break;
		case PLAYER_HEART_25: pTextView_2->SetText("간신히 살아있다.");				break;
		}
	}
	else if (pSender->GetTag() == E_BRAIN || pSender->GetTag() == E_BRAIN_UP)
	{
		pTextView->SetText("정신도");
		switch (BrainSate)
		{
		case PLAYER_BRAIN_100: pTextView_2->SetText("깔끔하다.");					break;
		case PLAYER_BRAIN_75: pTextView_2->SetText("약간의 투통이 있다.");			break;
		case PLAYER_BRAIN_50: pTextView_2->SetText("제정신이 아니야, 손이 떨려.");	break;
		case PLAYER_BRAIN_25: pTextView_2->SetText("...");							break;
		}
	}
	else if (pSender->GetTag() == ITEM_TINDER)
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
	else if (pSender->GetTag() == ITEM_HP)
	{
		pTextView->SetText("아편");
		pTextView_2->SetText("강장약은 건강 상태를 좋게 하고 부상을 치료한다.");
	}
}

void cUI_In_Game::OnClick(cUIButton* pSender)
{
	if (pSender->GetTag() == E_JOURNAL)
	{
		g_pSceneManager->SceneChange("cUIJournalScene");
	}
}

void cUI_In_Game::CreateItem(int tag)
{
	for each(auto row in m_itemList)
	{
		for each(auto col in row.second)
		{
			if (col.second && col.second->GetTag() == tag)
			{
				switch (tag)
				{
				case ITEM_TINDER:
					DATABASE->Insert(ITEM_TINDER);
					break;
				case ITEM_LAMP:
					//	DATABASE->Insert(ITEM_LAMP);
					break;
				case ITEM_OIL:
					DATABASE->Insert(ITEM_OIL);
					break;
				case ITEM_HP:
					DATABASE->Insert(ITEM_HP);
					break;
				case ITEM_MENTAL:
					DATABASE->Insert(ITEM_MENTAL);
					break;
				}
				return;
			}
		}
	}

	int ix = 46, iy = -6;
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
	case ITEM_LAMP:
	{
		pObj->SetTexture("UI/Item/lantern.tga",
			"UI/Item/lantern.tga",
			"UI/Item/lantern.tga");
		pObj->SetPosition(x, y);
		pObj->SetScaling(1.2f, 1.2f);
		pObj->SetDelegate(this);
		pObj->SetTag(ITEM_LAMP);
		m_pUIRoot->AddChild(pObj);
		m_itemList[row][col] = pObj;

		DATABASE->Insert(ITEM_LAMP);
		cUITextView* pTextView = new cUITextView(cFontManager::E_ITEM_VALUE);
		pTextView->SetText("");
		pTextView->SetSize(ST_SIZE(1, 100));
		pTextView->SetPosition(ix, iy);
		pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
		pTextView->SetTag(E_TEXT_ITEM);
		pObj->AddChild(pTextView);
	}
	break;
	case ITEM_OIL:
	{
		pObj->SetTexture("UI/Item/potion_oil.tga",
			"UI/Item/potion_oil.tga",
			"UI/Item/potion_oil.tga");
		pObj->SetPosition(x, y);
		pObj->SetScaling(1.2f, 1.2f);
		pObj->SetDelegate(this);
		pObj->SetTag(ITEM_OIL);
		m_pUIRoot->AddChild(pObj);
		m_itemList[row][col] = pObj;

		char OilNum[20];
		sprintf(OilNum, "x%d", DATABASE->Load(ITEM_OIL));
		DATABASE->Insert(ITEM_OIL);
		cUITextView* pTextView = new cUITextView(cFontManager::E_ITEM_VALUE);
		pTextView->SetText(OilNum);
		pTextView->SetSize(ST_SIZE(100, 100));
		pTextView->SetPosition(ix, iy);
		pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
		pTextView->SetTag(E_TEXT_ITEM);
		pObj->AddChild(pTextView);
	}
	break;
	case ITEM_HP:
	{
		pObj->SetTexture("UI/Item/potion_health.tga",
			"UI/Item/potion_health.tga",
			"UI/Item/potion_health.tga");
		pObj->SetPosition(x, y);
		pObj->SetScaling(1.2f, 1.2f);
		pObj->SetDelegate(this);
		pObj->SetTag(ITEM_HP);
		m_pUIRoot->AddChild(pObj);
		m_itemList[row][col] = pObj;

		char HpNum[20];
		sprintf(HpNum, "x%d", DATABASE->Load(ITEM_HP));
		DATABASE->Insert(ITEM_HP);
		cUITextView* pTextView = new cUITextView(cFontManager::E_ITEM_VALUE);
		pTextView->SetText(HpNum);
		pTextView->SetSize(ST_SIZE(100, 100));
		pTextView->SetPosition(ix, iy);
		pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
		pTextView->SetTag(E_TEXT_ITEM);
		pObj->AddChild(pTextView);
	}
	break;
	case ITEM_MENTAL:
		pObj->SetTexture("UI/Item/potion_sanity.tga",
			"UI/Item/potion_sanity.tga",
			"UI/Item/potion_sanity.tga");
		pObj->SetPosition(x, y);
		pObj->SetScaling(1.2f, 1.2f);
		pObj->SetDelegate(this);
		pObj->SetTag(ITEM_MENTAL);
		m_pUIRoot->AddChild(pObj);
		m_itemList[row][col] = pObj;

		char MentalNum[20];
		sprintf(MentalNum, "x%d", DATABASE->Load(ITEM_MENTAL));
		DATABASE->Insert(ITEM_MENTAL);
		cUITextView* pTextView = new cUITextView(cFontManager::E_ITEM_VALUE);
		pTextView->SetText(MentalNum);
		pTextView->SetSize(ST_SIZE(100, 100));
		pTextView->SetPosition(ix, iy);
		pTextView->SetDrawTextFormat(/*DT_CENTER | DT_VCENTER | */DT_WORDBREAK);
		pTextView->SetTag(E_TEXT_ITEM);
		pObj->AddChild(pTextView);
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
	if (KEYMANAGER->isStayKeyDown('V')) m_fOilValue -= 0.01f;//0.0001f;
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD1)) CreateItem(ITEM_HP);
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD2)) DATABASE->Delete(ITEM_HP);
	if (KEYMANAGER->isOnceKeyDown('O')) CreateItem(ITEM_OIL);
	if (KEYMANAGER->isOnceKeyDown('P')) DATABASE->Delete(ITEM_OIL);
	if (KEYMANAGER->isOnceKeyDown('Y')) CreateItem(ITEM_LAMP);
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD4)) CreateItem(ITEM_MENTAL);
	if (KEYMANAGER->isOnceKeyDown(VK_NUMPAD5)) DATABASE->Delete(ITEM_MENTAL);
}

void cUI_In_Game::UpdateItemState()
{
	for (int row = 0; row < 3; row++)
	{
		for (int col = 0; col < 6; col++)
		{
			if (m_itemList[row][col])
			{
				int nTag = m_itemList[row][col]->GetTag();
				int nCount;
				cUITextView* pText = (cUITextView*)m_itemList[row][col]->GetChildByTag(E_TEXT_ITEM);
				if (pText)
				{
					nCount = DATABASE->Load(nTag);
					if (nCount <= 0)
					{
						m_itemList[row][col] = NULL;
						m_pUIRoot->Delete(nTag);
						continue;
					}
					char str[30];
					sprintf(str, "x%d", nCount);
					pText->SetText(str);
				}
			}
		}
	}
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
