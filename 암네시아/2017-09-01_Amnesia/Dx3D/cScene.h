#pragma once
class cScene
{
private:
	SYNTHESIZE(Scene_oBject_List, oBject_List, OBJECTLIST);
public:
	cScene();
	~cScene();
	void Update();
	void Render();
};

