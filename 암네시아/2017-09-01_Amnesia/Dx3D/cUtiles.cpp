#include "stdafx.h"
#include "cUtiles.h"

namespace MY_UTIL
{
	float MY_UTIL::GetDistance(D3DXVECTOR3 pos1, D3DXVECTOR3 pos2)
	{
		float x = pos1.x - pos2.x;
		float y = pos1.y - pos2.y;
		float z = pos1.z - pos2.z;

		return sqrtf(x * x + y * y + z * z);
	}
}
