#include "StdAfx.h"
#include "cFontManager.h"


cFontManager::cFontManager(void)
{
}

cFontManager::~cFontManager(void)
{
}

LPD3DXFONT cFontManager::GetFont( eFontType e )
{
	if (m_mapFont.find(e) == m_mapFont.end())
	{
		D3DXFONT_DESC fd;
		ZeroMemory(&fd,sizeof(D3DXFONT_DESC));

		if(e == E_NORMAL)
		{
			fd.Height			= 20;
			fd.Width			= 8;
			fd.Weight			= FW_NORMAL;
			fd.Italic			= false;
			fd.CharSet			= DEFAULT_CHARSET;
			fd.OutputPrecision  = OUT_DEFAULT_PRECIS;
			fd.PitchAndFamily   = FF_DONTCARE;
			//AddFontResource("umberto.ttf");
			strcpy_s(fd.FaceName, "굴림");	//글꼴 스타일
		}
		else if(e == E_EXPLANATION)
		{
			fd.Height			= 25;
			fd.Width			= 10;
			fd.Weight			= FW_NORMAL;
			fd.Italic			= false;
			fd.CharSet			= DEFAULT_CHARSET;
			fd.OutputPrecision  = OUT_DEFAULT_PRECIS;
			fd.PitchAndFamily   = FF_DONTCARE;
			//AddFontResource("umberto.ttf");
			strcpy_s(fd.FaceName, "굴림");	//글꼴 스타일
		}
		else if (e == E_NUMBER)
		{
			fd.Height = 50;
			fd.Width = 25;
			fd.Weight = FW_NORMAL;
			fd.Italic = false;
			fd.CharSet = DEFAULT_CHARSET;
			fd.OutputPrecision = OUT_DEFAULT_PRECIS;
			fd.PitchAndFamily = FF_DONTCARE;
			//AddFontResource("umberto.ttf");
			strcpy_s(fd.FaceName, "궁서체");	//글꼴 스타일
		}
		else if (e == E_ITEM_VALUE)
		{
			fd.Height = 20;
			fd.Width = 10;
			fd.Weight = FW_NORMAL;
			fd.Italic = false;
			fd.CharSet = DEFAULT_CHARSET;
			fd.OutputPrecision = OUT_DEFAULT_PRECIS;
			fd.PitchAndFamily = FF_DONTCARE;
			//AddFontResource("umberto.ttf");
			strcpy_s(fd.FaceName, "굴림");	//글꼴 스타일
		}
		else if (e == E_OPTIONEXPLANATION)
		{
			fd.Height = 20;
			fd.Width = 7;
			fd.Weight = FW_NORMAL;
			fd.Italic = false;
			fd.CharSet = DEFAULT_CHARSET;
			fd.OutputPrecision = OUT_DEFAULT_PRECIS;
			fd.PitchAndFamily = FF_DONTCARE;
			//AddFontResource("umberto.ttf");
			strcpy_s(fd.FaceName, "굴림");	//글꼴 스타일
		}

		D3DXCreateFontIndirect(g_pD3DDevice, &fd, &m_mapFont[e]);
	}

	return m_mapFont[e];
}

void cFontManager::Destroy()
{
	for each(auto it in m_mapFont)
	{
		SAFE_RELEASE(it.second);
	}
}
