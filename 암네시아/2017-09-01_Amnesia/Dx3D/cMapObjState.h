#pragma once

class cMapObjState
{
private:
	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);
	SYNTHESIZE(D3DXVECTOR3, m_rot, Rotation);
	SYNTHESIZE(D3DXVECTOR3, m_scl, Scale);

public:
	void Setup(D3DXVECTOR3 pos = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 rot = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 scl = D3DXVECTOR3(1, 1, 1));
	void Clean();
};