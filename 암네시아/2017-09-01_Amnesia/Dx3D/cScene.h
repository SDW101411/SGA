#pragma once
class cScene
{
private:
	SYNTHESIZE(Scene_oBject_List, oBject_List, OBJECTLIST);
public:
	cScene();
	~cScene();
	virtual void Update();
	virtual void Render();
};

