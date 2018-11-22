#pragma once

#include "Map.h"

class Character
{
protected:
	int walkspd;
	char image; // �÷��̾��� �̹���(����� char��)
	Window win;

public:
	int x, y;
	bool locked; // ��ǳ���� �������� ����
	int numWaterBalloon;
	bool needle; // �ٴ��� ����

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
