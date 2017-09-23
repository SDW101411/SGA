#pragma once

class cMapObject
{
private:
	SYNTHESIZE(int, m_tag, Tag);
	SYNTHESIZE(int, m_floor, Floor);
	SYNTHESIZE(D3DXVECTOR3, m_pos, Position);
	SYNTHESIZE(D3DXVECTOR3, m_rot, Rotation);
	SYNTHESIZE(D3DXVECTOR3, m_scl, Scale);
public:
	cMapObject();
	~cMapObject();

	void Setup(int tag, D3DXVECTOR3 pos = { 0, 0, 0 }, D3DXVECTOR3 rot = { 0, 0, 0 }, D3DXVECTOR3 scl = { 1, 1, 1 });
};