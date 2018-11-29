#include "Map.h"

void Map::setXY1(int x, int y)
{
	map[x][y] = 1;
}

Map::Map()
{
	for (int i = 0; i < MapLength; i++)
	{
		for (int j = 0; j < MapWidth; j++)
		{
			if (i == 1 && j >= 0 && j <= 3)
			{
				setXY1(i, j);
			}
			else if (i == 3 && j >= 5 && j <= 8)
			{
				setXY1(i, j);
			}
			else if (i == 4 && j >= 0 && j <= 3)
			{
				setXY1(i, j);
			}
			else if (i == 5 && j >= 5 && j <= 6)
			{
				setXY1(i, j);
			}
			else if (i == 6 && j >= 8 && j <= 9)
			{
				setXY1(i, j);
			}
			else if (i == 7 && j >= 3 && j <= 4)
			{
				setXY1(i, j);
			}
			else if (i == 8 && j >= 6 && j <= 7)
			{
				setXY1(i, j);
			}
			else if (i == 9 && j >= 0 && j <= 4)
			{
				setXY1(i, j);
			}
		}
	}
}

int Map::getXY(int x, int y)
{
	return map[x][y];
}