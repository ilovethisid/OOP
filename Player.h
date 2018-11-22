#pragma once

#include "WaterBalloon.h"
#include "Map.h"

#define MaxSpeed 3

// ĳ����
class Character: public WaterBalloon
{
protected:
	int x, y;                // ĳ������ ��ǥ
	bool locked = false;     // ��ǳ���� �������� ����
	int numWaterBalloon = 1; // ĳ���Ͱ� ������ �ִ� ��ǳ�� ����
	int characterSpeed = 1;  // ĳ������ �̵��ӵ�
	int item = 0;            // ������ (0 : ������ ����, 1 : �ٴ�)
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
