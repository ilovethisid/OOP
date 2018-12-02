#pragma once

#define MapWidth 10
#define MapLength 10

class Map
{
private:
	int map[MapLength][MapWidth];
	void setXY1(int x, int y);
public:
	Map();
	int getXY(int x, int y);
};
