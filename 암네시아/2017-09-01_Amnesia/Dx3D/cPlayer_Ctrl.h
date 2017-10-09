#pragma once
class cPlayer_Ctrl
{//d
private:
	D3DXVECTOR3*	m_pPos;
	D3DXVECTOR3*	m_pTarget;
	D3DXVECTOR3		m_Camera;
	D3DXVECTOR3		m_pViewTarget;
	D3DXVECTOR3		m_pViewTarget_2;

	float			m_Speed;

	bool			m_isLButtonDown;

	float			m_fAngleX;
	float			m_fAngleY;
	POINT			m_ptPrevMouse;
	float			check;
	float			fx, fy;
	float			m_UpY;


	SYNTHESIZE_PASS_BY_REF(D3DXMATRIX, m_World, m_World_f);

	vector<D3DXVECTOR3>			m_Surface;

public:
	cPlayer_Ctrl();
	cPlayer_Ctrl(D3DXVECTOR3 Save);
	cPlayer_Ctrl(D3DXVECTOR3 Save, float UpY);
	~cPlayer_Ctrl();
	void Update();
	void MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);

public:
	D3DXVECTOR3 *Get_m_pTarget();
	D3DXVECTOR3 *Get_m_pViewTarget();
	D3DXVECTOR3 *Get_m_Pos();
	D3DXVECTOR3 Get_m_Camera();
	D3DXMATRIX Get_m_pTarget_Matrix(D3DXVECTOR3 Insert);
	D3DXMATRIX Get_m_pTarget_Matrix();

	bool Get_Ray(IN float x, OUT float & y, IN float z);

private:
	void cPlayer_cCamera_Update();
	void cPlayer_cCamera_MsgProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
private:
	void cPlayer_cMove_Update();
public:
	void m_surface_Insert(D3DXVECTOR3 Save);
};

