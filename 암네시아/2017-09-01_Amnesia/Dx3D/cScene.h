#pragma once
class cScene
{
private:
	SYNTHESIZE(Scene_oBject_List, oBject_List, OBJECTLIST);
public:
	cScene();
	virtual ~cScene();
	virtual void Update();
	virtual void Render();
};

