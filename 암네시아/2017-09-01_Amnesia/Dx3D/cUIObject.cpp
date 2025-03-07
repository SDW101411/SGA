#include "StdAfx.h"
#include "cUIObject.h"


cUIObject::cUIObject(void)
	: m_vPosition(0, 0, 0)
	, m_vScaling(1, 1, 1)
	, m_fAngle(0.0f)
	, m_stSize(0, 0)
	, m_pParent(NULL)
	, m_nTag(0)
{
	D3DXMatrixIdentity(&m_matWorld);
}

cUIObject::~cUIObject(void)
{
	for each(auto p in m_vecChild)
	{
		SAFE_RELEASE(p);
	}
}

void cUIObject::Delete(int n)
{
	cUIObject* pChild = GetChildByTag(n);
	if (pChild)
	{
		vector<cUIObject*>::iterator it = m_vecChild.begin();
		for (; it != m_vecChild.end(); it++)
		{
			if ((*it) == pChild)
			{
				it = m_vecChild.erase(it);
				break;
			}
		}
		SAFE_RELEASE(pChild);
	}
}

void cUIObject::AddChild(cUIObject* pChild)
{
	pChild->m_pParent = this;
	m_vecChild.push_back(pChild);
}

void cUIObject::Update()
{
	D3DXMatrixScaling(&m_matWorld, m_vScaling.x, m_vScaling.y, m_vScaling.z);
	D3DXMatrixRotationZ(&m_matR, m_fAngle);
	m_matWorld *= m_matR;
	m_matWorld._41 = m_vPosition.x;
	m_matWorld._42 = m_vPosition.y;
	if (m_pParent)
	{
		m_matWorld._41 += m_pParent->m_matWorld._41;
		m_matWorld._42 += m_pParent->m_matWorld._42;
	}

	for each(auto p in m_vecChild)
	{
		p->Update();
	}
}

void cUIObject::Render(LPD3DXSPRITE pSprite)
{
	for each(auto p in m_vecChild)
	{
		p->Render(pSprite);
	}
}

void cUIObject::SetPosition(float x, float y)
{
	m_vPosition.x = x;
	m_vPosition.y = y;
	m_vPosition.z = 0;
}

void cUIObject::SetScaling(float x, float y)
{
	m_vScaling.x = x;
	m_vScaling.y = y;
	m_vScaling.z = 1.0f;
}

void cUIObject::SetRotationX(float x)
{
	m_fAngle = x;
}

void cUIObject::GetRect(RECT* pRect)
{
	if (!pRect) return;

	pRect->left = m_matWorld._41;
	pRect->top = m_matWorld._42;
	pRect->right = m_matWorld._41 + m_stSize.fWidth;
	pRect->bottom = m_matWorld._42 + m_stSize.fHeight;
}

cUIObject* cUIObject::GetChildByTag(int nTag)
{
	if (m_nTag == nTag)
	{
		return this;
	}

	cUIObject* pChild = NULL;
	for each(auto p in m_vecChild)
	{
		if (p->GetTag() == nTag)
		{
			pChild = p;
			break;
		}
	}
	return pChild;
}
