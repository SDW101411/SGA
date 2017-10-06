#pragma once

class cUIImageView : public cUIObject
{
private:
	string	m_sTexture;
	SYNTHESIZE(int, m_nAlpha, AlphaValue);

public:
	cUIImageView(void);
	virtual ~cUIImageView(void);

	virtual void SetTexture(string sFullPath);

	// cUIObject override
	virtual void Render(LPD3DXSPRITE pSprite) override;
};

