#pragma once
class cCamera
{
protected:
	D3DXVECTOR3*	m_pvTarget;
	float			m_fAngleX;
	float			m_fAngleY;
	POINT			m_ptPrevMouse;
	bool			m_isLButtonDown;
	D3DXVECTOR3		m_vEye;
	float			m_fDistance;

public:
	cCamera(void);
	~cCamera(void);

	void Setup(D3DXVECTOR3* pvTarget = NULL);
	virtual void Update();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
	D3DXVECTOR3 * get_pvPostion();
};

