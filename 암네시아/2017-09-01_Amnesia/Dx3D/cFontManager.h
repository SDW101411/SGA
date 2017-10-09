#pragma once

#define g_pFontManager cFontManager::GetInstance()

class cFontManager
{
private:
	SINGLETON(cFontManager);

public:
	enum eFontType
	{
		E_NORMAL,
		E_EXPLANATION,
		E_NUMBER,
		E_ITEM_VALUE,
		E_OPTIONEXPLANATION,
		E_END,
	};

private:
	map<eFontType, LPD3DXFONT> m_mapFont;

public:
	LPD3DXFONT GetFont(eFontType e);
	void Destroy();
};

