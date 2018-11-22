#include "WaterBalloon.h"

void WaterBalloon::pop(Map &map, int x, int y) // �ð��� �Ǹ� �����ų�, ��ó�� ��ǳ���� ���� �� ������ ���� �ȿ� ������ ���� ������.
{
	map.setPopRange(x, y); // �� �ڸ����� ������.
	for (int i = 1; i <= popLength; i++) // ��ǳ�� �������� ������.
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
	for (int i = 1; i <= popLength; i++) // ��ǳ�� �������� ������.
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
	for (int i = 1; i <= popLength; i++) // ��ǳ�� �Ʒ������� ������.
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
	for (int i = 1; i <= popLength; i++) // ��ǳ�� ���������� ������.
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