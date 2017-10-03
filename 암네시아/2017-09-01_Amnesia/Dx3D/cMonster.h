#pragma once

class cSkinnedMesh;

class cMonster
{
private:
	cSkinnedMesh* m_pMesh;

public:
	cMonster();
	~cMonster();

	void Update();
	void Render();
};