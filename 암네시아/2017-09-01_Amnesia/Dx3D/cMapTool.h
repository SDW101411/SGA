#pragma once

class cGridNode;
class cAStar;
class cMapObject;
class cMapMesh;
class cMapWall;

class cMapTool
{
private:
	SYNTHESIZE(D3DXVECTOR3, m_leftTop, LeftTopPos);
	SYNTHESIZE(int, m_rowMax, MaxRow);
	SYNTHESIZE(int, m_colMax, MaxCol);
	SYNTHESIZE(int, m_curTag, CurrentTag);
	SYNTHESIZE(int, m_curFloor, CurrentFloor);

	map<int, map<int, cGridNode*>>				m_nodeList;
	map<int, map<int, vector<cMapObject*>>>		m_tileList;
	map<int, cMapMesh*>							m_meshList;
	vector<cMapWall>							m_pickingWall;

public:
	cMapTool();
	~cMapTool();

	void SetUp(D3DXVECTOR3 leftTop, int row, int col);
	void Update();
	void Render();

	void CreateNode(D3DXVECTOR3 pos);
	void CreateNode(int row, int col);
	void DestroyNode();
	void RenderNode();

	void CreateTile(D3DXVECTOR3 pos = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 rot = D3DXVECTOR3(0, 0, 0), D3DXVECTOR3 scl = D3DXVECTOR3(1, 1, 1));
	void DeleteTile(D3DXVECTOR3 pos);
	void DestroyTile();
	void TileRender();

	void CreateMesh();
	void CreateMesh(int id);
	void DestroyMesh();

	void CreateWall(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos);
	void DeleteWall(D3DXVECTOR3 startPos, D3DXVECTOR3 endPos);
	void RenderWall();

	void RenderCurrentTag(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scl);

	vector<D3DXVECTOR3> FindPickingGround();
	bool FindPickingPosition(OUT D3DXVECTOR3& pos, vector<D3DXVECTOR3> ground);
	bool FindRowCol(IN D3DXVECTOR3 pos, OUT int& row, OUT int& col);
	void FindNearNode(IN D3DXVECTOR3 pos, OUT D3DXVECTOR3& nodePos);
};