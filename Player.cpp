#include <iostream>
#include <string.h>

#include "Player.h"

using namespace std;

// Character
Character::Character()
{
	this->locked = false;
	this->needle = 0;
	this->numWaterBalloon = 1;
	this->walkspd = 1;
	this->win = Window();
}

void Character::draw()
{
	this->win.gotoxy(this->x, this->y);
	cout << this->image;
}

void Character::erase()
{
	this->win.gotoxy(this->x, this->y);
	cout << ' ';
}

void Character::move(Map* map, const char* dir)
{
	if (strcmp(dir, "up") == 0)
	{
		if (this->y >= this->walkspd)
		{
			this->y -= this->walkspd;
		}
	}
	else if (strcmp(dir, "down") == 0)
	{
		if (this->y < WINHEIGHT - this->walkspd)
		{
			this->y += this->walkspd;
		}
	}
	else if (strcmp(dir, "left") == 0)
	{
		if (this->x >= this->walkspd)
		{
			this->x -= this->walkspd;
		}
	}
	else if (strcmp(dir, "right") == 0)
	{
		if (this->x < WINWIDTH - this->walkspd)
		{
			this->x += this->walkspd;
		}
	}
	else
	{
		// do nothing
	}
}


// player1
Player1::Player1(int x, int y)
{
	this->x = x;
	this->y = y;
	this->image = 'P';
}

// player2
Player2::Player2(int x, int y)
{
	this->x = x;
	this->y = y;
	this->image = 'S';
}
