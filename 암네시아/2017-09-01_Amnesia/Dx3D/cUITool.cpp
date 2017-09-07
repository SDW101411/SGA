#include "stdafx.h"
#include "cUITool.h"
#include "cUIGrid.h"

cUITool::cUITool()
	: m_pUIGrid(NULL)
{
}

cUITool::~cUITool()
{
	SAFE_DELETE(m_pUIGrid);
}
void cUITool::Setup()
{
	m_pUIGrid = new cUIGrid;
	m_pUIGrid->Setup(10, 1.0f);
}
void cUITool::Update()
{
}
void cUITool::Render()
{
	SAFE_RENDER(m_pUIGrid);
}
