#pragma once
#include "cUIButton.h"

class cGrid;
class cCamera;
class cCrtCtrl;
class cMain_admin;
class c_Gaussian;

class cMainGame : public iButtonDelegate
{
private:
	cGrid*			m_pGrid;
	cCamera*		m_pCamera;
	cCrtCtrl*		m_pCrtCtrl;
	cMain_admin*	m_pMain_admin;
	c_Gaussian*		m_pGaussian;
public:
	cMainGame(void);
	~cMainGame(void);

	void Setup();
	void Update();
	void Render();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

private:
	void SetLight();
	virtual void OnMouse(cUIButton* pSender) override;
	virtual void OnClick(cUIButton* pSender) override;
	virtual void OnRightClick(cUIButton* pSender) override;
};

