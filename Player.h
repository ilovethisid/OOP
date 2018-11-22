#pragma once

#include "WaterBalloon.h"
#include "Map.h"

#define MaxSpeed 3

// 캐릭터
class Character: public WaterBalloon
{
protected:
	int x, y;                // 캐릭터의 좌표
	bool locked = false;     // 물풍선에 갇혔는지 여부
	int numWaterBalloon = 1; // 캐릭터가 가지고 있는 물풍선 갯수
	int characterSpeed = 1;  // 캐릭터의 이동속도
	int item = 0;            // 아이템 (0 : 아이템 없음, 1 : 바늘)
public:
	int getPlayerX();
	int getPlayerY();
	bool getLocked();
	int getNumWaterBalloon();
	int getCharacterSpeed();
	int getItem();
	void setPlayerX(int playerX);
	void setPlayerY(int playerY);
	void setLocked();
	void resetLocked();
	void setNumWaterBalloon();
	void setCharacterSpeed();
	void setItem();
	void resetItem();
};

// player1
class Player1: public Character
{
private:

public:
	Player1(int a, int b);

	void movement(Map &map, char move);
};

// player2
class Player2: public Character
{
public:
	Player2(int a, int b);

	void movement(Map &map, char move);
};
