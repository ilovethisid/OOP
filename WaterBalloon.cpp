#include "WaterBalloon.h"

void WaterBalloon::pop(Map &map, int x, int y) // 시간이 되면 터지거나, 근처의 물풍선이 터질 때 터지는 범위 안에 있으면 같이 터진다.
{
	map.setPopRange(x, y); // 그 자리에서 터진다.
	for (int i = 1; i <= popLength; i++) // 물풍선 위쪽으로 터진다.
	{
		if ((x - i) >= 0 && map.getFeature(x - i, y) == 0)
		{
			map.setPopRange(x - i, y);
		}
		else if ((x - i) >= 0 && map.getFeature(x - i, y) == 1)
		{
			map.setPopRange(x - i, y);
			break;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i <= popLength; i++) // 물풍선 왼쪽으로 터진다.
	{
		if ((y - i) >= 0 && map.getFeature(x, y - i) == 0)
		{
			map.setPopRange(x, y - i);
		}
		else if ((y - i) >= 0 && map.getFeature(x, y - i) == 1)
		{
			map.setPopRange(x, y - i);
			break;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i <= popLength; i++) // 물풍선 아래쪽으로 터진다.
	{
		if ((x + i) <= MAPHEIGHT && map.getFeature(x + i, y) == 0)
		{
			map.setPopRange(x + i, y);
		}
		else if ((x + i) <= MAPHEIGHT && map.getFeature(x + i, y) == 1)
		{
			map.setPopRange(x + i, y);
			break;
		}
		else
		{
			break;
		}
	}
	for (int i = 1; i <= popLength; i++) // 물풍선 오른쪽으로 터진다.
	{
		if ((y + i) <= MAPWIDTH && map.getFeature(x, y + i) == 0)
		{
			map.setPopRange(x, y + i);
		}
		else if ((y + i) <= MAPWIDTH && map.getFeature(x, y + i) == 1)
		{
			map.setPopRange(x, y + i);
			break;
		}
		else
		{
			break;
		}
	}
}