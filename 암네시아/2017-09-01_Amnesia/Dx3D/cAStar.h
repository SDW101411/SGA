#pragma once

class cAStarNode;

class cAStar
{
private:
	vector<cAStarNode*> m_nodeList;

public:

	list<D3DXVECTOR3> FindPath;
};