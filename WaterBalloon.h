#pragma once

#include "Map.h"

class WaterBalloon
{
public:
	int popLength; // 물풍선이 터질 때의 물줄기 길이

	void pop(Map &map, int x, int y); // 시간이 되면 터지거나, 근처의 물풍선이 터질 때 터지는 범위 안에 있으면 같이 터진다.
};
