
#include <iostream>

#include "Map.h"
#include "Player.h"

using namespace std;

class Game
{
public:
	void playGameMap1(Map1 &map)
	{
		map.initMap();                                 // map1 �ʱ�ȭ
		Player1 p1(1, 1);                              // player1 ó�� ��ġ �����
		Player2 p2(MAPHEIGHT - 2, MAPWIDTH - 2); // player2 ó�� ��ġ �����

													   // player1, player2 �����Ӱ� ��ǳ�� ���� �� �پ��� ����
													   // ...
	}
};

int main()
{

}