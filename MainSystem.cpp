
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <WinUser.h>

#include "Window.h"
#include "Map.h"
#include "Player.h"

#define FPS 30 // Frames Per Second

using namespace std;

void gamestart(Player1*, Player2*, Map*);
void getKey(Player1*, Player2*, Map*);

int main()
{
	Window win = Window("temp title");
	Map map1 = Map(win);
	Player1 player1 = Player1(3, 3);
	Player2 player2 = Player2(12, 12);

	gamestart(&player1, &player2, &map1);
}

void gamestart(Player1* player1, Player2* player2, Map* map)
{
	bool gameover = false;

	player1->draw();
	player2->draw();

	clock_t timer;

	while(!gameover)
	{
		// frame
		
		getKey(player1, player2, map);

		timer = clock();
		while (clock() < timer + CLOCKS_PER_SEC/FPS)
		{
			// wait for 1 frame time
		}
	}
}

void getKey(Player1* player1, Player2* player2, Map* map)
{
	// player1 movement
	if (GetKeyState('D') < 0)
	{
		player1->erase();
		player1->move(map, "right");
		player1->draw();
	}
	else if (GetKeyState('W') < 0)
	{
		player1->erase();
		player1->move(map, "up");
		player1->draw();
	}
	else if (GetKeyState('A') < 0)
	{
		player1->erase();
		player1->move(map, "left");
		player1->draw();
	}
	else if (GetKeyState('S') < 0)
	{
		player1->erase();
		player1->move(map, "down");
		player1->draw();
	}

	// player2 movement
	if (GetKeyState(VK_RIGHT) < 0)
	{
		player2->erase();
		player2->move(map, "right");
		player2->draw();
	}
	else if (GetKeyState(VK_UP) < 0)
	{
		player2->erase();
		player2->move(map, "up");
		player2->draw();
	}
	else if (GetKeyState(VK_LEFT) < 0)
	{
		player2->erase();
		player2->move(map, "left");
		player2->draw();
	}
	else if (GetKeyState(VK_DOWN) < 0)
	{
		player2->erase();
		player2->move(map, "down");
		player2->draw();
	}
}