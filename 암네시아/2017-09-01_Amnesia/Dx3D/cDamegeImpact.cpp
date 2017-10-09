#include "stdafx.h"
#include "cDamegeImpact.h"
#include "cUIImageView.h"

enum
{
	E_BACK,
	E_BLOOD0,
};

cDamegeImpact::cDamegeImpact()
	: m_pUIRoot(NULL)
	, m_pSprite(NULL)
	, m_nAlpha(255)
{
	D3DXCreateSprite(g_pD3DDevice, &m_pSprite);

	cUIImageView* pImageView = new cUIImageView;
	pImageView->SetTexture("UI/tab_UI_bg2.png");
	pImageView->SetScaling(0.75f, 0.65f);
	pImageView->SetAlphaValue(m_nAlpha);
	pImageView->SetTag(E_BACK);
	m_pUIRoot = pImageView;

	pImageView = new cUIImageView;		// 피 이미지
	pImageView->SetAlphaValue(m_nAlpha);
	pImageView->SetTag(E_BLOOD0);
	m_pUIRoot->AddChild(pImageView);

	m_nTypeNum = RND->getInt(3);

	//BloodType(m_nTypeNum, pImageView->GetAlphaValue());
}

cDamegeImpact::~cDamegeImpact()
{
	SAFE_RELEASE(m_pSprite);
	SAFE_RELEASE(m_pUIRoot);
}

void cDamegeImpact::Update()
{
	cUIImageView* pImageBack = (cUIImageView*)m_pUIRoot->GetChildByTag(E_BACK);
	cUIImageView* pImageView = (cUIImageView*)m_pUIRoot->GetChildByTag(E_BLOOD0);

	if (pImageBack) pImageBack->SetAlphaValue(pImageBack->GetAlphaValue() - 5);
	if (pImageBack->GetAlphaValue() <= 0) pImageBack->SetAlphaValue(0); //m_pUIRoot->Delete(E_BACK);
	
	if(pImageView) pImageView->SetAlphaValue(pImageView->GetAlphaValue() - g_pTimeManager->GetElapsedTime());

	if (m_pUIRoot->GetTag() == E_BLOOD0)
	{
		if (pImageView->GetAlphaValue() <= 0)
		{
			pImageView->SetAlphaValue(0);
			m_pUIRoot->Delete(E_BLOOD0);
		}
	}
	
	SAFE_UPDATE(m_pUIRoot);
}

void cDamegeImpact::Render()
{
	//알파테스트 설정, 알파값이 0인 경우 그리지 않는다
	//g_pD3DDevice->SetRenderState(D3DRS_ALPHATESTENABLE, true);
	//g_pD3DDevice->SetRenderState(D3DRS_ALPHAFUNC, D3DCMP_GREATER);
	//g_pD3DDevice->SetRenderState(D3DRS_ALPHAREF, 0);

	if(m_pUIRoot)
	m_pUIRoot->Render(m_pSprite);
}

void cDamegeImpact::BloodType(int num, int alpha)
{
	switch (m_nTypeNum)
	{
	case 0:
		SOUNDMANAGER->play("player_falldamage1");
		stPos.x = 612, stPos.y = 200;
		break;
	case 1:
		SOUNDMANAGER->play("player_falldamage2");
		stPos.x = 312, stPos.y = 80;
		break;
	case 2:
		SOUNDMANAGER->play("player_falldamage3");
		stPos.x = 1000, stPos.y = 60;
		break;
	}

	char str[35];
	sprintf(str, "UI/damege/damage_bloodsplat%d.tga", num);
	cUIImageView* pImageView = new cUIImageView;		// 피 이미지
	pImageView->SetTexture(str);
	pImageView->SetPosition(stPos.x, stPos.y);
	pImageView->SetScaling(1.0f, 1.0f);
	pImageView->SetAlphaValue(alpha);
	pImageView->SetTag(E_BLOOD0);
	m_pUIRoot->AddChild(pImageView);
}

void cDamegeImpact::BloodImpact()
{
	cUIImageView* pImageBack = (cUIImageView*)m_pUIRoot->GetChildByTag(E_BACK);
	cUIImageView* pImageView = (cUIImageView*)m_pUIRoot->GetChildByTag(E_BLOOD0);

	int n = RND->getInt(3);
	//m_nTypeNum = RND->getInt(3);
	if (m_nTypeNum == n) n = RND->getInt(3);
	else m_nTypeNum = n;
	pImageView->SetAlphaValue(255);
	BloodType(m_nTypeNum, pImageView->GetAlphaValue()); //m_nTypeNum = RND->getInt(3);
	m_pUIRoot->Delete(E_BLOOD0);

	pImageBack->SetAlphaValue(255);
}