#pragma once

#include "Map.h"

class WaterBalloon
{
public:
	int popLength; // ��ǳ���� ���� ���� ���ٱ� ����

	void pop(Map &map, int x, int y); // �ð��� �Ǹ� �����ų�, ��ó�� ��ǳ���� ���� �� ������ ���� �ȿ� ������ ���� ������.
};
