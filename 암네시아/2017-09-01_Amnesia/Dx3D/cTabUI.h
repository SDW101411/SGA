#pragma once
class cTabUI
{
private:
	vector<D3DXVECTOR3>				m_ImagePos;

public:
	cTabUI();
	~cTabUI();

	void Setup();
	void Update();
	void Render();
};

