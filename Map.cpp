#include "Map.h"

Map::Map()
{

}

Map::Map(Window win)
{
	this->win = win;

	// initialize tiles
	for (int i = 0; i < MAPHEIGHT; i++)
	{
		for (int j = 0; j < MAPWIDTH; j++)
		{
			this->tile[i][j] = Tile(j, i);
		}
	}
}

Map::Tile::Tile(int x, int y)
{
	this->x = x;
	this->y = y;
}

void Map::draw()
{

}

void Map::WaterBalloon::pop()
{
	// for duration, wait
	// (��ó�� ��ǳ���� ������ ���� ������)
	// if duration=0, pop
}

Map::Tile::Tile()
{

}

Map::Block::Block()
{

}

Map::Character::Character()
{

}

Map::Needle::Needle()
{

}

Map::Land::Land()
{

}

Map::WaterBalloon::WaterBalloon()
{

}

