#pragma once

#include "Map.h"

class Character
{
protected:
	int walkspd;
	char image; // 플래이어의 이미지(현재는 char형)
	Window win;

public:
	int x, y;
	bool locked; // 물풍선의 갇힌지의 여부
	int numWaterBalloon;
	bool needle; // 바늘의 유무

	Character();

	void draw();
	void erase();
	void move(Map*, const char* dir);
};

// player1
class Player1: public Character
{
public:
	Player1(int x, int y);
};

// player2
class Player2: public Character
{
public:
	Player2(int x, int y);
};
