#pragma once

class cGridNode;
class cAStar;
class cMapObject;

class cMapTool
{
private:
	SYNTHESIZE(D3DXVECTOR3, m_leftTop, LeftTopPos);
	SYNTHESIZE(int, m_row, MaxRow);
	SYNTHESIZE(int, m_col, MaxCol);

	map<int, map<int, cGridNode*>>	m_nodeList;
	map<int, cMapObject*>			m_objList;

public:
	cMapTool();
	~cMapTool();

	void SetUp(D3DXVECTOR3 leftTop, int row, int col);
	void Update();
	void Render();

	void CreateNode(D3DXVECTOR3 pos);
	void CreateNode(int row, int col);

	void CreateObject(int id, D3DXVECTOR3 pos = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 rot = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 scl = D3DXVECTOR3(1, 1, 1));

	vector<D3DXVECTOR3> FindPickingGround();
	bool FindPickingPosition(OUT D3DXVECTOR3& pos, vector<D3DXVECTOR3> ground);
	bool FindRowCol(IN D3DXVECTOR3 pos, OUT int& row, OUT int& col);
};