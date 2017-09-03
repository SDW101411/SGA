#pragma once

class cGridNode;

class cMapTool
{
private:

public:
	cMapTool();
	~cMapTool();

	void SetUp();
	void Update();
	void Render();

	vector<D3DXVECTOR3> FindPickingGround();
};