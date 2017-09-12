#pragma once

class cSkinnedMesh;
class cMapObjState;

enum MAP_OBJ_ID
{
	MAP_OBJ_WALL_DEFAULT,
};

class cMapObject
{
private:
	//cSkinnedMesh*			m_pMesh;
	ID3DXMesh*				m_pMesh;
	D3DMATERIAL9			m_material;
	vector<cMapObjState>	m_objList;
private:
	SYNTHESIZE(int, m_id, ID);
public:
	cMapObject();
	~cMapObject();

	void Setup(int id);
	void Render();

	void AddObject(D3DXVECTOR3 pos = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 rot = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 scl = D3DXVECTOR3(1, 1, 1));
};