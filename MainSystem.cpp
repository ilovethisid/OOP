
#include <iostream>

#include "Map.h"
#include "Player.h"

using namespace std;

class Game
{
public:
	void playGameMap1(Map1 &map)
	{
		map.initMap();                                 // map1 초기화
		Player1 p1(1, 1);                              // player1 처음 위치 세우기
		Player2 p2(MAPHEIGHT - 2, MAPWIDTH - 2); // player2 처음 위치 세우기

													   // player1, player2 움직임과 물풍선 놓는 등 다양한 행위
													   // ...
	}
};

int main()
{

}