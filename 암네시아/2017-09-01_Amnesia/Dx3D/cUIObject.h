#pragma once

class cUIObject : public cObject
{
protected:
	vector<cUIObject*>	m_vecChild;
	D3DXVECTOR3			m_vPosition;
	D3DXVECTOR3			m_vScaling;
	cUIObject*			m_pParent;
	D3DXMATRIX			m_matWorld;
	D3DXMATRIX			m_matR;
	float				m_fAngle;
	SYNTHESIZE(ST_SIZE,	m_stSize, Size);
	SYNTHESIZE(int, m_nTag, Tag);
	//SYNTHESIZE(int, m_nSave, Save);

public:
	cUIObject(void);
	virtual ~cUIObject(void);
	
	virtual void AddChild(cUIObject* pChild);
	virtual void Update();
	virtual void Render(LPD3DXSPRITE pSprite);
	virtual void SetPosition(float x, float y);
	virtual void SetScaling(float x, float y);
	virtual void SetRotationX(float x);
	virtual void GetRect(RECT* pRect);
	virtual cUIObject* GetChildByTag(int nTag);
};

