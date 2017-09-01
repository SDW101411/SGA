#include "StdAfx.h"
#include "cNode.h"


cNode::cNode(void)
{
	g_setPool.insert(this);
}


cNode::~cNode(void)
{
	g_setPool.erase(this);
}
