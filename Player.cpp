#include "Player.h"

#define UP 72
#define LEFT 75
#define RIGHT 77
#define DOWN 80

int Character::getPlayerX()
{
	return x;
}

int Character::getPlayerY()
{
	return y;
}
bool Character::getLocked()
{
	return locked;
}
int Character::getNumWaterBalloon()
{
	return numWaterBalloon;
}
int Character::getCharacterSpeed()
{
	return characterSpeed;
}
int Character::getItem()
{
	return item;
}
void Character::setPlayerX(int playerX)
{
	x = playerX;
}
void Character::setPlayerY(int playerY)
{
	y = playerY;
}
void Character::setLocked()
{
	locked = true;
}
void Character::resetLocked()
{
	locked = false;
}
void Character::setNumWaterBalloon()
{
	numWaterBalloon += 1;
}
void Character::setCharacterSpeed()
{
	if (characterSpeed < MaxSpeed)
		characterSpeed += 1;
}
void Character::setItem()
{
	item = 1;
}
void Character::resetItem()
{
	item = 0;
}

// player1

Player1::Player1(int a, int b)
{
	x = a;
	y = b;
}

void Player1::movement(Map &map, char move)
{
	switch (move)
	{
	case 'w':
		if (map.getFeature(x, y - 1) == 0)
			y -= 1;
		break;
	case 'a':
		if (map.getFeature(x - 1, y) == 0)
			x -= 1;
		break;
	case 's':
		if (map.getFeature(x, y + 1) == 0)
			y += 1;
		break;
	case 'd':
		if (map.getFeature(x + 1, y) == 0)
			x += 1;
		break;
	default:
		break;
	}
}

// player2
Player2::Player2(int a, int b)
{
	x = a;
	y = b;
}
	
void Player2::movement(Map &map, char move)
{
	switch (move)
	{
	case UP:
		if (map.getFeature(x, y - 1) == 0)
			y -= 1;
		break;
	case LEFT:
		if (map.getFeature(x - 1, y) == 0)
			x -= 1;
		break;
	case DOWN:
		if (map.getFeature(x, y + 1) == 0)
			y += 1;
		break;
	case RIGHT:
		if (map.getFeature(x + 1, y) == 0)
			x += 1;
		break;
	default:
		break;
	}
}
