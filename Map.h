#pragma once

#include <ctime>
#include <stdlib.h>

#define MAPWIDTH 15
#define MAPHEIGHT 13

// 맵
class Map
{
	struct waterBalloonType
	{
		int player; // 누구의 물풍선인지 (1 : player1, 2 : player2)
		int wtrBln; // 물풍선 유무 (0 : 물풍선 있음, 1 : 물풍선 없음)
	};
	struct elements
	{
		int character;                         // 캐릭터 (0 : player 존재 X, 1 : player1 , 2 : player2)
		struct waterBalloonType waterBalloon;
		int feature;                          // 지형지물 (0 : 아무것도 없는 땅, 1 : 깨질 수 있는 블럭, 2 : 깨질 수 없는 블럭)
		int popRange;                         // 물풍선 폭발 범위 (0 : 물풍선이 터지는 범위 X, 1 : 물풍선이 터지는 범위 O)
		int item;                             // 아이템 (1 : 물풍선(물풍선 갯수 +1 증가), 2 : 물약(물풍선의 물줄기 길이 +1 증가), 3 : 롤러스케이트(캐릭터의 이동속도 증가), 4 : 바늘(물풍선에 갇혔을 때 사용하면 탈출))
	};
	struct elements gameMap[MAPHEIGHT][MAPWIDTH];
public:
	void initMap()
	{
		for (int i = 0; i < MAPHEIGHT; i++)
		{
			for (int j = 0; j < MAPWIDTH; j++)
			{
				gameMap[i][j].character = 0;
				gameMap[i][j].waterBalloon.player = 0;
				gameMap[i][j].waterBalloon.wtrBln = 0;
				gameMap[i][j].popRange = 0;
			}
		}
	}
	int getCharacter(int x, int y)
	{
		return gameMap[x][y].character;
	}
	int getWhoseWaterBalloon(int x, int y)
	{
		return gameMap[x][y].waterBalloon.player;
	}
	int getWaterBalloon(int x, int y)
	{
		return gameMap[x][y].waterBalloon.wtrBln;
	}
	int getFeature(int x, int y)
	{
		return gameMap[x][y].feature;
	}
	int getPopRange(int x, int y)
	{
		return gameMap[x][y].popRange;
	}
	int getItem(int x, int y)
	{
		return gameMap[x][y].item;
	}
	void setCharacter1(int x, int y)
	{
		gameMap[x][y].character = 1;
	}
	void setCharacter2(int x, int y)
	{
		gameMap[x][y].character = 2;
	}
	void setPlayer1WaterBalloon(int x, int y) // 물풍선의 주인 변수에 player1 입력
	{
		gameMap[x][y].waterBalloon.player = 1;
	}
	void setPlayer2WaterBalloon(int x, int y) // 물풍선의 주인 변수에 player2 입력
	{
		gameMap[x][y].waterBalloon.player = 2;
	}
	void setWaterBalloon(int x, int y)
	{
		gameMap[x][y].waterBalloon.wtrBln = 1;
	}
	void setFeature0(int x, int y)
	{
		gameMap[x][y].feature = 0;
	}
	void setFeature1(int x, int y)
	{
		gameMap[x][y].feature = 1;
	}
	void setFeature2(int x, int y)
	{
		gameMap[x][y].feature = 2;
	}
	void setPopRange(int x, int y)
	{
		gameMap[x][y].popRange = 1;
	}
	void resetPopRange(int x, int y)
	{
		gameMap[x][y].popRange = 0;
	}
	void setItem(int x, int y)
	{
		srand((unsigned int)time(NULL));
		gameMap[x][y].item = rand() % 4 + 1;
	}
};

class Map1 : public Map
{
public:
	void map1Setting();
};