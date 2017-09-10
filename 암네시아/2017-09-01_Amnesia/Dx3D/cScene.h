#pragma once
class cPlayer;
class cScene
{
private:
	SYNTHESIZE(Scene_oBject_List, oBject_List, OBJECTLIST);
	cPlayer *m_pPlayer;
public:
	cScene();
	virtual ~cScene();
	virtual void Update();
	virtual void Render();
};

